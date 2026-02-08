--- include/Gaffer/Private/IECorePreview/TaskMutex.h.orig	2024-12-05 13:02:15 UTC
+++ include/Gaffer/Private/IECorePreview/TaskMutex.h
@@ -45,6 +45,7 @@
 
 #include "tbb/task_arena.h"
 #include "tbb/task_group.h"
+#include "oneapi/tbb/detail/_utils.h"
 
 #include <iostream>
 #include <optional>
@@ -141,7 +142,7 @@ class TaskMutex : boost::noncopyable
 				/// work on behalf of `execute()` while waiting.
 				void acquire( TaskMutex &mutex, bool write = true, bool acceptWork = true )
 				{
-					tbb::internal::atomic_backoff backoff;
+					tbb::detail::d0::atomic_backoff backoff;
 					while( !acquireOr( mutex, write, [acceptWork]( bool workAvailable ){ return acceptWork; } ) )
 					{
 						backoff.pause();
@@ -188,12 +189,6 @@ class TaskMutex : boost::noncopyable
 					std::optional<tbb::task_group_status> status;
 					m_mutex->m_executionState->arena.execute(
 						[this, &fWrapper, &status] {
-							// Prior to TBB 2018 Update 3, `run_and_wait()` is buggy,
-							// causing calls to `wait()` on other threads to return
-							// immediately rather than do the work we want. Use
-							// `static_assert()` to ensure we never build with a buggy
-							// version.
-							static_assert( TBB_INTERFACE_VERSION >= 10003, "Minumum of TBB 2018 Update 3 required" );
 							status = m_mutex->m_executionState->taskGroup.run_and_wait( fWrapper );
 						}
 					);

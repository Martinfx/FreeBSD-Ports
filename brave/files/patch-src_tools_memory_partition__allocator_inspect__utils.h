--- src/tools/memory/partition_allocator/inspect_utils.h.orig	2026-11-24 12:50:30 UTC
+++ src/tools/memory/partition_allocator/inspect_utils.h
@@ -55,7 +55,7 @@ class RemoteProcessMemoryReader {
   const pid_t pid_;
   bool is_valid_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedFD mem_fd_;
 #elif BUILDFLAG(IS_MAC)
   task_t task_;

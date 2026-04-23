--- src/GafferTestModule/TaskMutexTest.cpp.orig	2025-03-02 14:08:13 UTC
+++ src/GafferTestModule/TaskMutexTest.cpp
@@ -120,8 +120,8 @@ void testTaskMutex()
 	// but everyone should have got the lock, and everyone should
 	// have done some work.
 	GAFFERTEST_ASSERTEQUAL( didInitialisation.size(), 1 );
-	GAFFERTEST_ASSERTEQUAL( gotLock.size(), tbb::tbb_thread::hardware_concurrency() );
-	GAFFERTEST_ASSERTEQUAL( didInitialisationTasks.size(), tbb::tbb_thread::hardware_concurrency() );
+	GAFFERTEST_ASSERTEQUAL( gotLock.size(), std::thread::hardware_concurrency());
+	GAFFERTEST_ASSERTEQUAL( didInitialisationTasks.size(), std::thread::hardware_concurrency());
 
 }
 
@@ -202,7 +202,7 @@ void testTaskMutexJoiningOuterTasks()
 
 	using TaskMutexPtr = std::unique_ptr<TaskMutex>;
 	std::vector<TaskMutexPtr> independentTasks;
-	for( size_t i = 0; i < tbb::tbb_thread::hardware_concurrency() * 1000; ++i )
+	for( size_t i = 0; i < std::thread::hardware_concurrency() * 1000; ++i )
 	{
 		independentTasks.push_back( std::make_unique<TaskMutex>() );
 	}
@@ -227,8 +227,8 @@ void testTaskMutexJoiningOuterTasks()
 	// but everyone should have got the lock, and everyone should
 	// have done some work.
 	GAFFERTEST_ASSERTEQUAL( didInitialisation.size(), 1 );
-	GAFFERTEST_ASSERTEQUAL( gotLock.size(), tbb::tbb_thread::hardware_concurrency() );
-	GAFFERTEST_ASSERTEQUAL( didInitialisationTasks.size(), tbb::tbb_thread::hardware_concurrency() );
+	GAFFERTEST_ASSERTEQUAL( gotLock.size(), std::thread::hardware_concurrency());
+	GAFFERTEST_ASSERTEQUAL( didInitialisationTasks.size(), std::thread::hardware_concurrency());
 
 }
 

--- physx/source/foundation/src/unix/PsUnixThread.cpp.orig	2024-07-05 09:46:14 UTC
+++ physx/source/foundation/src/unix/PsUnixThread.cpp
@@ -36,15 +36,23 @@
 #include "PsThread.h"
 
 #include <math.h>
-#if !PX_APPLE_FAMILY && !defined(ANDROID) && !defined(__CYGWIN__) && !PX_PS4 && !PX_EMSCRIPTEN
+#if !PX_APPLE_FAMILY && !defined(ANDROID) && !defined(__CYGWIN__) && !PX_PS4 && !PX_EMSCRIPTEN && !PX_FREEBSD
 #include <bits/local_lim.h> // PTHREAD_STACK_MIN
 #endif
+#if defined(PX_FREEBSD)
+#include <pthread.h>
+#include <unistd.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <pthread_np.h>
+#include <sched.h>
+#endif
 #include <stdio.h>
 #include <pthread.h>
 #include <unistd.h>
 #if !PX_PS4
 #include <sys/syscall.h>
-#if !PX_APPLE_FAMILY && !PX_EMSCRIPTEN
+#if !PX_APPLE_FAMILY && !PX_EMSCRIPTEN && !PX_FREEBSD
 #include <asm/unistd.h>
 #include <sys/resource.h>
 #endif
@@ -117,6 +125,8 @@ static void setTid(_ThreadImpl& threadImpl)
 	threadImpl.tid = syscall(SYS_gettid);
 #elif PX_EMSCRIPTEN
 	threadImpl.tid = pthread_self();
+#elif PX_FREEBSD
+	threadImpl.tid = pthread_getthreadid_np();
 #else
 	threadImpl.tid = syscall(__NR_gettid);
 #endif
@@ -313,7 +323,7 @@ uint32_t ThreadImpl::setAffinityMask(uint32_t mask)
 		prevMask = setAffinityMaskPS4(getThread(this)->thread, mask);
 #elif PX_EMSCRIPTEN
 		// not supported
-#elif !PX_APPLE_FAMILY // Apple doesn't support syscall with getaffinity and setaffinity
+#elif !PX_APPLE_FAMILY && !PX_FREEBSD // Apple doesn't support syscall with getaffinity and setaffinity
 		int32_t errGet = syscall(__NR_sched_getaffinity, getThread(this)->tid, sizeof(prevMask), &prevMask);
 		if(errGet < 0)
 			return 0;
@@ -321,6 +331,14 @@ uint32_t ThreadImpl::setAffinityMask(uint32_t mask)
 		int32_t errSet = syscall(__NR_sched_setaffinity, getThread(this)->tid, sizeof(mask), &mask);
 		if(errSet != 0)
 			return 0;
+#elif PX_FREEBSD
+                int32_t errGet = syscall(SYS_cpuset_getaffinity, getThread(this)->tid, sizeof(prevMask), &prevMask);
+                if(errGet < 0)
+                       return 0;
+
+                int32_t errSet = syscall(SYS_cpuset_setaffinity, getThread(this)->tid, sizeof(mask), &mask);
+                if (errSet != 0)
+                       return 0;
 #endif
 	}
 

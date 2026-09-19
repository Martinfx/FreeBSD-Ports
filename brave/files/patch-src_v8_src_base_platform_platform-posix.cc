--- src/v8/src/base/platform/platform-posix.cc.orig	2026-08-31 10:59:09 UTC
+++ src/v8/src/base/platform/platform-posix.cc
@@ -78,7 +78,7 @@
 #include <sys/syscall.h>
 #endif
 
-#if V8_OS_FREEBSD || V8_OS_DARWIN || V8_OS_OPENBSD || V8_OS_SOLARIS
+#if V8_OS_FREEBSD || V8_OS_DARWIN || V8_OS_BSD || V8_OS_SOLARIS
 #define MAP_ANONYMOUS MAP_ANON
 #endif
 
@@ -359,6 +359,13 @@
   }
 }
 
+#if V8_OS_OPENBSD
+// Allow OpenBSD's mmap to select a random address on OpenBSD 
+// static
+void* OS::GetRandomMmapAddr() {
+  return nullptr;
+}
+#else
 // static
 void* OS::GetRandomMmapAddr() {
   uintptr_t raw_addr;
@@ -457,6 +464,7 @@
 #endif
   return reinterpret_cast<void*>(raw_addr);
 }
+#endif
 
 // TODO(bbudge) Move Cygwin and Fuchsia stuff into platform-specific files.
 #if !V8_OS_CYGWIN && !V8_OS_FUCHSIA
@@ -772,7 +780,7 @@
 #if !V8_OS_ZOS
 // static
 bool OS::HasLazyCommits() {
-#if V8_OS_AIX || V8_OS_LINUX || V8_OS_DARWIN
+#if V8_OS_AIX || V8_OS_LINUX || V8_OS_DARWIN || V8_OS_BSD
   return true;
 #else
   // TODO(bbudge) Return true for all POSIX platforms.
@@ -1422,9 +1430,6 @@
 // pthread_getattr_np used below is non portable (hence the _np suffix). We
 // keep this version in POSIX as most Linux-compatible derivatives will
 // support it. MacOS and FreeBSD are different here.
-#if !defined(V8_OS_FREEBSD) && !defined(V8_OS_DARWIN) && !defined(_AIX) && \
-    !defined(V8_OS_SOLARIS)
-
 namespace {
 #if DEBUG
 bool MainThreadIsCurrentThread() {
@@ -1440,6 +1445,9 @@
 #endif  // DEBUG
 }  // namespace
 
+#if !defined(V8_OS_FREEBSD) && !defined(V8_OS_DARWIN) && !defined(_AIX) && \
+    !defined(V8_OS_SOLARIS) && !defined(V8_OS_OPENBSD)
+
 // static
 Stack::StackSlot Stack::ObtainCurrentThreadStackStart() {
 #if V8_OS_ZOS
@@ -1486,21 +1494,20 @@
 #endif  // V8_OS_ZOS
 }
 
+#endif  // !defined(V8_OS_FREEBSD) && !defined(V8_OS_DARWIN) &&
+        // !defined(_AIX) && !defined(V8_OS_SOLARIS)
+
 // static
 Stack::StackSlot Stack::ObtainCurrentThreadStackReservedLimit() {
 #if V8_OS_ZOS
   return nullptr;
-#elif V8_OS_OPENBSD
-  stack_t stack;
-  int error = pthread_stackseg_np(pthread_self(), &stack);
-  if (error) {
-    DCHECK(MainThreadIsCurrentThread());
-    return nullptr;
-  }
-  return stack.ss_sp;
 #else
   pthread_attr_t attr;
+#if V8_OS_BSD
+  int error = pthread_attr_init(&attr);
+#else
   int error = pthread_getattr_np(pthread_self(), &attr);
+#endif
   if (error) {
     DCHECK(MainThreadIsCurrentThread());
     return nullptr;
@@ -1514,10 +1521,6 @@
 #endif  // V8_OS_ZOS
 }
 
-#endif  // !defined(V8_OS_FREEBSD) && !defined(V8_OS_DARWIN) &&
-        // !defined(_AIX) && !defined(V8_OS_SOLARIS)
-
-
 
 // static
 void Stack::SetCurrentThreadStackBounds(uintptr_t, uintptr_t) { UNREACHABLE(); }

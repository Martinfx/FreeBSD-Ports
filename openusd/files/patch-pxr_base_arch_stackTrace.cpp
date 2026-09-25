--- pxr/base/arch/stackTrace.cpp.orig	2026-04-24 18:55:54 UTC
+++ pxr/base/arch/stackTrace.cpp
@@ -62,7 +62,8 @@
 #include <ucontext.h>
 #endif
 
-#if defined(ARCH_OS_LINUX) && defined(ARCH_BITS_64)
+#if (defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)) && \
+    defined(ARCH_BITS_64)
 #include <unwind.h>
 #endif
 
@@ -93,7 +94,7 @@ using namespace std;
 // total hack -- no idea if this will work if we die in malloc...
 typedef int (*ForkFunc)(void);
 ForkFunc Arch_nonLockingFork =
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
     (ForkFunc)dlsym(RTLD_DEFAULT, "_Fork");
 #elif defined(ARCH_OS_DARWIN) || defined(ARCH_OS_WASM_VM)
     NULL;
@@ -1404,7 +1405,8 @@ ArchGetStackFrames(size_t maxDepth, size
     frames->resize(ArchGetStackFrames(maxDepth, skip, frames->data()));
 }
 
-#if defined(ARCH_OS_LINUX) && defined(ARCH_BITS_64)
+#if (defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)) && \
+    defined(ARCH_BITS_64)
 struct Arch_UnwindContext {
 public:
     Arch_UnwindContext(size_t maxdepth, size_t skip, uintptr_t* frames) :

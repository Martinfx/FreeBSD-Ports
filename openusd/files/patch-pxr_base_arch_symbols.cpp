--- pxr/base/arch/symbols.cpp.orig	2026-04-24 18:55:54 UTC
+++ pxr/base/arch/symbols.cpp
@@ -12,7 +12,7 @@
 
 #if defined(ARCH_OS_LINUX) || defined(ARCH_OS_WASM_VM)
 #include <dlfcn.h>
-#elif defined(ARCH_OS_DARWIN)
+#elif defined(ARCH_OS_DARWIN) || defined(ARCH_OS_FREEBSD)
 #include <dlfcn.h>
 #elif defined(ARCH_OS_WINDOWS)
 #include <Windows.h>
@@ -28,7 +28,11 @@ ArchGetAddressInfo(
     std::string* objectPath, void** baseAddress,
     std::string* symbolName, void** symbolAddress)
 {
-#if defined(_GNU_SOURCE) || defined(ARCH_OS_DARWIN)
+// dladdr() is also available on FreeBSD, where the compiler does not
+// define _GNU_SOURCE.  Without it the Plug library cannot find its own
+// location and thus the plugins installed next to it.
+#if defined(_GNU_SOURCE) || defined(ARCH_OS_DARWIN) || \
+    defined(ARCH_OS_FREEBSD)
 
     Dl_info info;
     if (dladdr(address, &info)) {

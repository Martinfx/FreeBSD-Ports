--- pxr/base/tf/diagnostic.cpp.orig	2026-02-23 22:54:59 UTC
+++ pxr/base/tf/diagnostic.cpp
@@ -20,6 +20,7 @@
 #include <cstdio>
 #include <stdexcept>
 #include <csignal>
+#include <unistd.h>
 
 #if defined(ARCH_OS_WASM_VM)
 #include <emscripten.h>

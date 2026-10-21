--- src/plugins/intel_gpu/thirdparty/onednn_gpu/src/xpu/utils.cpp.orig	2026-10-17 14:10:00 UTC
+++ src/plugins/intel_gpu/thirdparty/onednn_gpu/src/xpu/utils.cpp
@@ -21,7 +21,7 @@
 #define NOMINMAX
 #endif
 #include "windows.h"
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #include <dlfcn.h>
 #endif
 
@@ -74,7 +74,7 @@
         return nullptr;
     }
     return symbol_address;
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
     // To clean the error string
     dlerror();
     void *handle = dlopen(library_name, RTLD_NOW | RTLD_LOCAL);

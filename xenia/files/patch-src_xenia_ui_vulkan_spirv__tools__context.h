--- src/xenia/ui/vulkan/spirv_tools_context.h.orig	2025-03-06 14:28:35 UTC
+++ src/xenia/ui/vulkan/spirv_tools_context.h
@@ -16,7 +16,7 @@
 #include "third_party/SPIRV-Tools/include/spirv-tools/libspirv.h"
 #include "xenia/base/platform.h"
 
-#if XE_PLATFORM_LINUX
+#if XE_PLATFORM_LINUX || XE_PLATFORM_FREEBSD
 #include <dlfcn.h>
 #elif XE_PLATFORM_WIN32
 #include "xenia/base/platform_win.h"
@@ -39,7 +39,7 @@ class SpirvToolsContext {
                         std::string* error) const;
 
  private:
-#if XE_PLATFORM_LINUX
+#if XE_PLATFORM_LINUX || XE_PLATFORM_FREEBSD
   void* library_ = nullptr;
 #elif XE_PLATFORM_WIN32
   HMODULE library_ = nullptr;
@@ -47,7 +47,7 @@ class SpirvToolsContext {
 
   template <typename FunctionPointer>
   bool LoadLibraryFunction(FunctionPointer& function, const char* name) {
-#if XE_PLATFORM_LINUX
+#if XE_PLATFORM_LINUX || XE_PLATFORM_FREEBSD
     function = reinterpret_cast<FunctionPointer>(dlsym(library_, name));
 #elif XE_PLATFORM_WIN32
     function =

--- pxr/imaging/plugin/hdPrmanLoader/rendererPlugin.cpp.orig	2025-02-04 21:22:17 UTC
+++ pxr/imaging/plugin/hdPrmanLoader/rendererPlugin.cpp
@@ -31,7 +31,7 @@ static struct HdPrmanLoader
 {
     static void Load();
     ~HdPrmanLoader();
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN) || defined(ARCH_OS_FREEBSD)
     void* libprman = nullptr;
 #endif
     void* hdPrman = nullptr;
@@ -56,7 +56,7 @@ HdPrmanLoader::Load()
         return;
     }
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN) || defined(ARCH_OS_FREEBSD)
     // Open $RMANTREE/lib/libprman.so into the global namespace
     const std::string libprmanPath =
         TfStringCatPaths(rmantree, "lib/libprman" ARCH_LIBRARY_SUFFIX);
@@ -121,7 +121,7 @@ HdPrmanLoader::~HdPrmanLoader()
         ArchLibraryClose(hdPrman);
         hdPrman = nullptr;
     }
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN) || defined(ARCH_OS_FREEBSD)
     if (libprman) {
         ArchLibraryClose(libprman);
         libprman = nullptr;

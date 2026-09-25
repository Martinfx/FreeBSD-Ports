--- pxr/imaging/garch/glApi.cpp.orig	2026-04-24 18:55:54 UTC
+++ pxr/imaging/garch/glApi.cpp
@@ -3137,7 +3137,7 @@ static bool loadLibrary()
     libGetProcAddress = (PFNGETPROCADDRESS) ArchLibraryGetSymbolAddress(libHandle, "wglGetProcAddress");
 #elif defined(ARCH_OS_DARWIN)
     libHandle = ArchLibraryOpen("/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL", RTLD_LAZY | RTLD_LOCAL);
-#elif defined(ARCH_OS_LINUX)
+#elif defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
     libHandle = ArchLibraryOpen("libGL.so.1", RTLD_LAZY | RTLD_LOCAL);
     libGetProcAddress = (PFNGETPROCADDRESS) ArchLibraryGetSymbolAddress(libHandle, "glXGetProcAddressARB");
 #else

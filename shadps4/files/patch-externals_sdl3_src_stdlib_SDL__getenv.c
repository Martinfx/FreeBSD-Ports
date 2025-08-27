--- externals/sdl3/src/stdlib/SDL_getenv.c.orig	2025-08-27 16:08:37 UTC
+++ externals/sdl3/src/stdlib/SDL_getenv.c
@@ -41,7 +41,12 @@
 #define environ (*_NSGetEnviron())
 #elif defined(SDL_PLATFORM_FREEBSD)
 #include <dlfcn.h>
-#define environ ((char **)dlsym(RTLD_DEFAULT, "environ"))
+static char **get_environ_rtld(void)
+{
+    char ***environ_rtld = (char ***)dlsym(RTLD_DEFAULT, "environ");
+    return environ_rtld ? *environ_rtld : NULL;
+}
+#define environ (get_environ_rtld())
 #else
 extern char **environ;
 #endif

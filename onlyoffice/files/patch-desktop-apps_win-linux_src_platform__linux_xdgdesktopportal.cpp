--- desktop-apps/win-linux/src/platform_linux/xdgdesktopportal.cpp.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/src/platform_linux/xdgdesktopportal.cpp
@@ -12,7 +12,11 @@
 #include <unistd.h>
 #include <dbus/dbus.h>
 #include <sys/syscall.h>
+#ifdef __FreeBSD__
+#include <sys/random.h>
+#else
 #include <linux/random.h>
+#endif
 #include <X11/Xlib.h>
 
 #if defined(__x86_64__)
@@ -35,7 +39,9 @@
 # define GETRANDOM_NR 349
 #endif
 
-#if defined(SYS_getrandom)
+#if defined(__FreeBSD__)
+// getrandom(2) is used directly
+#elif defined(SYS_getrandom)
 # if defined(GETRANDOM_NR)
 static_assert(GETRANDOM_NR == SYS_getrandom, "GETRANDOM_NR should match the actual SYS_getrandom value");
 # endif
@@ -634,8 +640,12 @@ char* generateChars(char* out) {
     size_t count = 32;
     while (count > 0) {
         unsigned char buff[32];
+#ifdef __FreeBSD__
+        ssize_t rnd = getrandom(buff, count, 0);
+#else
         //ssize_t rnd = getrandom(buff, count, 0);
         ssize_t rnd = syscall(SYS_getrandom, buff, count, 0);
+#endif
         if (rnd == -1) {
             if (errno == EINTR)
                 continue;

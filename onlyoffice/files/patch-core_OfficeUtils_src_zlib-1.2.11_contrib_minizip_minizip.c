--- core/OfficeUtils/src/zlib-1.2.11/contrib/minizip/minizip.c.orig	2026-11-05 00:00:00 UTC
+++ core/OfficeUtils/src/zlib-1.2.11/contrib/minizip/minizip.c
@@ -94,7 +94,7 @@
   return ret;
 }
 #else
-#if defined(unix) || defined(_LINUX) || defined(__APPLE__)
+#if defined(unix) || defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
 uLong filetime(f, tmzip, dt)
     char *f;               /* name of file to get info on */
     tm_zip *tmzip;         /* return value: access, modific. and creation times */

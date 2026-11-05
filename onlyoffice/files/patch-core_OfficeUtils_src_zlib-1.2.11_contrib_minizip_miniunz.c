--- core/OfficeUtils/src/zlib-1.2.11/contrib/minizip/miniunz.c.orig	2026-11-05 00:00:00 UTC
+++ core/OfficeUtils/src/zlib-1.2.11/contrib/minizip/miniunz.c
@@ -98,7 +98,7 @@
   SetFileTime(hFile,&ftm,&ftLastAcc,&ftm);
   CloseHandle(hFile);
 #else
-#if defined(unix) || defined(_LINUX) || defined(__APPLE__)
+#if defined(unix) || defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
   struct utimbuf ut;
   struct tm newdate;
   newdate.tm_sec = tmu_date.tm_sec;

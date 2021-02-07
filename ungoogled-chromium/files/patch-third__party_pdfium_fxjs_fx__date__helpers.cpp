--- third_party/pdfium/fxjs/fx_date_helpers.cpp.orig	2020-11-13 06:42:21 UTC
+++ third_party/pdfium/fxjs/fx_date_helpers.cpp
@@ -36,6 +36,11 @@ double GetLocalTZA() {
     return 0;
   time_t t = 0;
   FXSYS_time(&t);
+#ifdef __FreeBSD__
+  struct tm lt;
+  localtime_r(&t, &lt);
+  return (double)(-(lt.tm_gmtoff * 1000));
+#else
   FXSYS_localtime(&t);
 #if defined(OS_WIN)
   // In gcc 'timezone' is a global variable declared in time.h. In VC++, that
@@ -44,6 +49,7 @@ double GetLocalTZA() {
   _get_timezone(&timezone);
 #endif
   return (double)(-(timezone * 1000));
+#endif // __FreeBSD__
 }
 
 int GetDaylightSavingTA(double d) {

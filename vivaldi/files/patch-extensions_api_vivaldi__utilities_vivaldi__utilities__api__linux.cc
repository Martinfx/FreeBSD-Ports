--- extensions/api/vivaldi_utilities/vivaldi_utilities_api_linux.cc.orig	2026-08-25 00:00:00 UTC
+++ extensions/api/vivaldi_utilities/vivaldi_utilities_api_linux.cc
@@ -17,6 +17,12 @@
 
 #include "launch_bar_gnome_support.h"
 
+#if !defined(__GLIBC__)
+#include <memory>
+
+#include "third_party/icu/source/i18n/unicode/calendar.h"
+#endif
+
 namespace extensions {
 void reduce_spaces(std::string& s) {
   // strip leading spaces.
@@ -103,10 +109,26 @@ std::string getMomentJsFormatString(cons
 }
 
 static int first_weekday(void) {
+#if defined(__GLIBC__)
   const char* const s = nl_langinfo(_NL_TIME_FIRST_WEEKDAY);
 
   if (s && *s >= 1 && *s <= 7)
     return (int)*s;
+#else
+  // _NL_TIME_FIRST_WEEKDAY is a glibc extension.  Ask ICU about the locale
+  // of LC_TIME instead; its days are numbered like glibc's, Sunday being 1.
+  const char* const name = setlocale(LC_TIME, nullptr);
+  if (name && *name) {
+    UErrorCode status = U_ZERO_ERROR;
+    std::unique_ptr<icu::Calendar> calendar(icu::Calendar::createInstance(
+        icu::Locale::createCanonical(name), status));
+    if (U_SUCCESS(status)) {
+      const int day = calendar->getFirstDayOfWeek(status);
+      if (U_SUCCESS(status) && day >= 1 && day <= 7)
+        return day;
+    }
+  }
+#endif
 
   /* Default to Sunday, 1. */
   return 1;

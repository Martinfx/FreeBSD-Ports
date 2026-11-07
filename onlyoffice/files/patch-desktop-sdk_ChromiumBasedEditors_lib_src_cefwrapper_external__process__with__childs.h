--- desktop-sdk/ChromiumBasedEditors/lib/src/cefwrapper/external_process_with_childs.h.orig	2026-11-07 00:00:00 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/cefwrapper/external_process_with_childs.h
@@ -34,6 +34,7 @@
  */
 
 #pragma once
+#include <array>
 #include <functional>
 #include <map>
 #include <stdexcept>
@@ -55,7 +56,7 @@
 #include <iomanip>
 #endif
 
-#ifdef _MAC
+#if defined(_MAC) || defined(__FreeBSD__)
 #ifdef __APPLE__
 #include <crt_externs.h>
 #define environ (*_NSGetEnviron())

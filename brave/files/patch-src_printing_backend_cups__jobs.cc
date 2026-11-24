--- src/printing/backend/cups_jobs.cc.orig	2026-11-24 12:50:30 UTC
+++ src/printing/backend/cups_jobs.cc
@@ -26,7 +26,7 @@
 #include "printing/backend/cups_ipp_helper.h"
 #include "printing/printer_status.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/backend/cups_weak_functions.h"
 #endif
 

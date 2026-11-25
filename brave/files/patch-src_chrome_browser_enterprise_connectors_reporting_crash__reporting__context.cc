--- src/chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc
@@ -30,7 +30,7 @@
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 namespace {
 

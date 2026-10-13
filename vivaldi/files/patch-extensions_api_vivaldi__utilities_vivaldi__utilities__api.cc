--- extensions/api/vivaldi_utilities/vivaldi_utilities_api.cc.orig	2026-08-25 00:00:00 UTC
+++ extensions/api/vivaldi_utilities/vivaldi_utilities_api.cc
@@ -2957,7 +2957,10 @@ ExtensionFunction::ResponseAction Utilit
 
 std::string UtilitiesDetectNewCrashesFunction::CheckForNewCrashes() {
   std::vector<crash_reporter::Report> reports;
+#if !BUILDFLAG(IS_BSD)
+  // There is no crashpad on the BSDs, so there are no crash reports either.
   crash_reporter::GetReports(&reports);
+#endif
   if (reports.empty()) {
     return "";
   }

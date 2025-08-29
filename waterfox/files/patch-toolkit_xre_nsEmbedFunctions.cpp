--- toolkit/xre/nsEmbedFunctions.cpp.orig	2025-08-28 19:08:14 UTC
+++ toolkit/xre/nsEmbedFunctions.cpp
@@ -348,6 +348,7 @@ nsresult XRE_InitChildProcess(int aArgc, char* aArgv[]
 
   SetupErrorHandling(aArgv[0]);
 
+#if !defined(XP_FREEBSD)
   bool exceptionHandlerIsSet = false;
   if (!CrashReporter::IsDummy()) {
     auto crashReporterArg = geckoargs::sCrashReporter.Get(aArgc, aArgv);
@@ -357,7 +358,7 @@ nsresult XRE_InitChildProcess(int aArgc, char* aArgv[]
           std::move(*crashReporterArg), std::move(*crashHelperArg));
       MOZ_ASSERT(exceptionHandlerIsSet,
                  "Should have been able to set remote exception handler");
-
+#endif
       if (!exceptionHandlerIsSet) {
         // Bug 684322 will add better visibility into this condition
         NS_WARNING("Could not setup crash reporting\n");

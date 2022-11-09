--- browser/app/nsBrowserApp.cpp.orig	2022-11-04 13:52:09 UTC
+++ browser/app/nsBrowserApp.cpp
@@ -372,6 +372,9 @@ int main(int argc, char* argv[], char* envp[]) {
   // Register an external module to report on otherwise uncatchable exceptions.
   CrashReporter::RegisterRuntimeExceptionModule();
 
+  setenv("MOZ_GMP_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+
 #ifdef HAS_DLL_BLOCKLIST
   DllBlocklist_Initialize(gBlocklistInitFlags);
 #endif

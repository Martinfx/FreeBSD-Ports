--- chromium/components/policy/core/common/policy_paths.cc.orig	2024-01-30 07:53:34 UTC
+++ chromium/components/policy/core/common/policy_paths.cc
@@ -17,6 +17,8 @@ namespace policy {
 const char kPolicyPath[] = "/etc/opt/chrome/policies";
 #elif BUILDFLAG(GOOGLE_CHROME_FOR_TESTING_BRANDING)
 const char kPolicyPath[] = "/etc/opt/chrome_for_testing/policies";
+#elif defined(VIVALDI_BUILD) && BUILDFLAG(IS_FREEBSD)
+const char kPolicyPath[] = "/usr/local/etc/vivaldi/policies";
 #elif defined(VIVALDI_BUILD)
 const char kPolicyPath[] = "/etc/vivaldi/policies";
 #else

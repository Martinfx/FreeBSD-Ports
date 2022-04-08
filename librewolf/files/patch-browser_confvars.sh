--- browser/confvars.sh.orig	2022-04-08 14:49:46 UTC
+++ browser/confvars.sh
@@ -41,3 +41,9 @@ MOZ_PROFILE_MIGRATOR=1
 
 # Include the DevTools client, not just the server (which is the default)
 MOZ_DEVTOOLS=all
+
+# Reduce data sharing with Mozilla
+MOZ_DATA_REPORTING=0
+MOZ_TELEMETRY_REPORTING=0
+MOZ_CRASHREPORTER=0
+MOZ_SERVICES_HEALTHREPORT=0

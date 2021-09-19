--- browser/confvars.sh.orig	2021-09-19 20:07:05 UTC
+++ browser/confvars.sh
@@ -3,8 +3,9 @@
 # License, v. 2.0. If a copy of the MPL was not distributed with this
 # file, You can obtain one at http://mozilla.org/MPL/2.0/.
 
-MOZ_APP_VENDOR=Mozilla
-MOZ_UPDATER=1
+MOZ_APP_VENDOR=Librewolf
+MOZ_APP_VENDOR=="LibreWolf Community"
+MOZ_UPDATER=0
 
 if test "$OS_ARCH" = "WINNT"; then
   if ! test "$HAVE_64BIT_BUILD"; then
@@ -34,8 +35,8 @@ BROWSER_CHROME_URL=chrome://browser/content/browser.xh
 # For mozilla-beta, mozilla-release, or mozilla-central repositories, use
 # "unofficial" branding.
 # For the mozilla-aurora repository, use "aurora".
-MOZ_BRANDING_DIRECTORY=browser/branding/unofficial
-MOZ_OFFICIAL_BRANDING_DIRECTORY=browser/branding/official
+MOZ_BRANDING_DIRECTORY=browser/branding/librewolf
+MOZ_OFFICIAL_BRANDING_DIRECTORY=browser/branding/librewolf
 MOZ_APP_ID={ec8030f7-c20a-464f-9b0e-13a3a9e97384}
 
 MOZ_PROFILE_MIGRATOR=1

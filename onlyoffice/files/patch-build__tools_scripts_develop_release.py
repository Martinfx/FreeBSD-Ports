--- build_tools/scripts/develop/release.py.orig	2026-11-05 00:00:00 UTC
+++ build_tools/scripts/develop/release.py
@@ -42,7 +42,7 @@
 # Add other repositories
 repositories['core-ext'] = [True, False]
 
-base.update_repositories(repositories)
+#base.update_repositories(repositories)
 
 repositories['onlyoffice'] = [True, False]
 

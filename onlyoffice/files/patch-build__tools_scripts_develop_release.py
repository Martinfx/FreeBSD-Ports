--- build_tools/scripts/develop/release.py.orig	2025-09-23 22:50:09 UTC
+++ build_tools/scripts/develop/release.py
@@ -42,7 +42,7 @@ repositories['core-ext'] = [True, False]
 # Add other repositories
 repositories['core-ext'] = [True, False]
 
-base.update_repositories(repositories)
+#base.update_repositories(repositories)
 
 repositories['onlyoffice'] = [True, False]
 

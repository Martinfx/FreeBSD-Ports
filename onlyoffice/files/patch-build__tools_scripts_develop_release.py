--- build_tools/scripts/develop/release.py.orig	2026-09-24 21:58:50 UTC
+++ build_tools/scripts/develop/release.py
@@ -42,7 +42,7 @@ repositories = base.get_repositories()
 # Add other repositories
 repositories['core-ext'] = [True, False]
 
-base.update_repositories(repositories)
+#base.update_repositories(repositories)
 
 repositories['onlyoffice'] = [True, False]
 

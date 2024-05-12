--- build/variables.py.orig	2024-05-11 10:55:10 UTC
+++ build/variables.py
@@ -86,10 +86,10 @@ def source_repo_header(output):
             repo, changeset = get_info_from_sourcestamp(sourcestamp_path)
     elif not changeset:
         changeset = get_hg_changeset(buildconfig.topsrcdir)
-        if not changeset:
-            raise Exception(
-                "could not resolve changeset; " "try setting MOZ_SOURCE_CHANGESET"
-            )
+#        if not changeset:
+#            raise Exception(
+#                "could not resolve changeset; " "try setting MOZ_SOURCE_CHANGESET"
+#            )
 
     if changeset:
         output.write("#define MOZ_SOURCE_STAMP %s\n" % changeset)

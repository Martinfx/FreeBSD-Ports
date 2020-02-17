--- utils/patches.py.orig	2020-02-17 21:30:17 UTC
+++ utils/patches.py
@@ -41,7 +41,7 @@ def apply_patches(patch_path_iter, tree_path, reverse=
         cmd = [
             str(patch_bin_path), '-p1', '--ignore-whitespace', '-i',
             str(patch_path), '-d',
-            str(tree_path), '--no-backup-if-mismatch'
+            str(tree_path), '--posix'
         ]
         if reverse:
             cmd.append('--reverse')

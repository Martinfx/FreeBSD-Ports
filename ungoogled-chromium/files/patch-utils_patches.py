--- utils/patches.py.orig	2020-12-04 08:04:04 UTC
+++ utils/patches.py
@@ -90,7 +90,8 @@ def dry_run_check(patch_path, tree_path, patch_bin_pat
     cmd = [
         str(find_and_check_patch(patch_bin_path)), '-p1', '--ignore-whitespace', '-i',
         str(patch_path), '-d',
-        str(tree_path), '--no-backup-if-mismatch', '--dry-run'
+        #str(tree_path), '--no-backup-if-mismatch', '--dry-run'
+        str(tree_path), '--posix', '--dry-run'
     ]
     result = subprocess.run(
         cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True)
@@ -119,7 +120,8 @@ def apply_patches(patch_path_iter, tree_path, reverse=
         cmd = [
             str(patch_bin_path), '-p1', '--ignore-whitespace', '-i',
             str(patch_path), '-d',
-            str(tree_path), '--no-backup-if-mismatch'
+            #str(tree_path), '--no-backup-if-mismatch'
+            str(tree_path), '--posix'
         ]
         if reverse:
             cmd.append('--reverse')

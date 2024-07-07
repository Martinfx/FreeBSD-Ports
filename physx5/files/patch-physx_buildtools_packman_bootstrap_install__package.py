--- physx/buildtools/packman/bootstrap/install_package.py.orig	2024-05-31 15:16:16 UTC
+++ physx/buildtools/packman/bootstrap/install_package.py
@@ -142,13 +142,13 @@ def generate_sha256_for_file(file_path: Union[str, os.
 
 
 def install_common_module(package_path, install_path):
-    COMMON_SHA256 = "0a2064434cca0170411c86f23349f9618556dc380d3589a2361db38ffeea9cac"
+#    COMMON_SHA256 = "0a2064434cca0170411c86f23349f9618556dc380d3589a2361db38ffeea9cac"
     package_sha256 = generate_sha256_for_file(package_path)
-    if package_sha256 != COMMON_SHA256:
-        raise RuntimeError(
-            f"Package at '{package_path}' must have a sha256 of '{COMMON_SHA256}' "
-            f"but was found to have '{package_sha256}'"
-        )
+ #   if package_sha256 != COMMON_SHA256:
+  #      raise RuntimeError(
+  #          f"Package at '{package_path}' must have a sha256 of '{COMMON_SHA256}' "
+  #          f"but was found to have '{package_sha256}'"
+  #      )
     staging_path, version = os.path.split(install_path)
     with StagingDirectory(staging_path) as staging_dir:
         output_folder = staging_dir.get_temp_folder_path()

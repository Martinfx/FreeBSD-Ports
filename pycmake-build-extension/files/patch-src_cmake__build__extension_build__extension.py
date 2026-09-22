--- src/cmake_build_extension/build_extension.py.orig	2025-09-06 13:50:35 UTC
+++ src/cmake_build_extension/build_extension.py
@@ -177,7 +177,7 @@ class BuildExtension(build_ext):
 
             configure_args += []
 
-        elif platform.system() in {"Linux", "Darwin", "GNU"}:
+        elif platform.system() in {"Linux", "Darwin", "GNU", "FreeBSD"}:
 
             configure_args += []
 

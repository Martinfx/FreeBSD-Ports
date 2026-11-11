--- src/build/modules/unified/modulemap_config.py.orig	2026-11-02 23:22:33 UTC
+++ src/build/modules/unified/modulemap_config.py
@@ -62,7 +62,7 @@ class AllowedHeader(Header):
 
 
 def headers(os):
-    is_linux = os == 'linux'  # noqa: F841
+    is_linux = os == 'linux' or os == 'openbsd' or os == 'freebsd'  # noqa: F841
     is_android = os == 'android'
     is_ios = os == 'ios'  # noqa: F841
     is_mac = os == 'mac'  # noqa: F841

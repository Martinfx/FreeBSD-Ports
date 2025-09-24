--- build_tools/scripts/core_common/make_common.py.orig	2025-09-24 14:52:58 UTC
+++ build_tools/scripts/core_common/make_common.py
@@ -8,22 +8,22 @@ import glob
 import base
 import glob
 
-import boost
+#import boost
 import cef
-import icu
-import openssl
+#import icu
+#import openssl
 import curl
 import websocket_all
 import v8
 import html2
 import iwork
 import md
-import hunspell
+#import hunspell
 import glew
 import harfbuzz
 import oo_brotli
-import hyphen
-import googletest
+#import hyphen
+#import googletest
 import libvlc
 
 def check_android_ndk_macos_arm(dir):
@@ -39,19 +39,19 @@ def make():
       if base.is_dir(toolchain):
         check_android_ndk_macos_arm(toolchain + "/prebuilt")
 
-  boost.make()
+#  boost.make()
   cef.make()
-  icu.make()
-  openssl.make()
+#  icu.make()
+#  openssl.make()
   v8.make()
   html2.make()
   iwork.make(False)
   md.make()
-  hunspell.make(False)
-  harfbuzz.make()
+#  hunspell.make(False)
+#  harfbuzz.make()
   glew.make()
-  hyphen.make()
-  googletest.make()
+#  hyphen.make()
+#  googletest.make()
   oo_brotli.make()
 
   if config.check_option("build-libvlc", "1"):

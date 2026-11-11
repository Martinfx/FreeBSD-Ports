--- src/brave/script/lib/config.py.orig	2026-11-02 23:22:33 UTC
+++ src/brave/script/lib/config.py
@@ -3,13 +3,18 @@ import json
 import os
 import sys
 
-PLATFORM = {
-    'cygwin': 'win32',
-    'darwin': 'darwin',
-    'linux2': 'linux',
-    'linux': 'linux',
-    'win32': 'win32',
-}[sys.platform]
+# sys.platform carries the major version on FreeBSD ('freebsd14', ...), so it
+# cannot be looked up in the table below.
+if sys.platform.startswith('freebsd'):
+    PLATFORM = 'freebsd'
+else:
+    PLATFORM = {
+        'cygwin': 'win32',
+        'darwin': 'darwin',
+        'linux2': 'linux',
+        'linux': 'linux',
+        'win32': 'win32',
+    }[sys.platform]
 
 SOURCE_ROOT = os.path.abspath(
     os.path.join(os.path.dirname(__file__), '..', '..')

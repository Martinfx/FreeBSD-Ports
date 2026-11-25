--- src/third_party/devtools-frontend/src/third_party/typescript/typescript.py.orig	2026-11-24 12:50:30 UTC
+++ src/third_party/devtools-frontend/src/third_party/typescript/typescript.py
@@ -10,6 +10,9 @@ import os
 
 
 def GetBinaryPath():
+    if platform.system() in ['OpenBSD', 'FreeBSD']:
+        return "tsc"
+
     if platform.machine() == 'arm64':
         darwin_path = 'mac-arm64'
     else:

--- core/Common/3dParty/v8_89/v8/build/detect_host_arch.py.orig	2025-09-23 22:49:55 UTC
+++ core/Common/3dParty/v8_89/v8/build/detect_host_arch.py
@@ -21,6 +21,8 @@ def HostArch():
     host_arch = 'ia32'
   elif host_arch in ['x86_64', 'amd64']:
     host_arch = 'x64'
+  elif host_arch.startswith('arm64'):
+    host_arch = 'arm64'
   elif host_arch.startswith('arm'):
     host_arch = 'arm'
   elif host_arch.startswith('aarch64'):

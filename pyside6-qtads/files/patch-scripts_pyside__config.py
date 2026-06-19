--- scripts/pyside_config.py.orig	2025-09-06 12:02:16 UTC
+++ scripts/pyside_config.py
@@ -155,6 +155,8 @@ def link_option(lib):
     link = ' -l'
     if sys.platform in ['linux', 'linux2']: # Linux: 'libfoo.so' -> '/absolute/path/libfoo.so'
         link = lib
+    elif sys.platform in ['freebsd', 'freebsd14']:
+        link = lib
     elif sys.platform in ['darwin']: # Darwin: 'libfoo.so' -> '-lfoo'
         link += os.path.splitext(baseName[3:])[0]
     else: # Windows: 'libfoo.dll' -> 'libfoo.dll'
@@ -186,6 +188,7 @@ def find_package_path(dir_name):
 
 
 def find_package_path(dir_name):
+    print(dir_name)
     for p in sys.path:
         if 'site-' in p:
             package = os.path.join(p, dir_name)

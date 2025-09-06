--- scripts/pyside_config.py.orig	2025-09-02 06:36:29 UTC
+++ scripts/pyside_config.py
@@ -155,6 +155,8 @@ def link_option(lib):
     link = ' -l'
     if sys.platform in ['linux', 'linux2']: # Linux: 'libfoo.so' -> '/absolute/path/libfoo.so'
         link = lib
+    elif sys.platform in ['freebsd','freebsd14']: 
+        link = lib
     elif sys.platform in ['darwin']: # Darwin: 'libfoo.so' -> '-lfoo'
         link += os.path.splitext(baseName[3:])[0]
     else: # Windows: 'libfoo.dll' -> 'libfoo.dll'

--- pxr/base/tf/__init__.py.orig	2026-04-24 18:55:54 UTC
+++ pxr/base/tf/__init__.py
@@ -58,6 +58,27 @@ else:
             pass
         def __exit__(self, exc_type, ex_val, exc_tb):
             pass
+
+# On FreeBSD, libc++ compares std::type_info objects by address.  Python loads
+# extension modules with RTLD_LOCAL, so each of them would bind to its own copy
+# of the RTTI of the types it shares with the USD libraries and plugins, which
+# breaks TfEnum, VtValue and dynamic_cast across them.  Loading the modules with
+# RTLD_GLOBAL makes them all use a single copy.
+if platform.system() == "FreeBSD":
+    class _DlopenFlagsWrapper(object):
+        def __enter__(self):
+            import os, sys
+            self._flags = sys.getdlopenflags()
+            sys.setdlopenflags(self._flags | os.RTLD_GLOBAL)
+        def __exit__(self, exc_type, ex_val, exc_tb):
+            import sys
+            sys.setdlopenflags(self._flags)
+else:
+    class _DlopenFlagsWrapper(object):
+        def __enter__(self):
+            pass
+        def __exit__(self, exc_type, ex_val, exc_tb):
+            pass
 del platform, sys
 
 
@@ -82,7 +103,7 @@ def PreparePythonModule(moduleName=None)
             moduleName = f_locals["__name__"].split(".")[-1]
             moduleName = "_" + moduleName[0].lower() + moduleName[1:]
 
-        with WindowsImportWrapper():
+        with WindowsImportWrapper(), _DlopenFlagsWrapper():
             module = importlib.import_module(
                     "." + moduleName, f_locals["__name__"])
 

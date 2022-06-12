--- global.pri.orig	2022-01-23 17:42:27 UTC
+++ global.pri
@@ -40,16 +40,16 @@ run-without-python {
 } else {
     # from <https://docs.python.org/3/c-api/intro.html#include-files>:
     # "Since Python may define some pre-processor definitions which affect the standard headers on some systems, you must include Python.h before any standard headers are included."
-    CONFIG += python
-    python3 {
-      PYV=3
+    CONFIG += python3.8
+#    python3 {
+      PYV=3.8
       PY_PKG_SUFFIX=-embed
       PYTHON_CONFIG_FLAGS=--embed
-    } else {
-      PYV=2
-      PY_PKG_SUFFIX=
-      PYTHON_CONFIG_FLAGS=
-    }
+#    } else {
+#      PYV=2.7
+#      PY_PKG_SUFFIX=
+#      PYTHON_CONFIG_FLAGS=
+#    }
     # PYVER contains just major.minor
     PYVER=$$system(python$$PYV -c \"import platform; print(\'.\'.join(platform.python_version_tuple()[:2]))\")
     PYVERNODOT=$$replace(PYVER,\\.,)

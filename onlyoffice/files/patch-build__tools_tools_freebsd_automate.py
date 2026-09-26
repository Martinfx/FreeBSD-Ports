--- build_tools/tools/freebsd/automate.py.orig	2026-09-24 21:58:50 UTC
+++ build_tools/tools/freebsd/automate.py
@@ -0,0 +1,49 @@
+#!/usr/bin/env python
+
+import sys
+sys.path.append('../../scripts')
+import base
+import os
+
+branch = "master"
+
+array_args = sys.argv[1:]
+array_modules = []
+
+# build_tools looks for qmake in <qt-dir>/clang_64/bin and takes the Qt
+# version from the name of <qt-dir>
+qt_root = "qt_build/Qt-%%QT_VERSION%%"
+base.set_env('QT_SELECT', 'qt5')
+if not base.is_dir(qt_root + "/clang_64"):
+    base.cmd("mkdir", ["-p", qt_root])
+    base.cmd("ln", ["-s", "%%QT_ARCHDIR%%", qt_root + "/clang_64"])
+
+config = {}
+for arg in array_args:
+  if (0 == arg.find("--")):
+    indexEq = arg.find("=")
+    if (-1 != indexEq):
+      config[arg[2:indexEq]] = arg[indexEq + 1:]
+  else:
+    array_modules.append(arg)
+
+if ("branch" in config):
+  branch = config["branch"]
+
+modules = " ".join(array_modules)
+if ("" == modules):
+  modules = "desktop"
+
+print("---------------------------------------------")
+print("build branch: " + branch)
+print("build modules: " + modules)
+print("---------------------------------------------")
+
+build_tools_params = ["--branch", branch,
+                      "--module", modules,
+                      "--update", "0",
+                      "--platform", "freebsd_64",
+                      "--qt-dir", os.getcwd() + "/" + qt_root]
+
+base.cmd_in_dir("../..", "./configure.py", build_tools_params)
+base.cmd_in_dir("../..", "./make.py")

--- build_tools/scripts/base.py.orig	2026-11-05 00:00:00 UTC
+++ build_tools/scripts/base.py
@@ -932,6 +932,8 @@
   return ret_params
 
 def qt_copy_lib(lib, dir):
+  if ("freebsd" == host_platform()):
+    return # the system Qt is used
   qt_dir = get_env("QT_DEPLOY")
 
   # TODO: remove version from library name
@@ -973,6 +975,8 @@
   return isExist
 
 def qt_copy_icu(out, platform):
+  if ("freebsd" == host_platform()):
+    return # the system Qt is used
   tests = [get_env("QT_DEPLOY") + "/../lib"]
   prefix = ""
   postfixes = [""]
@@ -1002,6 +1006,8 @@
   return False
 
 def qt_copy_plugin(name, out):
+  if ("freebsd" == host_platform()):
+    return # the system Qt is used
   src = get_env("QT_DEPLOY") + "/../plugins/" + name
   if not is_dir(src):
     return
@@ -1614,9 +1620,15 @@
 def support_old_versions_plugins(out_dir):
   if is_file(out_dir + "/pluginBase.js"):
     return
-  download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.js", out_dir + "/plugins.js")
-  download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins-ui.js", out_dir + "/plugins-ui.js")
-  download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.css", out_dir + "/plugins.css")
+#  download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.js", out_dir + "/plugins.js")
+#  download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins-ui.js", out_dir + "/plugins-ui.js")
+#  download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.css", out_dir + "/plugins.css")
+  git_dir = get_script_dir() + "/../.."
+  plugins_dir = git_dir + "/sdkjs-plugins"
+  copy_file(plugins_dir + "/v1/plugins.js", out_dir + "/plugins.js")
+  copy_file(plugins_dir + "/v1/plugins-ui.js", out_dir + "/plugins-ui.js")
+  copy_file(plugins_dir + "/v1/plugins.css", out_dir + "/plugins.css")
+
   content_plugin_base = ""
   with open(get_path(out_dir + "/plugins.js"), "r") as file:
     content_plugin_base += file.read()
@@ -1769,7 +1781,7 @@
 def clone_marketplace_plugin(out_dir, is_name_as_guid=False, is_replace_paths=False, is_delete_git_dir=True, git_owner=""):
   old_cur = os.getcwd()
   os.chdir(out_dir)
-  git_update("onlyoffice.github.io", False, True, git_owner)
+#  git_update("onlyoffice.github.io", False, True, git_owner)
   os.chdir(old_cur)
 
   dst_dir_name = "marketplace"

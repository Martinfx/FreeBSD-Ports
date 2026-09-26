--- build_tools/scripts/base.py.orig	2026-09-24 21:58:50 UTC
+++ build_tools/scripts/base.py
@@ -853,6 +853,8 @@ def qt_config_as_param(value):
   return ret_params
 
 def qt_copy_lib(lib, dir):
+  if ("freebsd" == host_platform()):
+    return # the system Qt is used
   qt_dir = get_env("QT_DEPLOY")
   if ("windows" == host_platform()):
     if ("" == qt_dst_postfix()):
@@ -886,6 +888,8 @@ def _check_icu_common(dir, out):
   return isExist
 
 def qt_copy_icu(out):
+  if ("freebsd" == host_platform()):
+    return # the system Qt is used
   tests = [get_env("QT_DEPLOY") + "/../lib", "/lib", "/lib/x86_64-linux-gnu", "/lib64", "/lib64/x86_64-linux-gnu"]
   tests += ["/usr/lib", "/usr/lib/x86_64-linux-gnu", "/usr/lib64", "/usr/lib64/x86_64-linux-gnu"]
   tests += ["/lib/i386-linux-gnu", "/usr/lib/i386-linux-gnu"]
@@ -897,6 +901,8 @@ def qt_copy_icu(out):
   return False
 
 def qt_copy_plugin(name, out):
+  if ("freebsd" == host_platform()):
+    return # the system Qt is used
   src = get_env("QT_DEPLOY") + "/../plugins/" + name
   if not is_dir(src):
     return
@@ -1449,9 +1455,15 @@ def copy_sdkjs_plugins_server(dst_dir, i
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
@@ -1595,7 +1607,7 @@ def copy_v8_files(core_dir, deploy_dir,
 def clone_marketplace_plugin(out_dir, is_name_as_guid=False, is_replace_paths=False, is_delete_git_dir=True, git_owner=""):  
   old_cur = os.getcwd()
   os.chdir(out_dir)
-  git_update("onlyoffice.github.io", False, True, git_owner)
+#  git_update("onlyoffice.github.io", False, True, git_owner)
   os.chdir(old_cur)
 
   dst_dir_name = "marketplace"

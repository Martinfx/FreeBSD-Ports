--- build_tools/scripts/deploy_desktop.py.orig	2025-09-24 14:52:58 UTC
+++ build_tools/scripts/deploy_desktop.py
@@ -120,7 +120,7 @@ def make():
   
     # cef
     build_dir_name = "build"
-    if (0 == platform.find("linux")) and (config.check_option("config", "cef_version_107")):
+    if (0 == platform.find("freebsd")) and (config.check_option("config", "cef_version_107")):
       build_dir_name = "build_107"
     elif (0 == platform.find("mac")) and (config.check_option("config", "use_v8")):
       build_dir_name = "build_103"
@@ -189,7 +189,7 @@ def make():
           base.copy_file(git_dir + "/desktop-apps/win-linux/extras/online-installer/" + apps_postfix + "/online-installer.exe", root_dir + "/online-installer.exe")
         base.copy_file(git_dir + "/desktop-apps/win-linux/" + apps_postfix + "/DesktopEditors.exe", root_dir + "/editors.exe")
         base.copy_file(git_dir + "/desktop-apps/win-linux/res/icons/desktopeditors.ico", root_dir + "/app.ico")
-      elif (0 == platform.find("linux")):
+      elif (0 == platform.find("freebsd")):
         base.copy_file(git_dir + "/desktop-apps/win-linux/" + apps_postfix + "/DesktopEditors", root_dir + "/DesktopEditors")
 
       if base.check_congig_option_with_platfom(platform, "libvlc"):
@@ -233,9 +233,12 @@ def make():
 
     # io
     base.create_dir(root_dir + "/editors/sdkjs-plugins/v1")
-    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.js", root_dir + "/editors/sdkjs-plugins/v1/plugins.js")
-    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins-ui.js", root_dir + "/editors/sdkjs-plugins/v1/plugins-ui.js")
-    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.css", root_dir + "/editors/sdkjs-plugins/v1/plugins.css")
+#    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.js", root_dir + "/editors/sdkjs-plugins/v1/plugins.js")
+#    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins-ui.js", root_dir + "/editors/sdkjs-plugins/v1/plugins-ui.js")
+#    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.css", root_dir + "/editors/sdkjs-plugins/v1/plugins.css")
+    base.copy_file(plugins_dir + "/v1/plugins.js", js_dir + "/editors/sdkjs-plugins/v1/plugins.js")
+    base.copy_file(plugins_dir + "/v1/plugins-ui.js", js_dir + "/editors/sdkjs-plugins/v1/plugins-ui.js")
+    base.copy_file(plugins_dir + "/v1/plugins.css", js_dir + "/editors/sdkjs-plugins/v1/plugins.css")
     base.support_old_versions_plugins(root_dir + "/editors/sdkjs-plugins")
 
     base.copy_sdkjs_plugin(git_dir + "/desktop-sdk/ChromiumBasedEditors/plugins/encrypt", root_dir + "/editors/sdkjs-plugins", "advanced2", True)

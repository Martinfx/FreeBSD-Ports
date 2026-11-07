--- build_tools/scripts/deploy_desktop.py.orig	2026-11-05 00:00:00 UTC
+++ build_tools/scripts/deploy_desktop.py
@@ -136,7 +136,9 @@
     elif (0 == platform.find("mac")) and (config.check_option("config", "use_v8")):
       build_dir_name = "build_103"
 
-    if not isWindowsXP:
+    if (0 == platform.find("freebsd")):
+      pass # www/cef is used, libcef is found through the RPATH
+    elif not isWindowsXP:
       base.copy_files(core_dir + "/Common/3dParty/cef/" + platform + "/" + build_dir_name + "/*", root_dir)
     else:
       base.copy_files(core_dir + "/Common/3dParty/cef/" + native_platform + "/" + build_dir_name + "/*", root_dir)
@@ -211,7 +213,7 @@
           base.copy_file(git_dir + "/desktop-apps/win-linux/extras/update-daemon/" + apps_postfix + "/updatesvc.exe", root_dir + "/updatesvc.exe")
         base.copy_file(git_dir + "/desktop-apps/win-linux/" + apps_postfix + "/DesktopEditors.exe", root_dir + "/editors.exe")
         base.copy_file(git_dir + "/desktop-apps/win-linux/res/icons/desktopeditors.ico", root_dir + "/app.ico")
-      elif (0 == platform.find("linux")):
+      elif (0 == platform.find("linux")) or (0 == platform.find("freebsd")):
         base.copy_file(git_dir + "/desktop-apps/win-linux/" + apps_postfix + "/DesktopEditors", root_dir + "/DesktopEditors")
 
       if base.check_congig_option_with_platfom(platform, "libvlc"):
@@ -248,9 +250,8 @@
 
     # io
     base.create_dir(root_dir + "/editors/sdkjs-plugins/v1")
-    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.js", root_dir + "/editors/sdkjs-plugins/v1/plugins.js")
-    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins-ui.js", root_dir + "/editors/sdkjs-plugins/v1/plugins-ui.js")
-    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.css", root_dir + "/editors/sdkjs-plugins/v1/plugins.css")
+    for plugins_file in ["plugins.js", "plugins-ui.js", "plugins.css"]:
+      base.copy_file(git_dir + "/sdkjs-plugins/v1/" + plugins_file, root_dir + "/editors/sdkjs-plugins/v1/" + plugins_file)
     base.support_old_versions_plugins(root_dir + "/editors/sdkjs-plugins")
 
     base.copy_sdkjs_plugin(git_dir + "/desktop-sdk/ChromiumBasedEditors/plugins/encrypt", root_dir + "/editors/sdkjs-plugins", "advanced2", True)

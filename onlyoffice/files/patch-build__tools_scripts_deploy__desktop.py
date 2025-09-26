--- build_tools/scripts/deploy_desktop.py.orig	2025-09-26 05:38:13 UTC
+++ build_tools/scripts/deploy_desktop.py
@@ -120,7 +120,7 @@ def make():
   
     # cef
     build_dir_name = "build"
-    if (0 == platform.find("linux")) and (config.check_option("config", "cef_version_107")):
+    if (0 == platform.find("freebsd")) and (config.check_option("config", "cef_version_107")):
       build_dir_name = "build_107"
     elif (0 == platform.find("mac")) and (config.check_option("config", "use_v8")):
       build_dir_name = "build_103"
@@ -173,7 +173,7 @@ def make():
 
       base.qt_copy_plugin("styles", root_dir)
 
-      if (0 == platform.find("linux")):
+      if (0 == platform.find("freebsd")):
         base.qt_copy_lib("Qt5DBus", root_dir)
         base.qt_copy_lib("Qt5X11Extras", root_dir)
         base.qt_copy_lib("Qt5XcbQpa", root_dir)
@@ -189,7 +189,7 @@ def make():
           base.copy_file(git_dir + "/desktop-apps/win-linux/extras/online-installer/" + apps_postfix + "/online-installer.exe", root_dir + "/online-installer.exe")
         base.copy_file(git_dir + "/desktop-apps/win-linux/" + apps_postfix + "/DesktopEditors.exe", root_dir + "/editors.exe")
         base.copy_file(git_dir + "/desktop-apps/win-linux/res/icons/desktopeditors.ico", root_dir + "/app.ico")
-      elif (0 == platform.find("linux")):
+      elif (0 == platform.find("freebsd")):
         base.copy_file(git_dir + "/desktop-apps/win-linux/" + apps_postfix + "/DesktopEditors", root_dir + "/DesktopEditors")
 
       if base.check_congig_option_with_platfom(platform, "libvlc"):
@@ -199,7 +199,7 @@ def make():
           base.copy_dir(vlc_dir + "/plugins", root_dir + "/plugins")          
           base.copy_files(vlc_dir + "/*.dll", root_dir)
           base.copy_file(vlc_dir + "/vlc-cache-gen.exe", root_dir + "/vlc-cache-gen.exe")
-        elif (0 == platform.find("linux")):
+        elif (0 == platform.find("freebsd")):
           base.copy_dir(vlc_dir + "/vlc/plugins", root_dir + "/plugins")
           base.copy_file(vlc_dir + "/vlc/libcompat.a", root_dir + "/libcompat.a")
           copy_lib_with_links(vlc_dir + "/vlc", root_dir, "libvlc_pulse.so", "0.0.0")
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

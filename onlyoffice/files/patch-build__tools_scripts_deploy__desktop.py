--- build_tools/scripts/deploy_desktop.py.orig	2025-09-24 14:44:06 UTC
+++ build_tools/scripts/deploy_desktop.py
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

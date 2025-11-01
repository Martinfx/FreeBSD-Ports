--- build_tools/scripts/deploy_server.py.orig	2025-09-23 22:50:09 UTC
+++ build_tools/scripts/deploy_server.py
@@ -98,7 +98,7 @@ def make():
       base.copy_file(core_dir + "/Common/3dParty/icu/" + platform + "/build/icudt58.dll", converter_dir + "/icudt58.dll")
       base.copy_file(core_dir + "/Common/3dParty/icu/" + platform + "/build/icuuc58.dll", converter_dir + "/icuuc58.dll")
 
-    if (0 == platform.find("linux")):
+    if (0 == platform.find("linux") and 0 != platform.find('freebsd')):
       base.copy_file(core_dir + "/Common/3dParty/icu/" + platform + "/build/libicudata.so.58", converter_dir + "/libicudata.so.58")
       base.copy_file(core_dir + "/Common/3dParty/icu/" + platform + "/build/libicuuc.so.58", converter_dir + "/libicuuc.so.58")
 
@@ -134,9 +134,13 @@ def make():
     else:
       base.generate_sdkjs_plugin_list(js_dir + "/sdkjs-plugins/plugin-list-default.json")
     base.create_dir(js_dir + "/sdkjs-plugins/v1")
-    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.js", js_dir + "/sdkjs-plugins/v1/plugins.js")
-    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins-ui.js", js_dir + "/sdkjs-plugins/v1/plugins-ui.js")
-    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.css", js_dir + "/sdkjs-plugins/v1/plugins.css")
+#    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.js", js_dir + "/sdkjs-plugins/v1/plugins.js")
+#    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins-ui.js", js_dir + "/sdkjs-plugins/v1/plugins-ui.js")
+#    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.css", js_dir + "/sdkjs-plugins/v1/plugins.css")
+    base.copy_file(plugins_dir + "/v1/plugins.js", js_dir + "/sdkjs-plugins/v1/plugins.js")
+    base.copy_file(plugins_dir + "/v1/plugins-ui.js", js_dir + "/sdkjs-plugins/v1/plugins-ui.js")
+    base.copy_file(plugins_dir + "/v1/plugins.css", js_dir + "/sdkjs-plugins/v1/plugins.css")
+
     base.support_old_versions_plugins(js_dir + "/sdkjs-plugins")
 
     # tools

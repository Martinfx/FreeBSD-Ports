--- src/brave/script/web_discovery_project.py.orig	2026-06-01 00:00:00 UTC
+++ src/brave/script/web_discovery_project.py
@@ -15,6 +15,24 @@
     NPM += '.cmd'
 
 
+# The bundles //brave/components/brave_extension declares as the outputs of
+# web_discovery_project_resources.
+BUNDLES = [
+    os.path.join('core', 'content-script.bundle.js'),
+    os.path.join('hpnv2', 'worker.asmjs.bundle.js'),
+    os.path.join('hpnv2', 'worker.wasm.bundle.js'),
+    'star.wasm',
+]
+
+
+def write_empty_bundles(output_path):
+    for name in BUNDLES:
+        path = os.path.join(output_path, name)
+        os.makedirs(os.path.dirname(path), exist_ok=True)
+        with open(path, 'w', encoding='utf-8'):
+            pass
+
+
 def main():
     args = parse_args()
     env = os.environ.copy()
@@ -26,6 +44,14 @@
             execute_stdout([NPM, 'install', '--no-save', '--yes'], env=env)
         if args.build:
             env["OUTPUT_PATH"] = args.output_path
+            if not os.path.isdir(
+                    os.path.join(WEB_DISCOVERY_DIR, 'node_modules')):
+                # The Web Discovery Project builds itself with npm out of its
+                # own git checkout, and a build from release tarballs has
+                # neither. Write the bundles the resource pack expects as empty
+                # files; the feature itself is off (enable_web_discovery).
+                write_empty_bundles(args.output_path)
+                return
             execute_stdout([NPM, 'run', 'build-module'], env=env)
 
 

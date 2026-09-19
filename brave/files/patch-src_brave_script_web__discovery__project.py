--- src/brave/script/web_discovery_project.py.orig	2026-06-01 00:00:00 UTC
+++ src/brave/script/web_discovery_project.py
@@ -15,6 +15,58 @@
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
+# The extension's background script imports this directory as
+# 'gen/brave/web-discovery-project'.  webpack resolves that to index.js and
+# ts-loader type checks it against index.d.ts, so a build without the project
+# has to leave both behind or the extension bundle does not compile.
+STUB_MODULE = """\
+// The Web Discovery Project builds itself with npm out of its own git
+// checkout, which a build from release tarballs does not have.  The feature is
+// off (enable_web_discovery) and the extension only reaches for this once the
+// brave.web_discovery_enabled preference is turned on, so a class that does
+// nothing is enough to keep the bundle building.
+export class App {
+  constructor () {
+    this.isRunning = false
+  }
+
+  start () {}
+
+  stop () {}
+}
+"""
+
+STUB_TYPES = """\
+export declare class App {
+  constructor (options: { version: string })
+  isRunning: boolean
+  start (): void
+  stop (): void
+}
+"""
+
+
+def write_stub_build(output_path):
+    for name in BUNDLES:
+        path = os.path.join(output_path, name)
+        os.makedirs(os.path.dirname(path), exist_ok=True)
+        with open(path, 'w', encoding='utf-8'):
+            pass
+    for name, text in (('index.js', STUB_MODULE), ('index.d.ts', STUB_TYPES)):
+        with open(os.path.join(output_path, name), 'w',
+                  encoding='utf-8') as out:
+            out.write(text)
+
+
 def main():
     args = parse_args()
     env = os.environ.copy()
@@ -26,6 +78,10 @@
             execute_stdout([NPM, 'install', '--no-save', '--yes'], env=env)
         if args.build:
             env["OUTPUT_PATH"] = args.output_path
+            if not os.path.isdir(
+                    os.path.join(WEB_DISCOVERY_DIR, 'node_modules')):
+                write_stub_build(args.output_path)
+                return
             execute_stdout([NPM, 'run', 'build-module'], env=env)
 
 

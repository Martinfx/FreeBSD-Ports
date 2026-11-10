--- src/third_party/blink/renderer/build/scripts/run_with_pythonpath.py.orig	2026-11-02 23:22:33 UTC
+++ src/third_party/blink/renderer/build/scripts/run_with_pythonpath.py
@@ -23,6 +23,7 @@ def main():
             (os.pathsep + env['PYTHONPATH']) if 'PYTHONPATH' in env else ''
         )
         env['PYTHONPATH'] = os.pathsep.join(python_paths) + existing_pp
+    env['LD_LIBRARY_PATH'] = "${WRKSRC}/out/Release"
     sys.exit(subprocess.call([sys.executable] + args, env=env))
 
 

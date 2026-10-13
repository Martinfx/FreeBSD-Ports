--- tools/prefs_files_generator/prefs_files_generator.py.orig	2026-08-25 00:00:00 UTC
+++ tools/prefs_files_generator/prefs_files_generator.py
@@ -117,6 +117,10 @@ def main():
     parser.add_argument('--target-os')
     args = parser.parse_args()
 
+    # The BSDs take the Linux defaults (default_linux).
+    if args.target_os in ('freebsd', 'openbsd'):
+        args.target_os = 'linux'
+
     prefs_definitions = json.load(args.prefs_definitions)
     prefs_list = generate_prefs_list('vivaldi', prefs_definitions['vivaldi'])
     prefs_list.sort(key=lambda i: i["name"])

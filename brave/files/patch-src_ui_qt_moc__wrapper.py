--- src/ui/qt/moc_wrapper.py.orig	2026-11-24 12:50:30 UTC
+++ src/ui/qt/moc_wrapper.py
@@ -20,4 +20,4 @@ args = parser.parse_args()
 if args.path is None:
     subprocess.check_call(["moc", args.input, "-o", args.output])
 else:
-    subprocess.check_call([args.path + "/moc", args.input, "-o", args.output])
+    subprocess.check_call([args.path, args.input, "-o", args.output])

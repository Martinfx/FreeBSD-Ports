--- src/v8/tools/metagen/compile_flags.py.orig	2026-11-02 23:22:33 UTC
+++ src/v8/tools/metagen/compile_flags.py
@@ -109,6 +109,10 @@ def _find_gn(source_root: str) -> str |
     plats = ("mac",)
   elif sys.platform == "win32":
     plats = ("win",)
+  elif sys.platform.startswith("freebsd"):
+    # The Linux binary in buildtools/linux64 is of no use here; the port
+    # links the gn it bootstrapped into buildtools/freebsd.
+    plats = ("freebsd",)
   else:
     plats = ("linux64",)
   for plat in plats:

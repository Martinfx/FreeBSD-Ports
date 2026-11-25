--- src/build/linux/strip_binary.py.orig	2026-11-24 12:50:30 UTC
+++ src/build/linux/strip_binary.py
@@ -10,6 +10,7 @@ import sys
 
 
 def main() -> int:
+    return 0
     parser = argparse.ArgumentParser(
         description="Strip binary using LLVM tools."
     )

--- src/dynarec/dynarec.c.orig	2025-04-11 15:04:12 UTC
+++ src/dynarec/dynarec.c
@@ -149,7 +149,7 @@ void DynaRun(x64emu_t* emu)
 void DynaRun(x64emu_t* emu)
 {
     // prepare setjump for signal handling
-    JUMPBUFF jmpbuf[1] = {0};
+    JUMPBUFF *jmpbuf;
     int skip = 0;
     JUMPBUFF *old_jmpbuf = emu->jmpbuf;
     #ifdef RV64

--- core/Common/3dParty/v8_89/v8/src/base/cpu.cc.orig	2025-09-23 22:49:55 UTC
+++ core/Common/3dParty/v8_89/v8/src/base/cpu.cc
@@ -545,6 +545,7 @@ CPU::CPU()
 
 #if V8_OS_LINUX
 
+#if V8_OS_LINUX
   CPUInfo cpu_info;
 
   // Extract implementor from the "CPU implementer" field.
@@ -578,6 +579,7 @@ CPU::CPU()
     }
     delete[] part;
   }
+#endif
 
   // Extract architecture from the "CPU Architecture" field.
   // The list is well-known, unlike the the output of

--- src/app/integration/interpreter/interpreter.cpp.orig	2025-07-27 13:01:17 UTC
+++ src/app/integration/interpreter/interpreter.cpp
@@ -189,7 +189,7 @@ registerValueT read256BitRegister(const std::string& r
     }
 
     if (!use32BitLanes){
-        double valueArray[arrSize] = {0};
+        double valueArray[arrSize];
 
         // Convert bytes to doubles
         for (int i = 0; i < 4; i++) {
@@ -1472,4 +1472,4 @@ bool runTempCode(const std::string& codeIn, const uint
     tempIcicle = icicle;
     updateRegs(true);
     return true;
-}
\ No newline at end of file
+}

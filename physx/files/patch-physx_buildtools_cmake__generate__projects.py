--- physx/buildtools/cmake_generate_projects.py.orig	2022-11-09 12:26:46 UTC
+++ physx/buildtools/cmake_generate_projects.py
@@ -118,6 +118,8 @@ class CMakePreset:
             return False
         elif self.targetPlatform == 'linuxAarch64':
             return False
+        elif self.targetPlatform == 'freebsd':
+            return False
         elif self.targetPlatform == 'android':
             return False
         return True
@@ -163,6 +165,8 @@ class CMakePreset:
             outString = outString + '-G \"MinGW Makefiles\"'
         elif self.targetPlatform == 'linux':
             outString = outString + '-G \"Unix Makefiles\"'
+        elif self.targetPlatform == 'freebsd':
+            outString = outString + '-G \"Unix Makefiles\"'
         elif self.targetPlatform == 'linuxAarch64':
             outString = outString + '-G \"Unix Makefiles\"'
 
@@ -314,6 +318,20 @@ class CMakePreset:
                     os.environ['PM_CMakeModules_PATH'] + \
                     '/linux/LinuxAarch64.cmake\"'
             return outString
+        elif self.targetPlatform == 'freebsd':
+            outString = outString + ' -DTARGET_BUILD_PLATFORM=freebsd'
+            outString = outString + ' -DPX_OUTPUT_ARCH=x86'
+            outString = outString + ' -DNDEBUG=0'
+            if self.compiler == 'clang':
+                if os.environ.get('PM_clang_PATH') is not None:
+                    outString = outString + ' -DCMAKE_C_COMPILER=' + \
+                        os.environ['PM_clang_PATH'] + '/usr/bin/clang'
+                    outString = outString + ' -DCMAKE_CXX_COMPILER=' + \
+                        os.environ['PM_clang_PATH'] + '/usr/bin/clang++'
+                else:
+                    outString = outString + ' -DCMAKE_C_COMPILER=clang'
+                    outString = outString + ' -DCMAKE_CXX_COMPILER=clang++'
+            return outString
         elif self.targetPlatform == 'mac64':
             outString = outString + ' -DTARGET_BUILD_PLATFORM=mac'
             outString = outString + ' -DPX_OUTPUT_ARCH=x86'
@@ -393,7 +411,7 @@ def presetProvided(pName):
             # run the cmake script
             #print('Cmake params:' + cmakeParams)
             os.chdir(os.path.join(os.environ['PHYSX_ROOT_DIR'], outputDir))
-            # print(cmakeExec + ' \"' + os.environ['PHYSX_ROOT_DIR'] + '/compiler/' + cmakeMasterDir + '\"' + cmakeParams + ' -DCMAKE_BUILD_TYPE=' + config)
+            print(cmakeExec + ' \"' + os.environ['PHYSX_ROOT_DIR'] + '/compiler/' + cmakeMasterDir + '\"' + cmakeParams + ' -DCMAKE_BUILD_TYPE=' + config)
             os.system(cmakeExec + ' \"' + os.environ['PHYSX_ROOT_DIR'] + '/compiler/' +
                       cmakeMasterDir + '\"' + cmakeParams + ' -DCMAKE_BUILD_TYPE=' + config)
             os.chdir(os.environ['PHYSX_ROOT_DIR'])

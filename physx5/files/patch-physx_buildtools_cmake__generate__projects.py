--- physx/buildtools/cmake_generate_projects.py.orig	2024-05-31 15:16:16 UTC
+++ physx/buildtools/cmake_generate_projects.py
@@ -119,6 +119,8 @@ class CMakePreset:
             return False
         elif self.targetPlatform == 'linuxAarch64':
             return False
+        elif self.targetPlatform == 'freebsd':
+            return False
         return True
 
     def getCMakeSwitches(self):
@@ -166,7 +168,7 @@ class CMakePreset:
         elif self.compiler == 'xcode':
             outString = outString + '-G Xcode'
         # Linux
-        elif self.targetPlatform in ['linux', 'linuxAarch64']:
+        elif self.targetPlatform in ['linux', 'linuxAarch64', 'freebsd']:
             if self.generator is not None and self.generator == 'ninja':
                 outString = outString + '-G \"Ninja\"'
                 outString = outString + ' -DCMAKE_MAKE_PROGRAM=' + os.environ['PM_ninja_PATH'] + '/ninja'
@@ -215,6 +217,20 @@ class CMakePreset:
                 outString = outString + ' -DCMAKE_TOOLCHAIN_FILE=\"' + \
                     cmake_modules_root + '/linux/LinuxAarch64.cmake\"'
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
@@ -287,7 +303,7 @@ def presetProvided(pName, physx_root_dir):
             # run the cmake script
             #print('Cmake params:' + cmakeParams)
             os.chdir(os.path.join(os.environ['PHYSX_ROOT_DIR'], outputDir))
-            # print(cmakeExec + ' \"' + os.environ['PHYSX_ROOT_DIR'] + '/compiler/' + cmakeMasterDir + '\"' + cmakeParams + ' -DCMAKE_BUILD_TYPE=' + config)
+            print(cmakeExec + ' \"' + os.environ['PHYSX_ROOT_DIR'] + '/compiler/' + cmakeMasterDir + '\"' + cmakeParams + ' -DCMAKE_BUILD_TYPE=' + config)
             os.system(cmakeExec + ' \"' + os.environ['PHYSX_ROOT_DIR'] + '/compiler/' +
                       cmakeMasterDir + '\"' + cmakeParams + ' -DCMAKE_BUILD_TYPE=' + config)
             os.chdir(os.environ['PHYSX_ROOT_DIR'])

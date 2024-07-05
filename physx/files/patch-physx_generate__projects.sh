--- physx/generate_projects.sh.orig	2024-07-05 08:50:57 UTC
+++ physx/generate_projects.sh
@@ -1,4 +1,4 @@
-#!/bin/bash +x
+#!/usr/local/bin/bash +x
 
 export PHYSX_ROOT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
 export PM_PxShared_PATH="$PHYSX_ROOT_DIR/../pxshared"
@@ -11,9 +11,9 @@ export PM_PATHS="$PM_opengllinux_PATH;$PM_TARGA_PATH;$
 
 
 cd "$( dirname "${BASH_SOURCE[0]}" )"
-python ./buildtools/cmake_generate_projects.py $1
+python3 ./buildtools/cmake_generate_projects.py $1
 status=$?
 if [ "$status" -ne "0" ]; then
 echo "Error $status"
 exit 1
-fi
\ No newline at end of file
+fi

--- physx/generate_projects.sh.orig	2024-05-31 15:16:16 UTC
+++ physx/generate_projects.sh
@@ -1,4 +1,4 @@
-#!/bin/bash +x
+#!/usr/local/bin/bash -x
 
 if [ -n "${BASH_SOURCE[0]}" ]; then
     SCRIPT_DIR=$(dirname "${BASH_SOURCE[0]}")
@@ -13,7 +13,7 @@ fi
 source "$PACKMAN_CMD" init
 
 if [[ $# -eq 0 ]] ; then
-    exec "$SCRIPT_DIR/buildtools/packman/python.sh" "$SCRIPT_DIR/buildtools/cmake_generate_projects.py"
+    python "$SCRIPT_DIR/buildtools/cmake_generate_projects.py"
     exit 1
 fi
 
@@ -23,14 +23,14 @@ export targetPlatform=$1
 
 if [ "$1" = "$cutName" ] ; then
     source "$PACKMAN_CMD" pull "$SCRIPT_DIR/dependencies.xml" --platform $1
-    exec "$SCRIPT_DIR/buildtools/packman/python.sh" "$SCRIPT_DIR/buildtools/cmake_generate_projects.py" "$targetPlatform"
+    python "$SCRIPT_DIR/buildtools/cmake_generate_projects.py" "$targetPlatform"
 else
     source "$PACKMAN_CMD" pull "$SCRIPT_DIR/dependencies.xml" --platform $cutName
-    exec "$SCRIPT_DIR/buildtools/packman/python.sh" "$SCRIPT_DIR/buildtools/cmake_generate_projects.py" "$targetPlatform"
+    python "$SCRIPT_DIR/buildtools/cmake_generate_projects.py" "$targetPlatform"
 fi
 
 status=$?
 if [ "$status" -ne "0" ]; then
  echo "Error $status"
  exit 1
-fi
\ No newline at end of file
+fi

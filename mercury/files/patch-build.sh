--- build.sh.orig	2024-03-06 02:31:38 UTC
+++ build.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+!/bin/sh
 
 # Copyright (c) 2024 Alex313031.
 
@@ -29,7 +29,7 @@ esac
 
 # mozilla source dir env variable
 if [ -z "${HG_SRC_DIR}" ]; then 
-    HG_SRC_DIR="$HOME/mozilla-unified"
+    HG_SRC_DIR="${WRKSRC}/mozilla-unified"
     export HG_SRC_DIR
 else 
     HG_SRC_DIR="${HG_SRC_DIR}"

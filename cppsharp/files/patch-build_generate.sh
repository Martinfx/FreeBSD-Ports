--- build/generate.sh.orig	2024-06-09 05:32:25 UTC
+++ build/generate.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 set -e
 DIR=$( cd "$( dirname "$0" )" && pwd )
 "$DIR/build.sh" generate "$@"

--- shadps4plus/extractor/batch_install.sh.orig	2026-01-22 18:54:16 UTC
+++ shadps4plus/extractor/batch_install.sh
@@ -1,13 +1,8 @@
-#!/bin/bash
+#!/bin/sh
 
-oldIFS="$IFS"
-IFS=$'\n'
-
-for f in $1/*.pkg ; do
-	`dirname $0`/install_pkg.sh $f --batch
+for f in "$1"/*.pkg ; do
+	%%PREFIX%%/bin/shadps4-install-pkg "$f" --batch
 done
 
-IFS="$oldIFS"
-
 echo "Press [enter] to close"
-read
+read dummy

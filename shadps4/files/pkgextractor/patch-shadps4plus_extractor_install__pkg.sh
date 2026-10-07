--- shadps4plus/extractor/install_pkg.sh.orig	2026-01-22 18:54:16 UTC
+++ shadps4plus/extractor/install_pkg.sh
@@ -1,23 +1,23 @@
-#!/bin/bash
+#!/bin/sh
 
-gamesDir="PATH_TO_GAMES_DIR"
-addonsDir="PATH_TO_ADDONS_DIR"
+gamesDir="${SHADPS4_GAMES_DIR:-PATH_TO_GAMES_DIR}"
+addonsDir="${SHADPS4_ADDONS_DIR:-PATH_TO_ADDONS_DIR}"
 
-if [ "$gamesDir" == "PATH_TO_GAMES_DIR" ]; then
-	echo You need to update gamesDir with the games path used by ShadPs4
+if [ "$gamesDir" = "PATH_TO_GAMES_DIR" ]; then
+	echo Set SHADPS4_GAMES_DIR to the games path used by ShadPs4
 	echo "Press [enter] to close"
-	if [ "$2" != "--batch" ]; then read ; fi
+	if [ "$2" != "--batch" ]; then read dummy ; fi
 	exit
 fi
 
-if [ "$addonsDir" == "PATH_TO_ADDONS_DIR" ]; then
-	echo You need to update addonsDir with the addons path used by ShadPs4
+if [ "$addonsDir" = "PATH_TO_ADDONS_DIR" ]; then
+	echo Set SHADPS4_ADDONS_DIR to the addons path used by ShadPs4
 	echo "Press [enter] to close"
-	if [ "$2" != "--batch" ]; then read ; fi
+	if [ "$2" != "--batch" ]; then read dummy ; fi
 	exit
 fi
 
-`dirname $0`/pkg_extractor.AppImage "$1" --check-type
+%%PREFIX%%/bin/shadps4-pkg-extractor "$1" --check-type
 
 ret="$?"
 
@@ -25,17 +25,17 @@
 	echo "An error has occurred."
 else
 	if [ "$ret" -eq 101 ]; then
-		echo The file is a base game, installing to $gamesDir
+		echo The file is a base game, installing to "$gamesDir"
 	elif [ "$ret" -eq 102 ]; then
-		echo The file is a game update, installing to $gamesDir
+		echo The file is a game update, installing to "$gamesDir"
 	elif [ "$ret" -eq 103 ]; then
-		echo The file is a dlc, installing to $addonsDir
+		echo The file is a dlc, installing to "$addonsDir"
 		gamesDir=$addonsDir
 	fi
 	
-	`dirname $0`/pkg_extractor.AppImage "$1" $gamesDir
+	%%PREFIX%%/bin/shadps4-pkg-extractor "$1" "$gamesDir"
 fi
 
 echo "Press [enter] to close"
-if [ "$2" != "--batch" ]; then read ; fi
+if [ "$2" != "--batch" ]; then read dummy ; fi
 

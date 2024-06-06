--- build/premake.sh.orig	2024-06-05 21:42:22 UTC
+++ build/premake.sh
@@ -4,7 +4,7 @@ DIR=$( cd "$( dirname "$0" )" && pwd )
 
 case "$(uname -s)" in
 
-   Darwin|Linux)
+   Darwin|Linux|FreeBSD)
      "$DIR/premake/premake5" "$@"
      ;;
 

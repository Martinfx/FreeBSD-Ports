--- build/build.sh.orig	2023-10-18 15:27:43 UTC
+++ build/build.sh
@@ -33,7 +33,7 @@ build()
     restore
   fi
 
-  if [ $oshost = "linux" ] || [ $oshost = "macosx" ]; then
+  if [ $oshost = "linux" ] || [ $oshost = "macosx" ] || [ $oshost = "freebsd" ]; then
     config=$(tr '[:upper:]' '[:lower:]' <<< ${configuration}_$platform) make -C "$builddir/gmake/"
   fi
 
@@ -110,21 +110,22 @@ download_premake()
     premake_archive_ext=zip
   fi
   premake_path=$premake_dir/$premake_filename
-
-  if ! [ -f "$premake_path" ]; then
-    echo "Downloading and unpacking Premake..."
-    premake_version=5.0.0-beta2
-    premake_archive=premake-$premake_version-$oshost.$premake_archive_ext
-    premake_url=https://github.com/premake/premake-core/releases/download/v$premake_version/$premake_archive
-    curl -L -O $premake_url
-    if [ $oshost = "windows" ]; then
-      unzip $premake_archive $premake_filename -d "$premake_dir"
-    else
-      tar -xf $premake_archive -C "$premake_dir" ./$premake_filename
-    fi
-    chmod +x "$premake_path"
-    rm $premake_archive
-  fi
+  echo $premake_path
+#  ln -s "/usr/local/bin/premake5" $premake_path
+#  if ! [ -f "$premake_path" ]; then
+#    echo "Downloading and unpacking Premake..."
+#    premake_version=5.0.0-beta2
+#    premake_archive=premake-$premake_version-$oshost.$premake_archive_ext
+#    premake_url=https://github.com/premake/premake-core/releases/download/v$premake_version/$premake_archive
+#    curl -L -O $premake_url
+#    if [ $oshost = "windows" ]; then
+#      unzip $premake_archive $premake_filename -d "$premake_dir"
+#    else
+#      tar -xf $premake_archive -C "$premake_dir" ./$premake_filename
+#    fi
+#    chmod +x "$premake_path"
+#    rm $premake_archive
+#  fi
 }
 
 download_llvm()
@@ -156,6 +157,9 @@ detect_os()
     Linux)
       oshost=linux
       ;;
+    FreeBSD)
+      oshost=bsd
+      ;;
     CYGWIN*|MINGW32*|MSYS*|MINGW*)
       oshost=windows
       ;;
@@ -248,6 +252,7 @@ case "$cmd" in
     clone_llvm
     ;;
   build_llvm)
+    generate_config
     build_llvm
     ;;
   package_llvm)

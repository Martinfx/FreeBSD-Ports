--- cmake/modules/desktopapp_configuration.cmake.orig	2026-03-02 15:11:07 UTC
+++ cmake/modules/desktopapp_configuration.cmake
@@ -29,8 +29,8 @@ if(UNIX AND NOT APPLE)
     # Note: using cmake --install --prefix /some/prefix will keep the RPATH as configured above.
     #       Used for building packages: in which install dir is a path construction folder that will not be there in packages
 
-    set(CMAKE_INSTALL_LIBDIR "opt/megasync/lib") # override default "lib" from GNUInstallDirs
-    set(CMAKE_INSTALL_BINDIR "usr/bin") # override default "bin" from GNUInstallDirs
+    #set(CMAKE_INSTALL_LIBDIR "opt/megasync/lib") # override default "lib" from GNUInstallDirs
+    #set(CMAKE_INSTALL_BINDIR "usr/bin") # override default "bin" from GNUInstallDirs
 
     # Override CMAKE_INSTALL_PREFIX
     if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT) # In consecutive runs it will always be undef/false

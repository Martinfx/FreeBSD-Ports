--- cmake/Libraries.cmake.orig	2021-09-16 18:07:00 UTC
+++ cmake/Libraries.cmake
@@ -122,11 +122,9 @@ elseif(MAC)
 	find_library(OSX_FOUNDATION Foundation)
 	find_library(OSX_SERVICEMANAGEMENT ServiceManagement)
 elseif(UNIX)
-	if(LINUX)
-		find_library(LIBUDEV NAMES udev ludev libudev)
-		if(NOT LIBUDEV)
-			message(STATUS "Hardware detection disabled - Missing libudev")
-		endif()
+	find_library(LIBUDEV NAMES udev ludev libudev)
+	if(NOT LIBUDEV)
+		message(STATUS "Hardware detection disabled - Missing libudev")
 	endif()
 
 	find_package(PkgConfig REQUIRED)

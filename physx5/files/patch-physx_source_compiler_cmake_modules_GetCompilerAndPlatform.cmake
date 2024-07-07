--- physx/source/compiler/cmake/modules/GetCompilerAndPlatform.cmake.orig	2024-07-07 07:34:11 UTC
+++ physx/source/compiler/cmake/modules/GetCompilerAndPlatform.cmake
@@ -136,6 +136,9 @@ FUNCTION (GetPlatformBinName PLATFORM_BIN_NAME LIBPATH
 		ELSEIF(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "aarch64")
 			SET(RETVAL "linux.aarch64")
 		ENDIF()
+        ELSEIF(TARGET_BUILD_PLATFORM STREQUAL "freebsd")
+                        SET(RETVAL "freebsd.clang")
+
 	ENDIF()
 
 	SET(${PLATFORM_BIN_NAME} ${RETVAL} PARENT_SCOPE)

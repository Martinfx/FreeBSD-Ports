--- externals/cmakemodules/GetCompilerAndPlatform.cmake.orig	2024-07-05 08:53:50 UTC
+++ externals/cmakemodules/GetCompilerAndPlatform.cmake
@@ -126,6 +126,8 @@ FUNCTION (GetPlatformBinName PLATFORM_BIN_NAME LIBPATH
 		ELSEIF(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "aarch64")
 			SET(RETVAL "linux.aarch64")
 		ENDIF()
+	ELSEIF(TARGET_BUILD_PLATFORM STREQUAL "freebsd")
+		SET(RETVAL "freebsd.clang")
 	ENDIF()
 
 	SET(${PLATFORM_BIN_NAME} ${RETVAL} PARENT_SCOPE)

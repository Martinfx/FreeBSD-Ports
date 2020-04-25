--- cmake/Libraries.cmake.orig	2020-01-15 15:59:29 UTC
+++ cmake/Libraries.cmake
@@ -66,7 +66,11 @@ IF(MINGW AND NOT CMAKE_CROSSCOMPILING)
 	SET(CMAKE_CROSSCOMPILING ON)
 ENDIF()
 IF(QT_VENDOR STREQUAL "Governikus" OR FORCE_LEGACY_OPENSSL)
-	FIND_PACKAGE(OpenSSL 1.0.2 REQUIRED) # see openssl_rsa_psk.patch
+#	FIND_PACKAGE(OpenSSL 1.0.2 REQUIRED) # see openssl_rsa_psk.patch
+	message("OpenSSL include dir: ${OPENSSL_INCLUDE_DIR}")
+	message("OpenSSL libraries: ${OPENSSL_LIBRARIES}")
+	include_directories(${OPENSSL_INCLUDE_DIR})
+	list(APPEND LIB_LIST ${OPENSSL_LIBRARIES})
 ELSE()
 	FIND_PACKAGE(OpenSSL 1.1 REQUIRED)
 ENDIF()

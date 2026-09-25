--- cmake/macros/Public.cmake.orig	2026-04-24 18:55:54 UTC
+++ cmake/macros/Public.cmake
@@ -652,6 +652,15 @@ function(pxr_build_test TEST_NAME)
             FOLDER "${folder}"
         	POSITION_INDEPENDENT_CODE ON
     )
+
+    # On FreeBSD libcxxrt compares std::type_info by address and dladdr()
+    # only sees dynamic symbols, so export the test executable's symbols:
+    # testArchAbi compares RTTI with a plugin and testArchStackTrace looks
+    # up main() in its own stack trace.
+    if (CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+        set_target_properties(${TEST_NAME} PROPERTIES ENABLE_EXPORTS ON)
+    endif()
+
     target_include_directories(${TEST_NAME}
         PRIVATE $<TARGET_PROPERTY:${PXR_PACKAGE},INCLUDE_DIRECTORIES>
     )

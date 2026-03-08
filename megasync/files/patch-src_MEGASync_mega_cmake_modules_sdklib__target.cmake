--- src/MEGASync/mega/cmake/modules/sdklib_target.cmake.orig	2026-03-03 11:23:42 UTC
+++ src/MEGASync/mega/cmake/modules/sdklib_target.cmake
@@ -402,7 +402,7 @@ if((NOT (WIN32 OR APPLE OR ANDROID)) AND CMAKE_CXX_STA
 if((NOT (WIN32 OR APPLE OR ANDROID)) AND CMAKE_CXX_STANDARD LESS_EQUAL 17)
     # Needed for std::experimental::filesystem
     # Needed for c++17 and std::filesystem for some compilers. Not needed starting in gcc9, but harmless.
-    target_link_libraries(SDKlib PRIVATE stdc++fs)
+    #target_link_libraries(SDKlib PRIVATE stdc++fs)
 endif()
 
 if(ENABLE_DRIVE_NOTIFICATIONS)

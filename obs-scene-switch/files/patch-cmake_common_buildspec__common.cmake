--- cmake/common/buildspec_common.cmake.orig	2026-01-09 04:56:38 UTC
+++ cmake/common/buildspec_common.cmake
@@ -102,7 +102,7 @@ function(_setup_obs_studio)
   message(STATUS "Build ${label} (Release - ${arch})")
   execute_process(
     COMMAND "${CMAKE_COMMAND}" --build build_${arch} --target obs-frontend-api
-            --config Release --parallel
+            --parallel
     WORKING_DIRECTORY "${dependencies_dir}/${_obs_destination}"
     RESULT_VARIABLE _process_result COMMAND_ERROR_IS_FATAL ANY
     OUTPUT_QUIET)
@@ -117,7 +117,7 @@ function(_setup_obs_studio)
     OUTPUT_QUIET)
   execute_process(
     COMMAND "${CMAKE_COMMAND}" --install build_${arch} --component Development
-            --config Release --prefix "${dependencies_dir}"
+            --prefix "${dependencies_dir}"
     WORKING_DIRECTORY "${dependencies_dir}/${_obs_destination}"
     RESULT_VARIABLE _process_result COMMAND_ERROR_IS_FATAL ANY
     OUTPUT_QUIET)

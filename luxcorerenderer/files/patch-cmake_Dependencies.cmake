--- cmake/Dependencies.cmake.orig	2025-01-04 06:54:37 UTC
+++ cmake/Dependencies.cmake
@@ -96,8 +96,8 @@ set(Boost_USE_STATIC_RUNTIME    OFF)
 set(Boost_USE_RELEASE_LIBS      ON)   # only find release libs
 set(Boost_USE_MULTITHREADED     ON)
 set(Boost_USE_STATIC_RUNTIME    OFF)
-set(Boost_ROOT                  "${BOOST_SEARCH_PATH}")
-set(Boost_LIBRARYDIR 			"${BOOST_SEARCH_PATH}/lib")
+#set(Boost_ROOT                  "${BOOST_SEARCH_PATH}")
+#set(Boost_LIBRARYDIR 			"${BOOST_SEARCH_PATH}/lib")
 set(Boost_DEBUG					OFF)
 # set(Boost_NO_BOOST_CMAKE 		ON)
 set(Boost_MINIMUM_VERSION       "1.85.0") #1.56.0 1.85.0
@@ -125,7 +125,7 @@ if(Boost_FOUND)
 
 if(Boost_FOUND)
 	include_directories(BEFORE SYSTEM ${Boost_INCLUDE_DIRS})
-	link_directories(${Boost_LIBRARY_DIRS})
+	link_directories(${BOOST_LIBRARIES})
 	# Don't use old boost versions interfaces
 	add_definitions(-DBOOST_FILESYSTEM_NO_DEPRECATED)
 	if(Boost_USE_STATIC_LIBS)
@@ -134,6 +134,7 @@ endif()
 	endif()
 endif()
 
+if(LINUX)
 # Setup CUDA, necessary for optix
 # CudaToolkit
 set(CUDAToolkit_INCLUDE_DIRS ${CUDAToolkit_INCLUDE_DIRS})
@@ -162,6 +163,7 @@ message(STATUS "Optix libraries directory: ${OptiX_INS
 # Optix messages
 message(STATUS "Optix include directory: ${OptiX_INSTALL_DIR}/include")
 message(STATUS "Optix libraries directory: ${OptiX_INSTALL_DIR}/lib64")
+endif()
 
 # OpenGL
 # Set GLVND preference as legacy

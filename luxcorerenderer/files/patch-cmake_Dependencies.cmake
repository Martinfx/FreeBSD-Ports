--- cmake/Dependencies.cmake.orig	2025-01-04 06:54:37 UTC
+++ cmake/Dependencies.cmake
@@ -41,8 +41,11 @@ link_libraries(${JSONCPP_LIBRARIES})
 link_libraries(${JSONCPP_LIBRARIES})
 
 # spdlog and fmt
-find_package(spdlog CONFIG REQUIRED)
-find_package(fmt CONFIG REQUIRED)
+# broken spflog in FreeBSD
+#https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=258073
+#find_package(spdlog CONFIG REQUIRED)
+include_directories("${LuxRays_SOURCE_DIR}/deps/spdlog-1.13.0/include")
+#find_package(fmt CONFIG REQUIRED)
 
 # imgui
 # set(IMGUI_SOURCES
@@ -96,8 +99,8 @@ set(Boost_USE_STATIC_RUNTIME    OFF)
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
@@ -125,7 +128,7 @@ if(Boost_FOUND)
 
 if(Boost_FOUND)
 	include_directories(BEFORE SYSTEM ${Boost_INCLUDE_DIRS})
-	link_directories(${Boost_LIBRARY_DIRS})
+	link_directories(${BOOST_LIBRARIES})
 	# Don't use old boost versions interfaces
 	add_definitions(-DBOOST_FILESYSTEM_NO_DEPRECATED)
 	if(Boost_USE_STATIC_LIBS)
@@ -134,6 +137,7 @@ endif()
 	endif()
 endif()
 
+if(LINUX)
 # Setup CUDA, necessary for optix
 # CudaToolkit
 set(CUDAToolkit_INCLUDE_DIRS ${CUDAToolkit_INCLUDE_DIRS})
@@ -162,6 +166,7 @@ message(STATUS "Optix libraries directory: ${OptiX_INS
 # Optix messages
 message(STATUS "Optix include directory: ${OptiX_INSTALL_DIR}/include")
 message(STATUS "Optix libraries directory: ${OptiX_INSTALL_DIR}/lib64")
+endif()
 
 # OpenGL
 # Set GLVND preference as legacy
@@ -261,20 +266,8 @@ endif()
 	include_directories(BEFORE SYSTEM ${BLOSC_INCLUDE_PATH})
 endif()
 
-# OpenMP
-if(NOT APPLE)
-	find_package(OpenMP)
-	if(OPENMP_FOUND)
-		message(STATUS "OpenMP found - compiling with")
-   		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
-   		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
-	else()
-		message(WARNING "OpenMP not found - compiling without")
-	endif()
-endif()
-
 # Find GTK 3.0 for Linux only (required by luxcoreui NFD)
-if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
+if(${CMAKE_SYSTEM_NAME} MATCHES "Linux" OR ${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
 	find_package(PkgConfig REQUIRED)
 	pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
 	include_directories(${GTK3_INCLUDE_DIRS})

--- cmake/Dependencies.cmake.orig	2025-01-08 07:43:39 UTC
+++ cmake/Dependencies.cmake
@@ -41,8 +41,8 @@ find_package(PkgConfig REQUIRED)
 # link_libraries(${JSONCPP_LIBRARIES})
 
 # spdlog and fmt
-find_package(spdlog CONFIG REQUIRED)
-find_package(fmt CONFIG REQUIRED)
+#find_package(spdlog CONFIG REQUIRED)
+#find_package(fmt CONFIG REQUIRED)
 
 # imgui
 # set(IMGUI_SOURCES
@@ -63,6 +63,8 @@ find_package(fmt CONFIG REQUIRED)
 # message(STATUS "imgui_INCLUDE_PATH: ${IMGUI_INCLUDE_DIRS}")
 # message(STATUS "imgui_LIBRARIES: ${IMGUI_LIBRARIES}")
 
+include_directories("${LuxRays_SOURCE_DIR}/deps/spdlog-1.13.0/include")
+
 if(NOT APPLE)
     # Apple has these available hardcoded and matched in macos repo, see Config_OSX.cmake
     include_directories(BEFORE SYSTEM ${OpenEXR_INCLUDE_DIRS})
@@ -102,8 +104,8 @@ set(Boost_DEBUG					OFF)
 set(Boost_USE_STATIC_RUNTIME    OFF)
 set(Boost_DEBUG					OFF)
 # set(Boost_NO_BOOST_CMAKE 		ON)
-set(Boost_MINIMUM_VERSION       "1.85.0") #1.56.0 1.85.0
-set(Boost_VERSION       		"1.85.0")
+set(Boost_MINIMUM_VERSION       "1.86.0") #1.56.0 1.85.0
+set(Boost_VERSION       		"1.86.0")
 message(STATUS "Boost version: ${Boost_VERSION}")
 
 # For Windows builds, PYTHON_V must be defined as "3x" (x=Python minor version, e.g. "35")
@@ -142,7 +144,7 @@ endif()
 endif()
 
 # Setup CUDA, necessary for optix (CudaToolkit)
-option(ENABLE_CUDA "Enable the cuda build" ON)
+option(ENABLE_CUDA "Enable the cuda build" OFF)
 
 if(ENABLE_CUDA)
 	set(CUDAToolkit_INCLUDE_DIRS ${CUDAToolkit_INCLUDE_DIRS})
@@ -217,8 +219,8 @@ endif()
 endif()
 
 # OpencolorIO
-set(OpenColorIO_INCLUDE_DIR "/usr/include/OpenColorIO")
-set(OpenColorIO_LIBRARY "/usr/lib64/libOpenColorIO.so")
+set(OpenColorIO_INCLUDE_DIR "/usr/local/include/OpenColorIO")
+set(OpenColorIO_LIBRARY "/usr/local/lib/libOpenColorIO.so")
 find_package(OpenColorIO REQUIRED)
 include_directories(${OpenColorIO_INCLUDE_DIRS})
 
@@ -230,16 +232,16 @@ endif()
 endif()
 
 # OpênSubdiv
-set(osdCPU_PATH_DEFAULT "/usr/")
+set(osdCPU_PATH_DEFAULT "/usr/local")
 set(osdCPU_PATH "${osdCPU_PATH_DEFAULT}" CACHE PATH "/usr/")
 set(osdCPU_INCLUDE_DIRS ${osdCPU_PATH}/include)
-set(osdCPU_LIBRARY_DIRS ${osdCPU_PATH}/lib64)
+set(osdCPU_LIBRARY_DIRS ${osdCPU_PATH}/lib)
 set(osdCPU_LIBRARIES osdCPU)
 
 find_package(OpenSubdiv REQUIRED)
 # Rechercher les bibliothèques nécessaires
-find_library(OSD_CPU_LIBRARY osdCPU HINTS /usr/lib64)
-find_library(OSD_GPU_LIBRARY osdGPU HINTS /usr/lib64)
+find_library(OSD_CPU_LIBRARY osdCPU HINTS /usr/local/lib)
+find_library(OSD_GPU_LIBRARY osdGPU HINTS /usr/local/lib)
 
 # Vérifier si elles ont été trouvées
 if (NOT OSD_CPU_LIBRARY)
@@ -285,6 +287,15 @@ message(STATUS "Using C++ compiler: ${CMAKE_CXX_COMPIL
 # Show the version of C++
 message(STATUS "Using C++ compiler: ${CMAKE_CXX_COMPILER}")
 
+# Specified th standard du C++ version
+set(CMAKE_CXX_STANDARD 17) # 17 by default
+set(CMAKE_CXX_STANDARD_REQUIRED ON)
+set(CMAKE_CXX_EXTENSIONS OFF)
+set(GENERATED_DIR "${CMAKE_BINARY_DIR}/generated")
+set(GENERATED_INCLUDE_DIR "${GENERATED_DIR}/include")
+# Show the version of C++
+message(STATUS "Using C++ compiler: ${CMAKE_CXX_COMPILER}")
+
 # OpenMP
 if(NOT APPLE)
 	find_package(OpenMP)
@@ -298,7 +309,7 @@ endif()
 endif()
 
 # Find GTK 3.0 for Linux only (required by luxcoreui NFD)
-if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
+if(${CMAKE_SYSTEM_NAME} MATCHES "Linux" OR ${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
 	find_package(PkgConfig REQUIRED)
 	pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
 	include_directories(${GTK3_INCLUDE_DIRS})

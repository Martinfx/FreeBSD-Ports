--- cmake/Dependencies.cmake.orig	2025-01-04 06:54:37 UTC
+++ cmake/Dependencies.cmake
@@ -41,8 +41,8 @@ link_libraries(${JSONCPP_LIBRARIES})
 link_libraries(${JSONCPP_LIBRARIES})
 
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
@@ -72,7 +74,7 @@ if(NOT APPLE)
     include_directories(BEFORE SYSTEM ${JPEG_INCLUDE_DIR})
     find_package(PNG REQUIRED)
     include_directories(BEFORE SYSTEM ${PNG_PNG_INCLUDE_DIR})
-	find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
+	find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
 	include_directories(${Python3_INCLUDE_DIRS})
 endif()
 
@@ -87,8 +89,12 @@ endif()
 #     PATHS "/usr/bin" "/usr/local/bin" "/usr/lib64/qt6/libexec/uic" "/usr/include/PySide6/QtUiTools"
 # )
 
-find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
+set(Python3_ROOT_DIR "${Python3_ROOT_DIR}")
+find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
 include_directories(${Python3_INCLUDE_DIRS})
+link_directories(${Python3_LIBRARIES})
+message(STATUS "Python include dirs: ${Python3_INCLUDE_DIRS}")
+message(STATUS "Python libraries: ${Python3_LIBRARIES}")
 
 # Find Boost
 set(Boost_USE_STATIC_LIBS       OFF)
@@ -96,37 +102,41 @@ set(Boost_USE_STATIC_RUNTIME    OFF)
 set(Boost_USE_RELEASE_LIBS      ON)   # only find release libs
 set(Boost_USE_MULTITHREADED     ON)
 set(Boost_USE_STATIC_RUNTIME    OFF)
-set(Boost_ROOT                  "${BOOST_SEARCH_PATH}")
-set(Boost_LIBRARYDIR 			"${BOOST_SEARCH_PATH}/lib")
 set(Boost_DEBUG					OFF)
 # set(Boost_NO_BOOST_CMAKE 		ON)
-set(Boost_MINIMUM_VERSION       "1.85.0") #1.56.0 1.85.0
-set(Boost_VERSION       		"1.85.0")
+set(Boost_MINIMUM_VERSION       "1.86.0") #1.56.0 1.85.0
+set(Boost_VERSION       		"1.86.0")
 message(STATUS "Boost version: ${Boost_VERSION}")
 
 # For Windows builds, PYTHON_V must be defined as "3x" (x=Python minor version, e.g. "35")
 # For other platforms, specifying python minor version is not needed
-set(LUXRAYS_BOOST_COMPONENTS thread program_options filesystem serialization iostreams regex system python${PYTHON_V} chrono serialization numpy${PYTHON_V})
-
+set (PYTHON_V "311")
+set(LUXRAYS_BOOST_COMPONENTS thread program_options filesystem serialization iostreams regex system python${PYTHON_V} chrono serialization )
+#  ${Python_LIBRARY_DIRS}
 find_package(Boost ${Boost_VERSION} REQUIRED COMPONENTS ${LUXRAYS_BOOST_COMPONENTS})
 if(NOT Boost_FOUND)
-		message(FATAL_ERROR "Boost not found!")
-        # Try again with the other type of libs
-        if(Boost_USE_STATIC_LIBS)
-                set(Boost_USE_STATIC_LIBS OFF)
-        else()
-                set(Boost_USE_STATIC_LIBS ON)
-        endif()
-        # The following line is necessary with CMake 3.18.0 to find static libs on Windows
-        unset(Boost_LIB_PREFIX)
-		message(STATUS "Re-trying with link static = ${Boost_USE_STATIC_LIBS}")
-        find_package(Boost ${Boost_MINIMUM_VERSION} REQUIRED COMPONENTS ${LUXRAYS_BOOST_COMPONENTS})
+	message(FATAL_ERROR "Boost not found!")
+	# Try again with the other type of libs
+	if(Boost_USE_STATIC_LIBS)
+			set(Boost_USE_STATIC_LIBS OFF)
+	else()
+			set(Boost_USE_STATIC_LIBS ON)
+	endif()
+	# The following line is necessary with CMake 3.18.0 to find static libs on Windows
+	unset(Boost_LIB_PREFIX)
+	message(STATUS "Re-trying with link static = ${Boost_USE_STATIC_LIBS}")
+	find_package(Boost ${Boost_MINIMUM_VERSION} REQUIRED COMPONENTS ${LUXRAYS_BOOST_COMPONENTS})
 endif()
 
 if(Boost_FOUND)
 	include_directories(BEFORE SYSTEM ${Boost_INCLUDE_DIRS})
+	set(Boost_ROOT "/usr/include/boost")
+	set(Boost_LIBRARYDIR "/usr/local/lib")
+	include_directories(${Boost_INCLUDE_DIRS})
 	link_directories(${Boost_LIBRARY_DIRS})
-	# Don't use old boost versions interfaces
+	message(STATUS "Boost Lib: ${BOOST_LIBRARYDIR}")
+
+	# Don't use old boost versions interfac
 	add_definitions(-DBOOST_FILESYSTEM_NO_DEPRECATED)
 	if(Boost_USE_STATIC_LIBS)
 		add_definitions(-DBOOST_STATIC_LIB)
@@ -134,35 +144,43 @@ endif()
 	endif()
 endif()
 
-# Setup CUDA, necessary for optix
-# CudaToolkit
-set(CUDAToolkit_INCLUDE_DIRS ${CUDAToolkit_INCLUDE_DIRS})
-set(CUDAToolkit_LIBRARY_ROOT ${CUDAToolkit_LIBRARY_ROOT}/targets/x86_64-linux/lib/)
+# Setup CUDA, necessary for optix (CudaToolkit)
+option(ENABLE_CUDA "Enable the cuda build" OFF)
 
-# Optionnal : CUDA runtime standard activated
-set(CMAKE_CUDA_STANDARD 12)
-set(CMAKE_CUDA_STANDARD_REQUIRED ON)
+if(ENABLE_CUDA)
+	set(CUDAToolkit_INCLUDE_DIRS ${CUDAToolkit_INCLUDE_DIRS})
+	set(CUDAToolkit_LIBRARY_ROOT ${CUDAToolkit_LIBRARY_ROOT}/targets/x86_64-linux/lib/)
 
-find_package(CUDAToolkit REQUIRED)
-include_directories(${CUDAToolkit_INCLUDE_DIRS})
+	# Optionnal : CUDA runtime standard activated
+	set(CMAKE_CUDA_STANDARD 12)
+	set(CMAKE_CUDA_STANDARD_REQUIRED ON)
 
-# CUDA messages
-message(STATUS "CUDA version: ${CUDAToolkit_VERSION}")
-message(STATUS "CUDA Include directory: ${CUDAToolkit_INCLUDE_DIRS}")
-message(STATUS "CUDA Libraries directory: ${CUDAToolkit_LIBRARY_ROOT}/targets/x86_64-linux/lib/")
-# message(STATUS "CMAKE_CUDA_COMPILER=${CMAKE_CUDA_COMPILER}")
+	find_package(CUDAToolkit REQUIRED)
+	include_directories(${CUDAToolkit_INCLUDE_DIRS})
 
-# OptiX
-# setup optix as an alternative to vulkan
-set(OPTIX_DIR "/opt/optix")
-set(OptiX_INSTALL_DIR "/opt/optix")
-include_directories(${OptiX_INSTALL_DIR}/include)
-link_directories(${OptiX_INSTALL_DIR}/lib64)
+	# CUDA messages
+	message(STATUS "CUDA version: ${CUDAToolkit_VERSION}")
+	message(STATUS "CUDA Include directory: ${CUDAToolkit_INCLUDE_DIRS}")
+	message(STATUS "CUDA Libraries directory: ${CUDAToolkit_LIBRARY_ROOT}/targets/x86_64-linux/lib/")
+	# message(STATUS "CMAKE_CUDA_COMPILER=${CMAKE_CUDA_COMPILER}")
 
-# Optix messages
-message(STATUS "Optix include directory: ${OptiX_INSTALL_DIR}/include")
-message(STATUS "Optix libraries directory: ${OptiX_INSTALL_DIR}/lib64")
+	# OptiX - setup as an alternative to vulkan
+	# find_package(OptiX REQUIRED)
+	set(OPTIX_DIR "/opt/optix")
+	set(OptiX_INSTALL_DIR "/opt/optix")
+	include_directories(${OptiX_INSTALL_DIR}/include)
+	link_directories(${OptiX_INSTALL_DIR}/lib64)
 
+	# Optix messages
+	message(STATUS "OptixDir: ${OPTIX_DIR}")
+	message(STATUS "Optix include directory: ${OptiX_INSTALL_DIR}/include")
+	message(STATUS "Optix libraries directory: ${OptiX_INSTALL_DIR}/lib64")
+endif()
+
+# OpenCL
+# find_package(OpenCL 1.2 EXACT REQUIRED)
+find_package(OpenCL REQUIRED)
+
 # OpenGL
 # Set GLVND preference as legacy
 set(OpenGL_GL_PREFERENCE GLVND)
@@ -202,16 +220,16 @@ endif()
 endif()
 
 # OpencolorIO
-set(OpenColorIO_ROOT		"${OpenColorIO_SEARCH_PATH}")
-set(OpenColorIO_LIBRARY		"${OpenColorIO_LIBRARY_DIR}")
-set(OpenColorIO_INCLUDE_DIR	"${OpenColorIO_INCLUDE_DIR}")
+set(OpenColorIO_INCLUDE_DIR "/usr/local/include/OpenColorIO")
+set(OpenColorIO_LIBRARY "/usr/local/lib/libOpenColorIO.so")
 find_package(OpenColorIO REQUIRED)
-find_library(OpenColorIO_LIBRARY NAMES OpenColorIO)
+include_directories(${OpenColorIO_INCLUDE_DIRS})
 
 if(OpenColorIO_FOUND)
-    message(STATUS "Found OpenColorIO: ${OpenColorIO_VERSION}")
+	message(STATUS "Found OpenColorIO: ${OpenColorIO_VERSION}")
+	message(STATUS "Found OpenColorIO include: ${OpenColorIO_INCLUDE_DIR}")
 else()
-    message(FATAL_ERROR "OpenColorIO not found.")
+	message(FATAL_ERROR "OpenColorIO not found.")
 endif()
 
 # OpênSubdiv
@@ -239,7 +257,7 @@ endif()
 # link_directories(${osdCPU_LIBRARY_DIRS})
 
 # Brut force lopencolorio lopensubdiv (-libosdCPU -libosdGPU)
-set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lOpenColorIO -lpython3.12")
+set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
 
 # GLFW
 set(GLFW_DIR "${glfw3_SEARCH_PATH}")
@@ -260,6 +278,15 @@ endif()
 if(BLOSC_FOUND)
 	include_directories(BEFORE SYSTEM ${BLOSC_INCLUDE_PATH})
 endif()
+
+# Specified th standard du C++ version
+set(CMAKE_CXX_STANDARD 17) # 17 by default
+set(CMAKE_CXX_STANDARD_REQUIRED ON)
+set(CMAKE_CXX_EXTENSIONS OFF)
+set(GENERATED_DIR "${CMAKE_BINARY_DIR}/generated")
+set(GENERATED_INCLUDE_DIR "${GENERATED_DIR}/include")
+# Show the version of C++
+message(STATUS "Using C++ compiler: ${CMAKE_CXX_COMPILER}")
 
 # OpenMP
 if(NOT APPLE)

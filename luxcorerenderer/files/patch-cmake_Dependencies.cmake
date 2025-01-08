--- cmake/Dependencies.cmake.orig	2025-01-08 07:43:39 UTC
+++ cmake/Dependencies.cmake
@@ -103,12 +103,13 @@ set(Boost_MINIMUM_VERSION       "1.85.0") #1.56.0 1.85
 set(Boost_DEBUG					OFF)
 # set(Boost_NO_BOOST_CMAKE 		ON)
 set(Boost_MINIMUM_VERSION       "1.85.0") #1.56.0 1.85.0
-set(Boost_VERSION       		"1.85.0")
+set(Boost_VERSION       		"1.86.0")
 message(STATUS "Boost version: ${Boost_VERSION}")
 
 # For Windows builds, PYTHON_V must be defined as "3x" (x=Python minor version, e.g. "35")
 # For other platforms, specifying python minor version is not needed
-set(LUXRAYS_BOOST_COMPONENTS thread program_options filesystem serialization iostreams regex system python${PYTHON_V} chrono serialization numpy${PYTHON_V})
+set (PYTHON_V "311")
+set(LUXRAYS_BOOST_COMPONENTS thread program_options filesystem serialization iostreams regex system python${PYTHON_V} chrono serialization )
 #  ${Python_LIBRARY_DIRS}
 find_package(Boost ${Boost_VERSION} REQUIRED COMPONENTS ${LUXRAYS_BOOST_COMPONENTS})
 if(NOT Boost_FOUND)
@@ -218,7 +219,7 @@ set(OpenColorIO_INCLUDE_DIR "/usr/include/OpenColorIO"
 
 # OpencolorIO
 set(OpenColorIO_INCLUDE_DIR "/usr/include/OpenColorIO")
-set(OpenColorIO_LIBRARY "/usr/lib64/libOpenColorIO.so")
+set(OpenColorIO_LIBRARY "/usr/local/lib/libOpenColorIO.so")
 find_package(OpenColorIO REQUIRED)
 include_directories(${OpenColorIO_INCLUDE_DIRS})
 

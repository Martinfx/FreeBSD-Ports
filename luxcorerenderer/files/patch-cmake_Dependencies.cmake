--- cmake/Dependencies.cmake.orig	2025-01-04 06:54:37 UTC
+++ cmake/Dependencies.cmake
@@ -98,6 +98,7 @@ set(Boost_LIBRARYDIR 			"${BOOST_SEARCH_PATH}/lib")
 set(Boost_USE_STATIC_RUNTIME    OFF)
 set(Boost_ROOT                  "${BOOST_SEARCH_PATH}")
 set(Boost_LIBRARYDIR 			"${BOOST_SEARCH_PATH}/lib")
+message(STATUS "Boost LIB DIR: ${Boost_LIBRARYDIR}") 
 set(Boost_DEBUG					OFF)
 # set(Boost_NO_BOOST_CMAKE 		ON)
 set(Boost_MINIMUM_VERSION       "1.85.0") #1.56.0 1.85.0
@@ -125,7 +126,7 @@ if(Boost_FOUND)
 
 if(Boost_FOUND)
 	include_directories(BEFORE SYSTEM ${Boost_INCLUDE_DIRS})
-	link_directories(${Boost_LIBRARY_DIRS})
+	link_directories(${BOOST_LIBRARIES})
 	# Don't use old boost versions interfaces
 	add_definitions(-DBOOST_FILESYSTEM_NO_DEPRECATED)
 	if(Boost_USE_STATIC_LIBS)

--- src/IECore/IndexedIOAlgo.cpp.orig	2024-12-04 14:54:31 UTC
+++ src/IECore/IndexedIOAlgo.cpp
@@ -228,7 +228,7 @@ void recursiveCopy( const IndexedIO *src, IndexedIO *d
 }
 
 //! Task for traversing all files in parallel. New tasks are spawned for each directory
-template<template<typename, typename> class FileHandler, typename FileCallback>
+/*template<template<typename, typename> class FileHandler, typename FileCallback>
 class FileTask : public tbb::task
 {
 
@@ -279,7 +279,7 @@ class FileTask : public tbb::task
 	private :
 		const IndexedIO *m_src;
 		FileCallback &m_fileCallback;
-};
+};*/
 
 } // namespace
 
@@ -292,7 +292,7 @@ void copy( const IndexedIO *src, IndexedIO *dst )
 {
 	::recursiveCopy( src, dst );
 }
-
+/*
 FileStats<size_t> parallelReadAll( const IndexedIO *src )
 {
 	FileStats<std::atomic<size_t> > fileStats;
@@ -307,6 +307,6 @@ FileStats<size_t> parallelReadAll( const IndexedIO *sr
 	tbb::task::spawn_root_and_wait( *task );
 	return fileStats;
 }
-
+*/
 } // IndexedIOAlgo
 } // IECore

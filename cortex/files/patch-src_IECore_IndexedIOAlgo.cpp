--- src/IECore/IndexedIOAlgo.cpp.orig	2025-02-25 10:37:21 UTC
+++ src/IECore/IndexedIOAlgo.cpp
@@ -228,6 +228,7 @@ void recursiveCopy( const IndexedIO *src, IndexedIO *d
 }
 
 //! Task for traversing all files in parallel. New tasks are spawned for each directory
+/*
 template<template<typename, typename> class FileHandler, typename FileCallback>
 class FileTask : public tbb::task
 {
@@ -280,6 +281,7 @@ class FileTask : public tbb::task
 		const IndexedIO *m_src;
 		FileCallback &m_fileCallback;
 };
+*/
 
 } // namespace
 
@@ -293,6 +295,7 @@ void copy( const IndexedIO *src, IndexedIO *dst )
 	::recursiveCopy( src, dst );
 }
 
+/*
 FileStats<size_t> parallelReadAll( const IndexedIO *src )
 {
 	FileStats<std::atomic<size_t> > fileStats;
@@ -308,5 +311,6 @@ FileStats<size_t> parallelReadAll( const IndexedIO *sr
 	return fileStats;
 }
 
+*/
 } // IndexedIOAlgo
 } // IECore

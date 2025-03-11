--- src/IECore/IndexedIOAlgo.cpp.orig	2025-02-25 10:37:21 UTC
+++ src/IECore/IndexedIOAlgo.cpp
@@ -33,9 +33,7 @@
 //////////////////////////////////////////////////////////////////////////
 
 #include "IECore/IndexedIOAlgo.h"
-
-#include "tbb/task.h"
-
+#include <oneapi/tbb/task_group.h>
 #include <atomic>
 
 using namespace IECore;
@@ -229,56 +227,45 @@ template<template<typename, typename> class FileHandle
 
 //! Task for traversing all files in parallel. New tasks are spawned for each directory
 template<template<typename, typename> class FileHandler, typename FileCallback>
-class FileTask : public tbb::task
+class FileTask
 {
+public:
+    FileTask(const IndexedIO* src, FileCallback& fileCallback)
+        : m_src(src), m_fileCallback(fileCallback)
+    {
+    }
 
-	public :
+    void operator()() const
+    {
+        IndexedIO::EntryIDList fileNames;
+        m_src->entryIds(fileNames, IndexedIO::EntryType::File);
 
-		FileTask( const IndexedIO *src, FileCallback &fileCallback )
-		: m_src( src ), m_fileCallback( fileCallback )
-		{
-		}
+        for (const auto& fileName : fileNames)
+        {
+            handleFile<FileHandler, FileCallback>(m_src, nullptr, fileName, m_fileCallback);
+        }
 
-		~FileTask() override
-		{
-		}
+        IndexedIO::EntryIDList directoryNames;
+        m_src->entryIds(directoryNames, IndexedIO::EntryType::Directory);
 
-		task *execute() override
-		{
-			IndexedIO::EntryIDList fileNames;
-			m_src->entryIds( fileNames, IndexedIO::EntryType::File );
+        std::vector<ConstIndexedIOPtr> childDirectories;
+        childDirectories.reserve(directoryNames.size());
+        for (const auto& directoryName : directoryNames)
+        {
+            childDirectories.push_back(m_src->subdirectory(directoryName, IndexedIO::ThrowIfMissing));
+        }
 
-			for( const auto &fileName : fileNames )
-			{
-				handleFile<FileHandler, FileCallback>( m_src, nullptr, fileName, m_fileCallback );
-			}
+        oneapi::tbb::task_group tg;
+        for (const auto& childDirectory : childDirectories)
+        {
+            tg.run(FileTask(childDirectory.get(), m_fileCallback));
+        }
+        tg.wait();
+    }
 
-			IndexedIO::EntryIDList directoryNames;
-			m_src->entryIds( directoryNames, IndexedIO::EntryType::Directory );
-
-			set_ref_count( 1 + directoryNames.size() );
-
-			std::vector<ConstIndexedIOPtr> childDirectories;
-			childDirectories.reserve(directoryNames.size());
-			for( const auto &directoryName : directoryNames )
-			{
-				childDirectories.push_back( m_src->subdirectory( directoryName, IndexedIO::ThrowIfMissing ) );
-			}
-
-			for( const auto &childDirectory : childDirectories )
-			{
-				FileTask *t = new( allocate_child() ) FileTask( childDirectory.get() , m_fileCallback );
-				spawn( *t );
-			}
-
-			wait_for_all();
-
-			return nullptr;
-		}
-
-	private :
-		const IndexedIO *m_src;
-		FileCallback &m_fileCallback;
+private:
+    const IndexedIO* m_src;
+    FileCallback& m_fileCallback;
 };
 
 } // namespace
@@ -293,19 +280,23 @@ void copy( const IndexedIO *src, IndexedIO *dst )
 	::recursiveCopy( src, dst );
 }
 
-FileStats<size_t> parallelReadAll( const IndexedIO *src )
+FileStats<size_t> parallelReadAll(const IndexedIO* src)
 {
-	FileStats<std::atomic<size_t> > fileStats;
+    FileStats<std::atomic<size_t>> fileStats;
 
-	auto fileCallback = [&fileStats]( size_t numBytes )
-	{
-		fileStats.addBlock( numBytes );
-	};
+    auto fileCallback = [&fileStats](size_t numBytes)
+    {
+        fileStats.addBlock(numBytes);
+    };
 
-	tbb::task_group_context taskGroupContext( tbb::task_group_context::isolated );
-	FileTask<Reader, decltype( fileCallback )> *task = new( tbb::task::allocate_root( taskGroupContext ) ) FileTask<Reader, decltype( fileCallback )>( src, fileCallback );
-	tbb::task::spawn_root_and_wait( *task );
-	return fileStats;
+    oneapi::tbb::task_group tg;
+    tg.run([src, &fileCallback, &tg]()
+    {
+        processFiles<Reader, decltype(fileCallback)>(src, fileCallback, tg);
+    });
+    tg.wait();
+
+    return fileStats;
 }
 
 } // IndexedIOAlgo

fmt 11 and later only quote std::filesystem::path when asked to with the
`?` format specifier, which the messages below were written to expect.

--- src/Gaffer/DataStore.cpp.orig	2026-09-24 19:41:12 UTC
+++ src/Gaffer/DataStore.cpp
@@ -243,7 +243,7 @@ public:
 					"either this file was written by another Gaffer process which is still open ( you should "
 					"close it before trying to save here to avoid possible data loss ), or the previous Gaffer "
 					"to write this file crashed without cleaning up ( In this case, you should "
-					"manually delete the recycle bin folder {} )",
+					"manually delete the recycle bin folder {:?} )",
 					m_recycleBinDirectory
 				) );
 			}
@@ -579,7 +579,7 @@ void DataStore::compute( ValuePlug *outp
 				if( !sourcePath )
 				{
 					throw IECore::Exception( fmt::format(
-						"Could not locate data store file {} in {}.", dataStoreFileName, m_sourceDirectory->dataStoreDirectory()
+						"Could not locate data store file {} in {:?}.", dataStoreFileName, m_sourceDirectory->dataStoreDirectory()
 					) );
 				}
 
@@ -756,7 +756,7 @@ void DataStore::save( const std::filesys
 			{
 				if( !warning.size() )
 				{
-					warning = fmt::format( "During saving, could not create hardlink at {} pointing to {}, falling back to copying file.", destPath, *sourcePath );
+					warning = fmt::format( "During saving, could not create hardlink at {:?} pointing to {:?}, falling back to copying file.", destPath, *sourcePath );
 				}
 
 				// If that failed, just copy.
@@ -768,7 +768,7 @@ void DataStore::save( const std::filesys
 			// This value does not yet exist on disk, and we need to write it.
 			if( !entry.m_liveValue )
 			{
-				throw IECore::Exception( fmt::format( "Unable to save entry \"{}\" on \"{}\" - no live value, but cannot find on disk in directory {}.", key, fullName(), m_sourceDirectory->dataStoreDirectory() ) );
+				throw IECore::Exception( fmt::format( "Unable to save entry \"{}\" on \"{}\" - no live value, but cannot find on disk in directory {:?}.", key, fullName(), m_sourceDirectory->dataStoreDirectory() ) );
 			}
 
 			// I can't think why the writer would modify the source, I assume this old Cortex stuff just isn't
@@ -856,7 +856,7 @@ void DataStore::finaliseDirectory( const
 				{
 					IECore::msg(
 						IECore::Msg::Warning, "Serialisation",
-						fmt::format( "Unexpected file {} in data store directory {}.",
+						fmt::format( "Unexpected file {:?} in data store directory {:?}.",
 							directoryEntry.path().filename(), dataStoreDirectory
 						)
 					);

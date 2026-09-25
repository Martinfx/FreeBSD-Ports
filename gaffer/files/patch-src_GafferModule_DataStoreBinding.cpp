fmt 11 and later only quote std::filesystem::path when asked to with the
`?` format specifier. Unquoted, the path makes the serialisation used to
copy and paste DataStore nodes invalid Python.

--- src/GafferModule/DataStoreBinding.cpp.orig	2026-09-24 19:41:12 UTC
+++ src/GafferModule/DataStoreBinding.cpp
@@ -187,7 +187,7 @@ class DataStoreSerialiser : public NodeS
 			}
 
 			mySerial = fmt::format(
-				"{}._loadEntries( {}, {} )\n", identifier, entriesRepr,
+				"{}._loadEntries( {}, {:?} )\n", identifier, entriesRepr,
 				std::filesystem::path( scriptNode->fileNamePlug()->getValue() )
 			);
 		}

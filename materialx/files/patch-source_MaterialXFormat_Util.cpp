--- source/MaterialXFormat/Util.cpp.orig	2025-09-15 18:12:11 UTC
+++ source/MaterialXFormat/Util.cpp
@@ -259,6 +259,14 @@ FileSearchPath getDefaultDataSearchPath(
         }
         currentPath = currentPath.getParentPath();
     }
+
+    // FreeBSD: the data libraries and resources are installed in
+    // %%PREFIX%%/share/MaterialX, and not with the executables.
+    const FilePath INSTALLED_DATA_PATH("%%PREFIX%%/share/MaterialX");
+    if (searchPath.isEmpty() && (INSTALLED_DATA_PATH / REQUIRED_LIBRARY_FOLDER).exists())
+    {
+        searchPath.append(INSTALLED_DATA_PATH);
+    }
     return searchPath;
 }
 

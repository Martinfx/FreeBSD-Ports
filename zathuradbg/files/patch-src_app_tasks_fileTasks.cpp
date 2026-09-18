--- src/app/tasks/fileTasks.cpp.orig	2025-07-27 13:05:18 UTC
+++ src/app/tasks/fileTasks.cpp
@@ -108,7 +108,7 @@ bool serializeState()
         return false;
     }
 
-    const char* fileName = tinyfd_saveFileDialog("Select a file to serialize into", NULL, NULL, NULL, NULL);
+    const char* fileName = tinyfd_saveFileDialog("Select a file to serialize into", nullptr, 0, nullptr, nullptr);
     if (!fileName)
     {
         LOG_ERROR("No file selected...");
@@ -135,7 +135,7 @@ bool deserializeState()
         startDebugging();
     }
 
-    const char* fileName = tinyfd_openFileDialog("Select file to deserialize", NULL, NULL, NULL, NULL, NULL);
+    const char* fileName = tinyfd_openFileDialog("Select file to deserialize", nullptr, 0, nullptr, nullptr, 0);
     if (fileName == NULL)
     {
         LOG_INFO("No file selected. Stopping debugging...");
@@ -156,4 +156,4 @@ bool deserializeState()
     LOG_INFO("Successfully deserialized from file " << fileName);
     safeHighlightLine(addressLineNoMap[icicle_get_pc(icicle)]);
     return true;
-}
\ No newline at end of file
+}

--- qtlauncher/src/common/versions.cpp.orig	2026-10-02 19:05:42 UTC
+++ qtlauncher/src/common/versions.cpp
@@ -67,6 +67,22 @@
         versions.push_back(std::move(v));
     }
 
+#ifdef SHADPS4_SYSTEM_EXECUTABLE
+    // Always offer the emulator installed by the package manager.
+    if (std::filesystem::exists(SHADPS4_SYSTEM_EXECUTABLE) &&
+        std::none_of(versions.begin(), versions.end(),
+                     [](const Version& v) { return v.path == SHADPS4_SYSTEM_EXECUTABLE; })) {
+        versions.push_back(Version{
+            .name = "shadPS4 (system)",
+            .path = SHADPS4_SYSTEM_EXECUTABLE,
+            .date = "",
+            .codename = "",
+            .type = VersionType::Custom,
+            .id = id++,
+        });
+    }
+#endif
+
     // Sort by id just for consistent ordering
     std::sort(versions.begin(), versions.end(),
               [](const Version& a, const Version& b) { return a.id < b.id; });

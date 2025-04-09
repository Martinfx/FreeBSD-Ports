--- src/common/logging/backend.cpp.orig	2025-03-27 20:40:40 UTC
+++ src/common/logging/backend.cpp
@@ -154,7 +154,9 @@ class Impl { (public)
     }
 
     static void Stop() {
-        instance->StopBackendThread();
+        if (instance != nullptr) {
+        	instance->StopBackendThread();
+        }
     }
 
     Impl(const Impl&) = delete;

--- src/lib/utility/Platform.h.orig	2025-09-10 13:58:36 UTC
+++ src/lib/utility/Platform.h
@@ -25,6 +25,11 @@ class Platform final
 			return BOOST_OS_MACOS;
 		}
 
+		static constexpr bool isBSD()
+                {
+                        return BOOST_OS_BSD_FREE;
+                }
+
 		static std::string getName();
 
 		enum class Architecture

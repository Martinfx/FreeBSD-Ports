--- src/GafferSceneUI/Inspector.cpp.orig	2025-10-24 22:57:40 UTC
+++ src/GafferSceneUI/Inspector.cpp
@@ -336,7 +336,7 @@ Inspector::ResultPtr Inspector::inspect() const
 		}
 
 		result->m_editors = {
-			fmt::format( formatString, "edit" ), "", fmt::format( formatString, "disable" ), nullptr, nullptr
+			fmt::format(fmt::runtime(formatString), "edit" ), "", fmt::format(fmt::runtime(formatString), "disable" ), nullptr, nullptr
 		};
 	}
 

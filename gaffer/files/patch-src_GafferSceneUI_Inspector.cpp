--- src/GafferSceneUI/Inspector.cpp.orig	2025-03-03 10:18:09 UTC
+++ src/GafferSceneUI/Inspector.cpp
@@ -322,7 +322,7 @@ Inspector::ResultPtr Inspector::inspect() const
 		}
 
 		result->m_editors = {
-			fmt::format( formatString, "edit" ), "", fmt::format( formatString, "disable" ), nullptr, nullptr
+			fmt::format(fmt::runtime(formatString), "edit" ), "", fmt::format(fmt::runtime(formatString), "disable" ), nullptr, nullptr
 		};
 	}
 

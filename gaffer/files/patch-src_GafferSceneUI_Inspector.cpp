--- src/GafferSceneUI/Inspector.cpp.orig	2026-01-06 23:37:17 UTC
+++ src/GafferSceneUI/Inspector.cpp
@@ -344,7 +344,7 @@ Inspector::ResultPtr Inspector::inspect() const
 		}
 
 		result->m_editors = {
-			fmt::format( formatString, "edit" ), "", fmt::format( formatString, "disable" ), nullptr, nullptr
+			fmt::format(fmt::runtime(formatString), "edit" ), "", fmt::format(fmt::runtime(formatString), "disable" ), nullptr, nullptr
 		};
 	}
 

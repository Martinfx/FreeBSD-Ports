--- src/GafferSceneUI/Inspector.cpp.orig	2026-05-27 19:02:41 UTC
+++ src/GafferSceneUI/Inspector.cpp
@@ -359,7 +359,7 @@ Inspector::ResultPtr Inspector::inspect() const
 		}
 
 		result->m_editors = {
-			fmt::format( formatString, "edit" ), "", fmt::format( formatString, "disable" ), nullptr, nullptr
+			fmt::format(fmt::runtime(formatString), "edit" ), "", fmt::format(fmt::runtime(formatString), "disable" ), nullptr, nullptr
 		};
 	}
 

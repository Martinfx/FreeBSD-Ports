--- src/Gaffer/TweakPlug.cpp.orig	2026-05-27 19:02:41 UTC
+++ src/Gaffer/TweakPlug.cpp
@@ -58,6 +58,7 @@ using namespace Gaffer;
 using namespace IECore;
 using namespace Gaffer;
 
+
 //////////////////////////////////////////////////////////////////////////
 // Internal utilities
 //////////////////////////////////////////////////////////////////////////
@@ -142,7 +143,7 @@ T applyNumericTweak(
 					)
 				);
 			default:
-				throw IECore::Exception( fmt::format( "Not a valid tweak mode: {}.", mode ) );
+				throw IECore::Exception( fmt::format( "Not a valid tweak mode: {}.",TweakPlug::modeToString(mode) ) );
 		}
 	}
 	else

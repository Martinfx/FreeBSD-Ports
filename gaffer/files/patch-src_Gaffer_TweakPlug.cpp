--- src/Gaffer/TweakPlug.cpp.orig	2025-10-24 22:57:40 UTC
+++ src/Gaffer/TweakPlug.cpp
@@ -57,6 +57,7 @@ using namespace Gaffer;
 using namespace IECore;
 using namespace Gaffer;
 
+
 //////////////////////////////////////////////////////////////////////////
 // Internal utilities
 //////////////////////////////////////////////////////////////////////////
@@ -139,7 +140,7 @@ T applyNumericTweak(
 					)
 				);
 			default:
-				throw IECore::Exception( fmt::format( "Not a valid tweak mode: {}.", mode ) );
+				throw IECore::Exception( fmt::format( "Not a valid tweak mode: {}.",TweakPlug::modeToString(mode) ) );
 		}
 	}
 	else

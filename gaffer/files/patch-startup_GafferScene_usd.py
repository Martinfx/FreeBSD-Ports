--- startup/GafferScene/usd.py.orig	2026-09-24 19:41:12 UTC
+++ startup/GafferScene/usd.py
@@ -39,7 +39,9 @@ import os
 import IECore
 
 moduleSearchPath = IECore.SearchPath( os.environ["PYTHONPATH"] )
-if moduleSearchPath.find( "IECoreUSD" ) and moduleSearchPath.find( "pxr/Usd" ) :
+# On FreeBSD, IECoreUSD can be imported even if USD was built without
+# Python support, so we don't require the `pxr` module to be available.
+if moduleSearchPath.find( "IECoreUSD" ) :
 
 	# Import IECoreUSD so that we get the USD SceneInterface registered,
 	# providing USD functionality to both the SceneReader and SceneWriter.

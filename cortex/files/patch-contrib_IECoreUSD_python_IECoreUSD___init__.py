--- contrib/IECoreUSD/python/IECoreUSD/__init__.py.orig	2026-09-10 21:49:58 UTC
+++ contrib/IECoreUSD/python/IECoreUSD/__init__.py
@@ -36,9 +36,14 @@
 # we get a weird exception when we later load the pxr modules. We're not
 # 100% sure why this is happening, but importing them first isn't
 # unreasonable.
-__import__( "pxr.Kind" )
-__import__( "pxr.Vt" )
-__import__( "pxr.Sdf" )
+# USD can be built without Python support, in which case there are no pxr
+# modules to import - IECoreUSD is still usable as a SceneInterface.
+try :
+	__import__( "pxr.Kind" )
+	__import__( "pxr.Vt" )
+	__import__( "pxr.Sdf" )
+except ImportError :
+	pass
 
 from ._IECoreUSD import *
 

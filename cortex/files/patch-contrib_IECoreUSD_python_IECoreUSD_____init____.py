--- contrib/IECoreUSD/python/IECoreUSD/__init__.py.orig	2026-09-24 18:05:26 UTC
+++ contrib/IECoreUSD/python/IECoreUSD/__init__.py
@@ -36,9 +36,14 @@
 # we get a weird exception when we later load the pxr modules. We're not
 # 100% sure why this is happening, but importing them first isn't
 # unreasonable.
-__import__( "pxr.Kind" )
-__import__( "pxr.Vt" )
-__import__( "pxr.Sdf" )
+try :
+	__import__( "pxr.Kind" )
+	__import__( "pxr.Vt" )
+	__import__( "pxr.Sdf" )
+except ImportError :
+	# USD may have been built without Python support, in which case
+	# `_IECoreUSD` is built without the `pxr` converters.
+	pass
 
 from ._IECoreUSD import *
 

--- startup/GafferScene/usdLights.py.orig	2026-09-24 19:41:12 UTC
+++ startup/GafferScene/usdLights.py
@@ -37,14 +37,22 @@
 import math
 import imath
 
-from pxr import Gf
-from pxr import Sdf
-from pxr import Usd
+try :
+	from pxr import Gf
+	from pxr import Sdf
+	from pxr import Usd
+except ImportError :
+	# USD may have been built without Python support, in which case we
+	# can't query it for default values.
+	Usd = None
 
 import Gaffer
 
 def __defaultValue( target ) :
 
+	if Usd is None :
+		return None
+
 	light, _, parameter = target[6:].partition( ":" )
 
 	if parameter.startswith( "shaping:" ) :

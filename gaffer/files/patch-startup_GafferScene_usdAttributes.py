--- startup/GafferScene/usdAttributes.py.orig	2026-09-24 19:41:12 UTC
+++ startup/GafferScene/usdAttributes.py
@@ -38,7 +38,13 @@ import IECore
 
 import Gaffer
 
-import pxr.Kind
+try :
+	import pxr.Kind
+	usdKinds = pxr.Kind.Registry().GetAllKinds()
+except ImportError :
+	# USD may have been built without Python support, in which case we
+	# offer the kinds that USD registers itself.
+	usdKinds = [ "model", "group", "assembly", "component", "subcomponent" ]
 
 Gaffer.Metadata.registerValues( {
 
@@ -83,8 +89,8 @@ Gaffer.Metadata.registerValues( {
 		""",
 		"label" : "Kind",
 		"plugValueWidget:type" : "GafferUI.PresetsPlugValueWidget",
-		"presetNames" : IECore.StringVectorData( [ IECore.CamelCase.toSpaced( k ) for k in pxr.Kind.Registry().GetAllKinds() if k != "model" ] ),
-		"presetValues" : IECore.StringVectorData( k for k in pxr.Kind.Registry().GetAllKinds() if k != "model" ),
+		"presetNames" : IECore.StringVectorData( [ IECore.CamelCase.toSpaced( k ) for k in usdKinds if k != "model" ] ),
+		"presetValues" : IECore.StringVectorData( k for k in usdKinds if k != "model" ),
 
 	},
 

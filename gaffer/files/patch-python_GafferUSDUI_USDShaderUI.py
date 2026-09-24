--- python/GafferUSDUI/USDShaderUI.py.orig	2026-09-24 19:41:12 UTC
+++ python/GafferUSDUI/USDShaderUI.py
@@ -36,8 +36,15 @@
 
 import functools
 
-from pxr import Sdr
-from pxr import Usd
+try :
+	from pxr import Sdr
+	from pxr import Usd
+except ImportError :
+	# USD may have been built without Python support, in which case we can't
+	# query it for parameter metadata, and only use the metadata we provide
+	# ourselves.
+	Sdr = None
+	Usd = None
 
 import IECore
 
@@ -59,6 +66,9 @@ def __primProperty( plug ) :
 	if isinstance( plug.parent(), Gaffer.OptionalValuePlug ) :
 		plug = plug.parent()
 
+	if Usd is None :
+		return None
+
 	plugName = plug.getName()
 
 	if plugName.startswith( "shaping:" ) :
@@ -75,6 +85,9 @@ def __primProperty( plug ) :
 
 def __sdrProperty( plug ) :
 
+	if Sdr is None :
+		return None
+
 	sdrNode = Sdr.Registry().GetShaderNodeByName( __shaderName( plug ) )
 	if plug.direction() == Gaffer.Plug.Direction.In :
 		return sdrNode.GetShaderInput( plug.getName() )
@@ -83,7 +96,8 @@ def __sdrProperty( plug ) :
 
 def __sdrMetadata( plug, name ) :
 
-	return __sdrProperty( plug ).GetMetadata().get( name )
+	property = __sdrProperty( plug )
+	return property.GetMetadata().get( name ) if property is not None else None
 
 def __layoutIndex( plug ) :
 
@@ -108,7 +122,8 @@ def __layoutSection( plug ) :
 	if property :
 		return property.GetMetadata( "displayGroup" )
 
-	return __sdrProperty( plug ).GetPage()
+	property = __sdrProperty( plug )
+	return property.GetPage() if property is not None else None
 
 def __label( plug ) :
 
@@ -116,7 +131,8 @@ def __label( plug ) :
 	if property :
 		return property.GetMetadata( "displayName" )
 
-	return __sdrProperty( plug ).GetLabel() or None
+	property = __sdrProperty( plug )
+	return ( property.GetLabel() or None ) if property is not None else None
 
 def __description( plug ) :
 
@@ -150,7 +166,7 @@ def __widgetType( plug ) :
 		if property.GetMetadata( "allowedTokens" ) is not None :
 			return "GafferUI.PresetsPlugValueWidget"
 
-	else :
+	elif Sdr is not None :
 
 		property = __sdrProperty( plug )
 
@@ -181,7 +197,7 @@ def __presetNames( plug ) :
 		return IECore.StringVectorData( allowedTokens ) if allowedTokens else None
 
 	property = __sdrProperty( plug )
-	options = property.GetOptions()
+	options = property.GetOptions() if property is not None else None
 	if options :
 		return IECore.StringVectorData( [ o[0] for o in options ] )
 
@@ -193,7 +209,7 @@ def __presetValues( plug ) :
 		return IECore.StringVectorData( allowedTokens ) if allowedTokens else None
 
 	property = __sdrProperty( plug )
-	options = property.GetOptions()
+	options = property.GetOptions() if property is not None else None
 	if options :
 		if len( options ) > 1 and all( o[1] == "" for o in options ) :
 			# USD's `_CreateSdrShaderProperty` method in `shaderDefUtils.cpp`
@@ -214,6 +230,8 @@ def __noduleType( plug ) :
 		return None
 
 	property = __sdrProperty( plug )
+	if property is None :
+		return None
 	# `None` means "no opinion", so a nodule will be created based
 	# on the plug's type. `""` means "no nodule please".
 	return None if property.IsConnectable() else ""

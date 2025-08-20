--- src/GafferUSD/USDShader.cpp.orig	2025-03-07 10:52:48 UTC
+++ src/GafferUSD/USDShader.cpp
@@ -301,7 +301,7 @@ Plug *loadShaderProperty( const SdrShaderProperty &pro
 
 Plug *loadShaderProperty( const SdrShaderProperty &property, Plug *parent )
 {
-	SdfValueTypeName sdfType = property.GetTypeAsSdfType().first;
+	SdfValueTypeName sdfType = property.GetTypeAsSdfType().GetSdfType();
 	if(
 		property.GetType() == SdrPropertyTypes->Terminal ||
 		property.GetType() == SdrPropertyTypes->Vstruct

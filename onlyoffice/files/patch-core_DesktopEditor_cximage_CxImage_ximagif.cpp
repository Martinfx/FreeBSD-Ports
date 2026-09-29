--- core/DesktopEditor/cximage/CxImage/ximagif.cpp.orig	2025-09-23 23:42:43 UTC
+++ core/DesktopEditor/cximage/CxImage/ximagif.cpp
@@ -86,7 +86,7 @@ namespace NSGeneratePalette
 
                 if ( ( X + Width ) > SrcWidth || ( Y + Height ) > SrcHeigth || NULL == pSrc )
                 {
-                    return NULL;
+                    return false;
                 }
 
                 (*pImage)	=	new CImage8bit ();

--- core/DesktopEditor/cximage/CxImage/ximagif.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/cximage/CxImage/ximagif.cpp
@@ -86,7 +86,7 @@
 
                 if ( ( X + Width ) > SrcWidth || ( Y + Height ) > SrcHeigth || NULL == pSrc )
                 {
-                    return NULL;
+                    return false;
                 }
 
                 (*pImage)	=	new CImage8bit ();

--- core/DesktopEditor/cximage/CxImage/ximaraw.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/cximage/CxImage/ximaraw.cpp
@@ -200,7 +200,7 @@
 				for (c=0; c < dcr.colors; c++) ppm2[col*dcr.colors+c] = dcr.image[soff][c];
 		}
 		if (dcr.opt.output_bps == 16 && !dcr.opt.output_tiff && htons(0x55aa) != 0x55aa)
-#if defined(_LINUX) || defined(__APPLE__)
+#if defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
 			swab ((char*)ppm2, (char*)ppm2, dcr.width*dcr.colors*2);
 #else
 			_swab ((char*)ppm2, (char*)ppm2, dcr.width*dcr.colors*2);

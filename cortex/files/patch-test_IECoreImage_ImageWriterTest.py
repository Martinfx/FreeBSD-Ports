--- test/IECoreImage/ImageWriterTest.py.orig	2026-09-10 21:49:58 UTC
+++ test/IECoreImage/ImageWriterTest.py
@@ -415,7 +415,9 @@
 		imgNew = r.read()
 		imgBlindData = imgNew.blindData()
 		# eliminate default header info that comes from OIIO
-		del imgBlindData['oiio:ColorSpace']
+		if 'oiio:ColorSpace' in imgBlindData :
+			# OIIO 3.1 no longer adds a colour space to the EXR header
+			del imgBlindData['oiio:ColorSpace']
 		if IECoreImage.OpenImageIOAlgo.version() >= 20206 :
 			del imgBlindData['oiio:subimages']
 		if IECoreImage.OpenImageIOAlgo.version() >= 30000 :

--- test/IECoreImage/ImageReaderTest.py.orig	2026-09-10 21:49:58 UTC
+++ test/IECoreImage/ImageReaderTest.py
@@ -235,6 +235,9 @@
 
 		r = IECore.Reader.create( os.path.join( "test", "IECoreImage", "data", "exr", "uvMap.512x256.exr" ) )
 		header = r.readHeader()
+		if 'oiio:ColorSpace' not in header :
+			# OIIO 3.1 no longer puts a colour space in the EXR header
+			del dictHeader['oiio:ColorSpace']
 		self.assertEqual( header, IECore.CompoundObject(dictHeader) )
 
 		img = r.read()

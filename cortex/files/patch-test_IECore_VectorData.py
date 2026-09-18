--- test/IECore/VectorData.py.orig	2026-09-10 21:49:58 UTC
+++ test/IECore/VectorData.py
@@ -1301,8 +1301,12 @@
 		secondTime = t.stop()
 
 		self.assertNotEqual( h, hm )
-		# should be slow this time, as the hash is being recomputed
-		self.assertGreaterEqual( secondTime, 0.7 * firstTime )
+		# should be slow this time, as the hash is being recomputed. Note the
+		# generous margin : IECore.Timer measures user CPU time, whose resolution
+		# is 1/64s on FreeBSD, so a ~60ms hash is only a handful of ticks. A
+		# recomputed hash is still 3 orders of magnitude slower than a cached one,
+		# which is what this is really distinguishing.
+		self.assertGreaterEqual( secondTime, 0.25 * firstTime )
 
 		t = IECore.Timer()
 		h2 = d2.hash()
@@ -1318,8 +1322,9 @@
 		secondTime = t.stop()
 
 		self.assertEqual( hm, hm2 )
-		# should be slow this time, as the hash is being recomputed
-		self.assertGreaterEqual( secondTime, 0.8 * firstTime )
+		# should be slow this time, as the hash is being recomputed ( see above
+		# for why the margin is so generous )
+		self.assertGreaterEqual( secondTime, 0.25 * firstTime )
 
 class TestInternedStringVectorData( unittest.TestCase ) :
 

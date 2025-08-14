--- python/GafferArnoldUITest/InteractiveArnoldRenderPerformanceTest.py.orig	2025-03-12 17:53:39 UTC
+++ python/GafferArnoldUITest/InteractiveArnoldRenderPerformanceTest.py
@@ -53,7 +53,7 @@ import GafferImageTest
 import GafferUITest
 import GafferImageTest
 
-from Qt import QtCore
+from PyQt5 import QtCore
 
 @unittest.skipIf( GafferTest.inCI(), "Performance not relevant on CI platform" )
 class InteractiveArnoldRenderPerformanceTest( GafferUITest.TestCase ) :

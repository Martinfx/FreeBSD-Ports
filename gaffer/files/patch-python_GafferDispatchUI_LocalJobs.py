--- python/GafferDispatchUI/LocalJobs.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferDispatchUI/LocalJobs.py
@@ -47,8 +47,8 @@ from GafferUI.PlugValueWidget import sole
 
 from GafferUI.PlugValueWidget import sole
 
-from Qt import QtCore
-from Qt import QtGui
+from PyQt5 import QtCore
+from PyQt5 import QtGui
 
 class _LocalJobsPath( Gaffer.Path ) :
 

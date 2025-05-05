--- python/GafferUI/EventLoop.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/EventLoop.py
@@ -48,9 +48,9 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtCore
-from Qt import QtWidgets
-
+from PyQt5 import QtCore
+from PyQt5 import QtWidgets
+from PyQt5.QtCore import pyqtSlot
 ## This class provides the event loops used to run GafferUI based applications.
 class EventLoop( object ) :
 
@@ -386,7 +386,7 @@ class _UIThreadExecutor( QtCore.QObject ) :
 
 		self.__blockedCallables = None
 
-	@QtCore.Slot()
+	@pyqtSlot()
 	def __executeInternal( self ) :
 
 		assert( QtCore.QThread.currentThread() == QtWidgets.QApplication.instance().thread() )

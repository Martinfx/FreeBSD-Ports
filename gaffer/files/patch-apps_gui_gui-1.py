--- apps/gui/gui-1.py.orig	2025-03-12 20:13:02 UTC
+++ apps/gui/gui-1.py
@@ -129,7 +129,7 @@ class gui( Gaffer.Application ) :
 		# Perhaps we should abolish the ApplicationRoot clipboard and the ScriptNode cut/copy/paste routines, relegating
 		# them all to GafferUI functionality?
 
-		from Qt import QtWidgets
+		from PyQt5 import QtWidgets
 
 		self.__clipboardContentsChangedConnection = self.root().clipboardContentsChangedSignal().connect(
 			Gaffer.WeakMethod( self.__clipboardContentsChanged ),
@@ -145,7 +145,7 @@ class gui( Gaffer.Application ) :
 
 		data = applicationRoot.getClipboardContents()
 
-		from Qt import QtWidgets
+		from PyQt5 import QtWidgets
 		clipboard = QtWidgets.QApplication.clipboard()
 		try :
 			self.__ignoreQtClipboardContentsChanged = True # avoid triggering an unecessary copy back in __qtClipboardContentsChanged
@@ -158,7 +158,7 @@ class gui( Gaffer.Application ) :
 		if self.__ignoreQtClipboardContentsChanged :
 			return
 
-		from Qt import QtWidgets
+		from PyQt5 import QtWidgets
 
 		text = QtWidgets.QApplication.clipboard().text().encode( "utf-8" )
 		if text and text != str( self.root().getClipboardContents() ).encode( "utf-8" ) :

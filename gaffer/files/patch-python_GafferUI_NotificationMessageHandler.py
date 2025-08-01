--- python/GafferUI/NotificationMessageHandler.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/NotificationMessageHandler.py
@@ -39,7 +39,7 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtGui
+from PyQt5 import QtGui
 
 class NotificationMessageHandler( IECore.MessageHandler ) :
 

--- python/GafferUI/TweakPlugValueWidget.py.orig	2025-03-12 17:53:38 UTC
+++ python/GafferUI/TweakPlugValueWidget.py
@@ -43,7 +43,7 @@ import GafferUI
 import Gaffer
 import GafferUI
 
-from Qt import QtWidgets
+from PyQt5 import QtWidgets
 
 # Widget for TweakPlug, which is used to build tweak nodes such as ShaderTweaks
 # and CameraTweaks.  Shows a value plug that you can use to specify a tweak value, along with

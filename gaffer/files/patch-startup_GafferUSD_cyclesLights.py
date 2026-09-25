--- startup/GafferUSD/cyclesLights.py.orig	2026-09-24 19:41:12 UTC
+++ startup/GafferUSD/cyclesLights.py
@@ -36,8 +36,6 @@
 
 import pathlib
 
-from pxr import Plug
-
 # Register a USD plugin that adds Cycles-specific auto-apply schemas for
 # UsdLux lights. We deliberately don't add this to the `PXR_PLUGINPATH_NAME`
 # search path because we don't want it to be loaded in any third-party
@@ -47,6 +45,7 @@ from pxr import Plug
 
 try :
 	import GafferCycles
+	from pxr import Plug
 	Plug.Registry().RegisterPlugins( str( pathlib.Path( GafferCycles.__file__ ).parents[2] / "plugin" / "GafferCycles" / "plugInfo.json" ) )
 except ImportError :
 	# GafferCycles not available

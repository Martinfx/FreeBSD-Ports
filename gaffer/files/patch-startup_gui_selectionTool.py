--- startup/gui/selectionTool.py.orig	2026-09-24 19:41:12 UTC
+++ startup/gui/selectionTool.py
@@ -37,7 +37,12 @@
 import functools
 import IECoreScene
 
-from pxr import Kind
+try :
+	from pxr import Kind
+except ImportError :
+	# USD may have been built without Python support, in which case we
+	# can't offer selection by kind.
+	Kind = None
 
 import IECore
 
@@ -62,7 +67,7 @@ def __kindSelectionModifier( targetKind,
 	return path
 
 
-usdKinds = Kind.Registry.GetAllKinds()
+usdKinds = Kind.Registry.GetAllKinds() if Kind is not None else []
 
 # Build a simplified hierarchy for sorting
 kindPaths = []

--- python/IECoreVDB/__init__.py.orig	2026-09-10 21:49:58 UTC
+++ python/IECoreVDB/__init__.py
@@ -35,10 +35,16 @@
 __import__( "IECore" )
 __import__( "IECoreScene" )
 
+# OpenVDB can be built without its Python module ( FreeBSD's misc/openvdb has
+# no option for it at all ). IECoreVDB is still useful in that case - only the
+# grid accessors, which convert to and from `openvdb.GridBase`, can't work.
 try :
 	import openvdb
 except ImportError :
-	import pyopenvdb
+	try :
+		import pyopenvdb
+	except ImportError :
+		pass
 
 from ._IECoreVDB import *
 

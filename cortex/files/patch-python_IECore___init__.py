--- python/IECore/__init__.py.orig	2026-09-25 08:10:04 UTC
+++ python/IECore/__init__.py
@@ -38,7 +38,7 @@
 #
 # Some parts of the IECore library are defined purely in Python. These are shown below.
 
-import os, pathlib
+import os, pathlib, sys
 
 if hasattr( os, "add_dll_directory" ) and "IECORE_DLL_DIRECTORIES" in os.environ :
 	for directory in os.environ.get( "IECORE_DLL_DIRECTORIES" ).split( os.pathsep ) :
@@ -47,8 +47,16 @@
 			os.add_dll_directory( directory )
 	del directory
 
+# FreeBSD's C++ runtime compares `type_info` objects by address, so the RTTI
+# for types instantiated in several libraries (class templates in particular)
+# only matches if they all resolve it to the same definition. Loading the
+# extension modules with RTLD_GLOBAL ensures that, which Boost.Python needs
+# to convert between classes bound in different modules.
+if sys.platform.startswith( "freebsd" ) :
+	sys.setdlopenflags( sys.getdlopenflags() | os.RTLD_GLOBAL )
+
 # Remove pollution of IECore namespace
-del os, pathlib
+del os, pathlib, sys
 
 __import__( "imath" )
 

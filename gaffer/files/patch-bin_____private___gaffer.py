--- bin/__private/_gaffer.py.orig	2026-09-25 08:10:28 UTC
+++ bin/__private/_gaffer.py
@@ -48,7 +48,7 @@ libraryPath = {
 	"linux" : "LD_LIBRARY_PATH",
 	"darwin" : "DYLD_LIBRARY_PATH",
 	"win32" : "PATH",
-}.get( sys.platform )
+}.get( sys.platform, "LD_LIBRARY_PATH" )
 
 def appendToPath( pathToAppend, envVar ) :
 
@@ -109,6 +109,31 @@ if sys.platform in ( "linux", "darwin" )
 # bad serialisations in certain locales.
 os.environ["LC_NUMERIC"] = "C"
 
+# FreeBSD Setup
+# =============
+
+# On FreeBSD, Gaffer uses the Cortex, USD, OSL and font packages installed
+# in %%LOCALBASE%% rather than bundling them, so point it at their resources.
+
+if sys.platform.startswith( "freebsd" ) :
+
+	appendToPath( "%%LOCALBASE%%/share/cortex", "IECOREGL_SHADER_PATHS" )
+	appendToPath( "%%LOCALBASE%%/share/cortex", "IECOREGL_SHADER_INCLUDE_PATHS" )
+	# Cortex installs the plugin that lets USD read and write Cortex's
+	# SceneInterface formats outside of USD's own plugin directory.
+	appendToPath( "%%LOCALBASE%%/resources/IECoreUSD", "PXR_PLUGINPATH_NAME" )
+	appendToPath( "%%LOCALBASE%%/share/fonts/bitstream-vera", "IECORE_FONT_PATHS" )
+	# The startup scripts search `PYTHONPATH` to decide which of the optional
+	# Cortex modules to import, so the site-packages directory holding them
+	# must be on it explicitly. USD installs its `pxr` module (when it has
+	# been built with Python support) in `lib/python`.
+	appendToPath( "%%PYTHON_SITELIBDIR%%", "PYTHONPATH" )
+	appendToPath( "%%LOCALBASE%%/lib/python", "PYTHONPATH" )
+	# Provides `stdosl.h` for the OSLCode node and OSL expressions.
+	appendToPath( "%%LOCALBASE%%/share/openshadinglanguage/shaders", "OSL_SHADER_PATHS" )
+	if "OSLHOME" not in os.environ :
+		os.environ["OSLHOME"] = "%%LOCALBASE%%"
+
 # Core Gaffer Setup
 # =================
 
@@ -183,6 +208,9 @@ def setUpCycles() :
 		cyclesRoot = pathlib.Path( os.environ["CYCLES_ROOT"] )
 	else :
 		cyclesRoot = gafferRoot / "cycles"
+		# On FreeBSD, the resources of Cycles are installed by graphics/cycles.
+		if sys.platform.startswith( "freebsd" ) and ( gafferRoot / "python" / "GafferCycles" ).is_dir() :
+			cyclesRoot = pathlib.Path( "%%LOCALBASE%%/share/cycles" )
 		if not cyclesRoot.exists() :
 			return
 		os.environ["CYCLES_ROOT"] = str( cyclesRoot )
@@ -375,6 +403,8 @@ setUp3rdPartyExtensions()
 
 # Enable scoped enum shortcuts to preserve compatibility with PySide2.
 os.environ["PYSIDE63_OPTION_PYTHON_ENUM"] = "0x08" # ENOPT_SCOPED_SHORTCUT
+# PySide 6.6 and later read the option from a differently named variable.
+os.environ["PYSIDE6_OPTION_PYTHON_ENUM"] = "0x08"
 
 os.environ["QT_QPA_PLATFORM_PLUGIN_PATH"] = str( gafferRoot / "qt" / "plugins" )
 

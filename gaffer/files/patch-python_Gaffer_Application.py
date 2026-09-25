--- python/Gaffer/Application.py.orig	2026-09-24 19:41:12 UTC
+++ python/Gaffer/Application.py
@@ -147,7 +147,13 @@ class Application( IECore.Parameterised
 		threadStackSize = 4 * 1024 * 1024
 		if os.name != "nt" :
 			import resource
-			threadStackSize = max( resource.getrlimit( resource.RLIMIT_STACK )[0], threadStackSize )
+			stackLimit = resource.getrlimit( resource.RLIMIT_STACK )[0]
+			if sys.platform.startswith( "freebsd" ) :
+				# FreeBSD's default stack limit is `kern.maxssiz` (512MB on
+				# amd64), or RLIM_INFINITY, neither of which is suitable for
+				# every TBB thread.
+				stackLimit = min( stackLimit, 64 * 1024 * 1024 )
+			threadStackSize = max( stackLimit, threadStackSize )
 		else :
 			import ctypes
 			maxStackAddress = ctypes.c_ulonglong()

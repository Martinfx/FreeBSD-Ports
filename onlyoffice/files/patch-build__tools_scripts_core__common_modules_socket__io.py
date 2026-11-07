--- build_tools/scripts/core_common/modules/socket_io.py.orig	2026-11-06 00:00:00 UTC
+++ build_tools/scripts/core_common/modules/socket_io.py
@@ -32,17 +32,20 @@
   base_dir = base.get_script_dir() + "/../../core/Common/3dParty/socketio"
 
   old_cur = os.getcwd()
-  os.chdir(base_dir)
-  base.common_check_version("socketio", "2", clean)
-  os.chdir(old_cur)
+#  os.chdir(base_dir)
+#  base.common_check_version("socketio", "2", clean)
+#  os.chdir(old_cur)
 
-  if not base.is_dir(base_dir + "/socket.io-client-cpp"):
-    base.cmd_in_dir(base_dir, "git", ["clone", "https://github.com/socketio/socket.io-client-cpp.git"])
-    base.cmd_in_dir(base_dir + "/socket.io-client-cpp", "git", ["checkout", "da779141a7379cc30c870d48295033bc16a23c66"])
-    base.cmd_in_dir(base_dir + "/socket.io-client-cpp", "git", ["submodule", "init"])
-    base.cmd_in_dir(base_dir + "/socket.io-client-cpp", "git", ["submodule", "update"])
-    base.cmd_in_dir(base_dir + "/socket.io-client-cpp/lib/asio", "git", ["checkout", "230c0d2ae035c5ce1292233fcab03cea0d341264"])
-    base.cmd_in_dir(base_dir + "/socket.io-client-cpp/lib/websocketpp", "git", ["checkout", "56123c87598f8b1dd471be83ca841ceae07f95ba"])
+  print("[patch]: socketio")
+
+# The sources and their submodules are GH_TUPLE distfiles, patch them once
+  if not base.is_dir(base_dir + "/socket.io-client-cpp/src_no_tls"):
+#    base.cmd_in_dir(base_dir, "git", ["clone", "https://github.com/socketio/socket.io-client-cpp.git"])
+#    base.cmd_in_dir(base_dir + "/socket.io-client-cpp", "git", ["checkout", "da779141a7379cc30c870d48295033bc16a23c66"])
+#    base.cmd_in_dir(base_dir + "/socket.io-client-cpp", "git", ["submodule", "init"])
+#    base.cmd_in_dir(base_dir + "/socket.io-client-cpp", "git", ["submodule", "update"])
+#    base.cmd_in_dir(base_dir + "/socket.io-client-cpp/lib/asio", "git", ["checkout", "230c0d2ae035c5ce1292233fcab03cea0d341264"])
+#    base.cmd_in_dir(base_dir + "/socket.io-client-cpp/lib/websocketpp", "git", ["checkout", "56123c87598f8b1dd471be83ca841ceae07f95ba"])
     # patches
     base.apply_patch(base_dir + "/socket.io-client-cpp/lib/websocketpp/websocketpp/impl/connection_impl.hpp", base_dir + "/patches/websocketpp.patch")
     base.apply_patch(base_dir + "/socket.io-client-cpp/src/internal/sio_client_impl.cpp", base_dir + "/patches/sio_client_impl_fail.patch")

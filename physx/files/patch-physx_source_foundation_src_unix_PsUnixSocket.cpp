--- physx/source/foundation/src/unix/PsUnixSocket.cpp.orig	2024-07-05 09:43:39 UTC
+++ physx/source/foundation/src/unix/PsUnixSocket.cpp
@@ -31,6 +31,10 @@
 
 #include "PsSocket.h"
 
+#if defined(PX_FREEBSD)
+#include <netinet/in.h>
+#endif
+
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/select.h>

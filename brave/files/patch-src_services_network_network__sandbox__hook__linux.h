--- src/services/network/network_sandbox_hook_linux.h.orig	2026-11-24 12:50:30 UTC
+++ src/services/network/network_sandbox_hook_linux.h
@@ -6,7 +6,11 @@
 #define SERVICES_NETWORK_NETWORK_SANDBOX_HOOK_LINUX_H_
 
 #include "base/component_export.h"
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace network {
 

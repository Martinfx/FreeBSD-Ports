--- src/core/libraries/kernel/threads/exception.h.orig	2026-10-02 12:00:00 UTC
+++ src/core/libraries/kernel/threads/exception.h
@@ -8,6 +8,7 @@
 
 #ifndef _WIN32
 #include <sys/signal.h>
+#include <sys/ucontext.h>
 #endif
 
 namespace Core::Loader {

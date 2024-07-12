--- src/libpsl-native/src/getuserfrompid.cpp.orig	2024-03-30 21:53:44 UTC
+++ src/libpsl-native/src/getuserfrompid.cpp
@@ -21,6 +21,7 @@
 
 #if __FreeBSD__
 #include <sys/user.h>
+#include <sys/sysctl.h>
 #endif
 
 char* GetUserFromPid(pid_t pid)

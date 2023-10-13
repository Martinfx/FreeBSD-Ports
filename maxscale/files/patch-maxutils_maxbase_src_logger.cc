--- maxutils/maxbase/src/logger.cc.orig	2023-09-22 06:15:26 UTC
+++ maxutils/maxbase/src/logger.cc
@@ -18,6 +18,7 @@
 #include <syslog.h>
 #include <fcntl.h>
 #include <unistd.h>
+#include <sys/stat.h>
 
 #include <cassert>
 #include <chrono>
@@ -84,7 +85,7 @@ std::string get_ident()
     if (!this_unit.ident[0])
     {
 #ifdef __GNUC__
-        return program_invocation_short_name;
+        return getprogname();
 #else
         return "The Program";
 #endif

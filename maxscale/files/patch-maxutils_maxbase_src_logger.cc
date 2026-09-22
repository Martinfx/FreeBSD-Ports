--- maxutils/maxbase/src/logger.cc.orig	2022-09-12 06:23:56 UTC
+++ maxutils/maxbase/src/logger.cc
@@ -17,6 +17,7 @@
 #include <syslog.h>
 #include <fcntl.h>
 #include <unistd.h>
+#include <sys/stat.h>
 
 #include <cassert>
 #include <chrono>
@@ -83,7 +84,7 @@ std::string get_ident()
     if (!this_unit.ident[0])
     {
 #ifdef __GNUC__
-        return program_invocation_short_name;
+        return getprogname();
 #else
         return "The Program";
 #endif

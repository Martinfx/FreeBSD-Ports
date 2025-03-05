--- pxr/base/tf/diagnostic.cpp.orig	2025-03-05 13:28:26 UTC
+++ pxr/base/tf/diagnostic.cpp
@@ -20,6 +20,7 @@
 #include <cstdio>
 #include <stdexcept>
 #include <csignal>
+#include <unistd.h>
 
 using std::string;
 

--- src/app/actions/actions.hpp.orig	2025-05-21 09:02:27 UTC
+++ src/app/actions/actions.hpp
@@ -1,6 +1,8 @@
 #ifndef ZATHURA_ACTIONS_HPP
 #define ZATHURA_ACTIONS_HPP
+#include <mutex>
 #include "../app.hpp"
+#include <icicle.h>
 extern std::mutex debugActionsMutex;
 extern void runActions();
 extern void startDebugging();

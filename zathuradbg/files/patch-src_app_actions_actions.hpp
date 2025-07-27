--- src/app/actions/actions.hpp.orig	2025-07-27 12:55:31 UTC
+++ src/app/actions/actions.hpp
@@ -1,5 +1,6 @@
 #ifndef ZATHURA_ACTIONS_HPP
 #define ZATHURA_ACTIONS_HPP
+#include <mutex>
 #include "../app.hpp"
 extern std::mutex debugActionsMutex;
 extern void runActions();

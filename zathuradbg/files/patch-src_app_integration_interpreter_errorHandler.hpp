--- src/app/integration/interpreter/errorHandler.hpp.orig	2024-11-17 09:57:49 UTC
+++ src/app/integration/interpreter/errorHandler.hpp
@@ -2,6 +2,6 @@
 #define ZATHURA_ERRORHANDLER_HPP
 #include <unicorn/unicorn.h>
 #include "../../../vendor/log/clue.hpp"
-#include "../../../vendor/code/tinyfiledialogs.h"
+#include "../../../vendor/tinydialogue/tinyfiledialogs.h"
 extern void handleUCErrors(uc_err err);
 #endif //ZATHURA_ERRORHANDLER_HPP

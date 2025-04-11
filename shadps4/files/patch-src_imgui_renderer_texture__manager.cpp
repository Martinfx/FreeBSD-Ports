--- src/imgui/renderer/texture_manager.cpp.orig	2025-04-07 16:30:43 UTC
+++ src/imgui/renderer/texture_manager.cpp
@@ -3,6 +3,8 @@
 
 #include <deque>
 #include <utility>
+#include <atomic>
+#include <thread>
 
 #include <imgui.h>
 #include "common/assert.h"
@@ -251,4 +253,4 @@ void Submit() {
 }
 } // namespace Core::TextureManager
 
-} // namespace ImGui
\ No newline at end of file
+} // namespace ImGui

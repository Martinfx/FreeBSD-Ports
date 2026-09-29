--- desktop-sdk/ChromiumBasedEditors/lib/src/keyboardlayout.h.orig	2026-09-24 21:58:50 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/keyboardlayout.h
@@ -1,7 +1,7 @@
 #ifndef KEYBOARDLAYOUT_H
 #define KEYBOARDLAYOUT_H
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 # include <cstdint>
 #endif
 #include <vector>
@@ -16,7 +16,7 @@ public:
     ~KeyboardLayout();
 
     std::vector<std::pair<std::string, std::string>> GetKeyboardLayoutList() const;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     bool IsKeyboardSupport() const;
     uint16_t GetKeyboardLayout() const;
 

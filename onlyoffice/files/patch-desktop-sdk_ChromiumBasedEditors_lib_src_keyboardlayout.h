--- desktop-sdk/ChromiumBasedEditors/lib/src/keyboardlayout.h.orig	2026-11-05 00:00:00 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/keyboardlayout.h
@@ -36,7 +36,7 @@
 #ifndef KEYBOARDLAYOUT_H
 #define KEYBOARDLAYOUT_H
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 # include <cstdint>
 #endif
 #include <vector>
@@ -51,7 +51,7 @@
     ~KeyboardLayout();
 
     std::vector<std::pair<std::string, std::string>> GetKeyboardLayoutList() const;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     bool IsKeyboardSupport() const;
     uint16_t GetKeyboardLayout() const;
 

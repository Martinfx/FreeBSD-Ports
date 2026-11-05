--- desktop-sdk/ChromiumBasedEditors/lib/src/keyboardlayout.cpp.orig	2026-11-05 00:00:00 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/keyboardlayout.cpp
@@ -228,7 +228,7 @@
 }
 
 KeyboardLayout::KeyboardLayout()
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     : pimpl(new KeyboardLayoutPrivate)
 #endif
 {
@@ -237,12 +237,12 @@
 
 KeyboardLayout::~KeyboardLayout()
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     delete pimpl, pimpl = nullptr;
 #endif
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 bool KeyboardLayout::IsKeyboardSupport() const
 {
     return pimpl->device_id != -1;

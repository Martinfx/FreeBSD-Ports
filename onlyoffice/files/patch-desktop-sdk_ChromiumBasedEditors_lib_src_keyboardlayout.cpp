--- desktop-sdk/ChromiumBasedEditors/lib/src/keyboardlayout.cpp.orig	2026-09-24 21:58:50 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/keyboardlayout.cpp
@@ -183,8 +183,8 @@ static std::string getNativeLanguageName
     icu::UnicodeString uname;
     loc.getDisplayLanguage(loc, uname);
     if (!uname.isEmpty()) {
-        UnicodeString first = uname.tempSubString(0, 1);
-        UnicodeString rest = uname.tempSubString(1);
+        icu::UnicodeString first = uname.tempSubString(0, 1);
+        icu::UnicodeString rest = uname.tempSubString(1);
         first.toUpper();
         uname = first + rest;
         uname.toUTF8String(displayName);
@@ -193,7 +193,7 @@ static std::string getNativeLanguageName
 }
 
 KeyboardLayout::KeyboardLayout()
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     : pimpl(new KeyboardLayoutPrivate)
 #endif
 {
@@ -202,12 +202,12 @@ KeyboardLayout::KeyboardLayout()
 
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

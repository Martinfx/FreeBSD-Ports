--- desktop-apps/win-linux/src/clangater.cpp.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/clangater.cpp
@@ -338,7 +338,7 @@
     if ( _lang.isEmpty() )
         _lang = reg_user.value("locale").value<QString>();
 
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
 //    if ( _lang.isEmpty() ) {
 //        _lang = QLocale::system().name();
 //    }

--- desktop-apps/win-linux/src/clangater.cpp.orig	2026-09-28 08:45:35 UTC
+++ desktop-apps/win-linux/src/clangater.cpp
@@ -302,7 +302,7 @@ void CLangater::init()
     if ( _lang.isEmpty() )
         _lang = reg_user.value("locale").value<QString>();
 
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
 //    if ( _lang.isEmpty() ) {
 //        _lang = QLocale::system().name();
 //    }

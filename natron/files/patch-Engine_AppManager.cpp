--- Engine/AppManager.cpp.orig	2020-10-30 05:13:34 UTC
+++ Engine/AppManager.cpp
@@ -255,8 +255,8 @@ setSigSegvSignal()
 
 //Borrowed from https://github.com/python/cpython/blob/634cb7aa2936a09e84c5787d311291f0e042dba3/Python/fileutils.c
 //Somehow Python 3 dev forced every C application embedding python to have their own code to convert char** to wchar_t**
-static wchar_t*
-char2wchar(char* arg)
+wchar_t*
+char2wchar(const char* arg)
 {
     wchar_t *res = NULL;
 
@@ -1840,7 +1840,7 @@ AppManager::getPyPlugsGlobalPath() const
 #ifdef __NATRON_OSX__
     path = QString::fromUtf8("/Library/Application Support/%1/Plugins").arg( QString::fromUtf8(NATRON_APPLICATION_NAME) );
 #else
-    path = QString::fromUtf8("/usr/share/%1/Plugins").arg( QString::fromUtf8(NATRON_APPLICATION_NAME) );
+    path = QString::fromUtf8("/usr/local/share/%1/Plugins").arg( QString::fromUtf8(NATRON_APPLICATION_NAME) );
 #endif
 #elif defined(__NATRON_WIN32__)
     wchar_t buffer[MAX_PATH];

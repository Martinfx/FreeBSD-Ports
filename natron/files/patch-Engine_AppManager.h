--- Engine/AppManager.h.orig	2020-10-30 05:13:34 UTC
+++ Engine/AppManager.h
@@ -460,6 +460,8 @@ GCC_DIAG_SUGGEST_OVERRIDE_ON (public)
     void refreshDiskCacheLocation();
     const QString& getDiskCacheLocation() const;
 
+    static wchar_t* char2wchar(const char* arg);
+
     void saveCaches() const;
 
     PyObject* getMainModule();

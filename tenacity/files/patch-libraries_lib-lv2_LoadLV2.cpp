--- libraries/lib-lv2/LoadLV2.cpp.orig	2026-10-16 17:51:47 UTC
+++ libraries/lib-lv2/LoadLV2.cpp
@@ -196,8 +196,7 @@
    newVar += wxT(":/usr/lib/lv2");
    newVar += wxT(":") + libdir.GetPath();
 
-   // Tell SUIL where to find his GUI support modules
-   wxSetEnv(wxT("SUIL_MODULE_DIR"), wxT(PKGLIBDIR));
+   // Use the system suil, which knows where its GUI support modules live
 #endif
 
    {

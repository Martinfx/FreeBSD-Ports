--- desktop-apps/win-linux/src/main.cpp.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/main.cpp
@@ -139,7 +139,7 @@
     app.setStyle(QStyleFactory::create("Fusion"));
 
     /* the order is important */
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
     gtk_init(&argc, &argv);
 #endif
     CApplicationCEF::Prepare(argc, argv);

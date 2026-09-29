--- desktop-apps/win-linux/src/main.cpp.orig	2026-09-28 08:45:35 UTC
+++ desktop-apps/win-linux/src/main.cpp
@@ -162,7 +162,7 @@ int main( int argc, char *argv[] )
     app.setStyle(QStyleFactory::create("Fusion"));
 
     /* the order is important */
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
     gtk_init(&argc, &argv);
 #endif
     CApplicationCEF::Prepare(argc, argv);

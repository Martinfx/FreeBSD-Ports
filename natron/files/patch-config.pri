--- config.pri.orig	2022-06-11 16:59:14 UTC
+++ config.pri
@@ -0,0 +1,7 @@
+boost: LIBS += -lboost_serialization
+PKGCONFIG += expat
+PKGCONFIG += fontconfig
+cairo {
+        PKGCONFIG += cairo
+        LIBS -=  $$system(pkg-config --variable=libdir cairo)/libcairo.a
+}

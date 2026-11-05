--- core/PdfFile/PdfFile.pro.orig	2026-11-05 00:00:00 UTC
+++ core/PdfFile/PdfFile.pro
@@ -147,6 +147,11 @@
            NOMINMAX
 LIBS += -L$$CORE_BUILDS_LIBRARIES_PATH -lCryptoPPLib
 
+core_freebsd {
+    DEFINES += HAVE_UNISTD_H \
+               HAVE_FCNTL_H
+    QMAKE_CXXFLAGS += -Wno-narrowing
+}
 core_linux {
     DEFINES += HAVE_UNISTD_H \
                HAVE_FCNTL_H

--- core/Apple/IWork.pro.orig	2026-11-05 00:00:00 UTC
+++ core/Apple/IWork.pro
@@ -43,6 +43,14 @@
 
 DEFINES += IWORK_USE_DYNAMIC_LIBRARY
 
+INCLUDEPATH += %%LOCALBASE%%/include/librevenge-0.0
+INCLUDEPATH += %%LOCALBASE%%/include/libetonyek-0.1
+INCLUDEPATH += %%LOCALBASE%%/include/libodfgen-0.1
+
+LIBS += %%LOCALBASE%%/lib/librevenge-0.0.so
+LIBS += %%LOCALBASE%%/lib/libetonyek-0.1.so
+LIBS += %%LOCALBASE%%/lib/libodfgen-0.1.so
+
 CORE_ROOT_DIR = $$PWD/..
 PWD_ROOT_DIR = $$PWD
 include($$CORE_ROOT_DIR/Common/base.pri)
@@ -69,8 +77,8 @@
 include($$CORE_ROOT_DIR/Common/3dParty/apple/apple.pri)
 
 # TEST
-HEADERS += $$ODF_LIB_ROOT/test/StringDocumentHandler.h
-SOURCES += $$ODF_LIB_ROOT/test/StringDocumentHandler.cxx
+#HEADERS += $$ODF_LIB_ROOT/test/StringDocumentHandler.h
+#SOURCES += $$ODF_LIB_ROOT/test/StringDocumentHandler.cxx
 
 SOURCES += IWork.cpp
 

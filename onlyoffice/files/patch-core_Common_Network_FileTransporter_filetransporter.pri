--- core/Common/Network/FileTransporter/filetransporter.pri.orig	2026-11-05 00:00:00 UTC
+++ core/Common/Network/FileTransporter/filetransporter.pri
@@ -57,6 +57,12 @@
 
 use_external_transport:DEFINES += USE_EXTERNAL_TRANSPORT
 
+core_freebsd {
+    !use_external_transport:include($$PWD/../../3dParty/curl/curl.pri)
+    LIBS += -lcurl
+    SOURCES += $$PWD/src/FileTransporter_curl.cpp
+}
+
 core_linux {
     !use_external_transport:include($$PWD/../../3dParty/curl/curl.pri)
     SOURCES += $$PWD/src/FileTransporter_curl.cpp

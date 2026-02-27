--- core/Common/Network/FileTransporter/filetransporter.pri.orig	2025-09-23 22:49:53 UTC
+++ core/Common/Network/FileTransporter/filetransporter.pri
@@ -24,6 +24,12 @@ use_external_transport:DEFINES += USE_EXTERNAL_TRANSPO
 
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

--- core/Common/3dParty/cryptopp/project/cryptopp.pro.orig	2026-11-05 00:00:00 UTC
+++ core/Common/3dParty/cryptopp/project/cryptopp.pro
@@ -11,6 +11,7 @@
 
 include(../../../../Common/base.pri)
 
+core_freebsd:DEFINES -= NDEBUG
 core_linux:DEFINES -= NDEBUG
 core_mac:DEFINES -= MAC
 core_ios:DEFINES -= MAC

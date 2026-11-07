--- core/Common/3dParty/heif/heif.pri.orig	2026-11-05 00:00:00 UTC
+++ core/Common/3dParty/heif/heif.pri
@@ -7,9 +7,13 @@
 
 HEIF_BUILD_PATH = $$PWD/libheif/build/$$HEIF_BUILDS_PLATFORM_PREFIX/$$CORE_BUILDS_CONFIGURATION_PREFIX
 
-INCLUDEPATH += \
-	$$PWD/libheif/libheif/api \
-	$$HEIF_BUILD_PATH				# for heif_version.h
+#INCLUDEPATH += \
+#	$$PWD/libheif/libheif/api \
+#	$$HEIF_BUILD_PATH				# for heif_version.h
+core_freebsd {
+	INCLUDEPATH += %%LOCALBASE%%/include/libheif
+	LIBS += -L%%LOCALBASE%%/lib -lheif
+ }
 
 core_windows {
 	core_debug {

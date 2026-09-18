--- core/Common/3dParty/boost/boost.pri.orig	2025-09-23 22:49:58 UTC
+++ core/Common/3dParty/boost/boost.pri
@@ -1,5 +1,11 @@
-INCLUDEPATH += $$PWD/build/$$CORE_BUILDS_PLATFORM_PREFIX/include
-CORE_BOOST_LIBS = $$PWD/build/$$CORE_BUILDS_PLATFORM_PREFIX/lib
+!core_freebsd {
+    INCLUDEPATH += $$PWD/build/$$CORE_BUILDS_PLATFORM_PREFIX/include
+    CORE_BOOST_LIBS = $$PWD/build/$$CORE_BUILDS_PLATFORM_PREFIX/lib
+}
+core_freebsd {
+    INCLUDEPATH += %%LOCALBASE%%/include
+    CORE_BOOST_LIBS = %%LOCALBASE%%/lib
+}
 
 core_ios:CONFIG += disable_enum_constexpr_conversion
 core_android:CONFIG += disable_enum_constexpr_conversion

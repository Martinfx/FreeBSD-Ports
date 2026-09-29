--- core/Common/3dParty/boost/boost.pri.orig	2026-09-24 21:58:50 UTC
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
@@ -40,7 +46,9 @@ core_windows {
     core_boost_regex:LIBS += -L$$CORE_BOOST_LIBS -llibboost_regex$$BOOST_POSTFIX
     core_boost_date_time:LIBS += -L$$CORE_BOOST_LIBS -llibboost_date_time$$BOOST_POSTFIX
 } else {
-    core_boost_libs:LIBS += -L$$CORE_BOOST_LIBS -lboost_system -lboost_filesystem
+    # Boost.System is header only, libboost_system is gone since Boost 1.89
+    core_freebsd:core_boost_libs:LIBS += -L$$CORE_BOOST_LIBS -lboost_filesystem
+    !core_freebsd:core_boost_libs:LIBS += -L$$CORE_BOOST_LIBS -lboost_system -lboost_filesystem
     core_boost_regex:LIBS += -L$$CORE_BOOST_LIBS -lboost_regex
     core_boost_date_time:LIBS += -L$$CORE_BOOST_LIBS -lboost_date_time
 }

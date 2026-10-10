--- gui/src/mainwindow.cpp.orig	2026-10-10 00:00:00 UTC
+++ gui/src/mainwindow.cpp
@@ -515,14 +515,14 @@
         locale_name = QLocale::system().name();
     }
 
-    // Apply the new translator
+    // Apply the new translator. The interface is written in English, so a
+    // locale that has no translation of its own, the C locale included, is
+    // not an error: leave the strings untranslated instead of refusing.
     if (m_translator.load(":/i18n/video2x-qt6_" + locale_name + ".qm")) {
         qApp->installTranslator(&m_translator);
     } else {
-        execErrorMessage("Failed to load translation for locale: " + locale_name);
-        video2x::logger()->error("Failed to load translation for locale: {}.",
-                                 locale_name.toStdString());
-        return false;
+        video2x::logger()->warn("No translation for locale: {}, using English.",
+                                locale_name.toStdString());
     }
 
     // Set the new UI font

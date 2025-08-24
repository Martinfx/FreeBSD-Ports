--- src/qt_gui/compatibility_info.h.orig	2025-04-06 14:05:53 UTC
+++ src/qt_gui/compatibility_info.h
@@ -37,6 +37,12 @@ enum class OSType {
     Unknown,
     Linux,
     Win32,
+#elif defined(Q_OS_FREEBSD)
+	FreeBSD = 0,   
+	macOS,
+    Unknown,
+    Linux,
+    Win32,
 #endif
     // Fake enum to allow for iteration
     Last
@@ -65,12 +71,14 @@ class CompatibilityInfoClass : public QObject { (publi
         {QStringLiteral("os-linux"), OSType::Linux},
         {QStringLiteral("os-macOS"), OSType::macOS},
         {QStringLiteral("os-windows"), OSType::Win32},
+		{QStringLiteral("os-freebsd"), OSType::FreeBSD},
     };
 
     inline static const std::unordered_map<OSType, QString> OSTypeToString = {
         {OSType::Linux, QStringLiteral("os-linux")},
         {OSType::macOS, QStringLiteral("os-macOS")},
         {OSType::Win32, QStringLiteral("os-windows")},
+ 		{OSType::FreeBSD, QStringLiteral("os-freebsd")},
         {OSType::Unknown, QStringLiteral("os-unknown")}};
 
     CompatibilityInfoClass();
@@ -85,4 +93,4 @@ class CompatibilityInfoClass : public QObject { (publi
     QNetworkAccessManager* m_network_manager;
     QString m_compatibility_filename;
     QJsonObject m_compatibility_database;
-};
\ No newline at end of file
+};

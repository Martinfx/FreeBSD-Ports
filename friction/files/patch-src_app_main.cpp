--- src/app/main.cpp.orig	2025-12-23 21:50:49 UTC
+++ src/app/main.cpp
@@ -105,7 +105,7 @@ int main(int argc, char *argv[])
     setlocale(LC_NUMERIC, "C");
 
     // handle XDG args
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_LINUX || Q_OS_FREEBSD
     const auto handleXDGActs = AppSupport::handleXDGArgs(isRenderer,
                                                          QApplication::arguments());
     if (handleXDGActs.first) { return handleXDGActs.second; }
@@ -208,7 +208,7 @@ int main(int argc, char *argv[])
     AppSupport::handlePortableFirstRun();
 
     // check XDG integration
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_LINUX || Q_OS_FREEBSD
     AppSupport::initXDGDesktop(isRenderer);
 #endif
 

--- desktop-apps/win-linux/src/cascapplicationmanagerwrapper.cpp.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/src/cascapplicationmanagerwrapper.cpp
@@ -361,7 +361,7 @@ bool CAscApplicationManagerWrapper::proc
                     gotoMainWindow();
 
                 mainWindow()->onFileLocation(-1, QString::fromStdWString(pData->get_Param()));
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
                 mainWindow()->bringToTop();
 #endif
                 return true;
@@ -1288,7 +1288,7 @@ void CAscApplicationManagerWrapper::init
 
     // TODO: merge stylesheets and apply for the whole app
     QString css{Utils::readStylesheets(":styles/styles.qss")};
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     css.append(Utils::readStylesheets(":styles/styles_unix.qss"));
 #endif
     qApp->setStyleSheet(css.arg(GetColorQValueByRole(ecrWindowBackground),
@@ -1353,7 +1353,7 @@ void CAscApplicationManagerWrapper::init
                                         {"type", _app.m_themes->current().stype()},
                                         {"id", QString::fromStdWString(_app.m_themes->current().id())},
                                         {"addlocal", "on"}
-#ifndef Q_OS_LINUX
+#if !defined(Q_OS_LINUX) && !defined(Q_OS_FREEBSD)
                                         ,{"system", _app.m_themes->isSystemSchemeDark() ? "dark" : "light"}
 #else
                                         ,{"system", "disabled"}
@@ -2023,7 +2023,7 @@ void CAscApplicationManagerWrapper::appl
         EditorJSVariables::applyVariable("theme", {
                                             {"type", _app.m_themes->current().stype()},
                                             {"id", QString::fromStdWString(_app.m_themes->current().id())}
-#ifndef Q_OS_LINUX
+#if !defined(Q_OS_LINUX) && !defined(Q_OS_FREEBSD)
                                             ,{"system", _app.m_themes->isSystemSchemeDark() ? "dark" : "light"}
 #else
                                             ,{"system", "disabled"}

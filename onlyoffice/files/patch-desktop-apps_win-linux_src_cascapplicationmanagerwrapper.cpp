--- desktop-apps/win-linux/src/cascapplicationmanagerwrapper.cpp.orig	2026-09-28 08:45:35 UTC
+++ desktop-apps/win-linux/src/cascapplicationmanagerwrapper.cpp
@@ -361,7 +361,7 @@ bool CAscApplicationManagerWrapper::proc
                     gotoMainWindow();
 
                 mainWindow()->onFileLocation(-1, QString::fromStdWString(pData->get_Param()));
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
                 mainWindow()->bringToTop();
 #endif
                 return true;
@@ -500,7 +500,7 @@ bool CAscApplicationManagerWrapper::proc
 
     case ASC_MENU_EVENT_TYPE_REPORTER_CREATE: {
         CPresenterWindow * reporterWindow = createReporterWindow(event->m_pData, event->get_SenderId());
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
         reporterWindow->show(false);
 #else
         reporterWindow->show(false);
@@ -1143,7 +1143,7 @@ void CAscApplicationManagerWrapper::star
 #if 0
     CMainWindow * _window = createMainWindow(_start_rect);
 
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
     _window->show();
     if ( _is_maximized )
         _window->slot_windowChangeState(Qt::WindowMaximized);
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

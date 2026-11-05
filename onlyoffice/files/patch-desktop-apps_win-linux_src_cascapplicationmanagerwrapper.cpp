--- desktop-apps/win-linux/src/cascapplicationmanagerwrapper.cpp.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/cascapplicationmanagerwrapper.cpp
@@ -556,7 +556,7 @@
                     gotoMainWindow();
 
                 mainWindow()->onFileLocation(-1, QString::fromStdWString(pData->get_Param()));
-#ifdef Q_OS_LINUX
+#if (defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)) || defined(Q_OS_FREEBSD)
                 mainWindow()->bringToTop();
 #endif
                 return true;
@@ -707,7 +707,7 @@
 
     case ASC_MENU_EVENT_TYPE_REPORTER_CREATE: {
         CPresenterWindow * reporterWindow = createReporterWindow(event->m_pData, event->get_SenderId());
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
         reporterWindow->show(false);
 #else
         reporterWindow->show(false);
@@ -1488,7 +1488,7 @@
 #if 0
     CMainWindow * _window = createMainWindow(_start_rect);
 
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
     _window->show();
     if ( _is_maximized )
         _window->slot_windowChangeState(Qt::WindowMaximized);
@@ -1631,7 +1631,7 @@
 
     // TODO: merge stylesheets and apply for the whole app
     QString css{Utils::readStylesheets(":styles/styles.qss")};
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     css.append(Utils::readStylesheets(":styles/styles_unix.qss"));
 #endif
     qApp->setStyleSheet(css.arg(GetColorQValueByRole(ecrWindowBackground),
@@ -2071,7 +2071,7 @@
     if (rc.left() < scrRc.left())
         rc.moveLeft(scrRc.left());
 
-#ifdef __linux__
+#if (defined(__linux__) || defined(__FreeBSD__)) || defined(__FreeBSD__)
     WindowHelper::CParentDisable oDisabler(parent);
 #endif
     _app.m_private->m_upgradeDialog = new UpgradeDialog(parent, rc, page);

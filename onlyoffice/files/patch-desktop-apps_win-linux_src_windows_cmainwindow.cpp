--- desktop-apps/win-linux/src/windows/cmainwindow.cpp.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/src/windows/cmainwindow.cpp
@@ -82,7 +82,7 @@ CMainWindow::CMainWindow(const QRect &re
     m_pMainPanel = createMainPanel(this);
     setCentralWidget(m_pMainPanel);
     QString css{AscAppManager::getWindowStylesheets(m_dpiRatio)};
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (WindowHelper::getEnvInfo() == WindowHelper::KDE)
         setWindowTitle(tr("Main Window"));
     setAcceptDrops(true);
@@ -247,7 +247,7 @@ void CMainWindow::applyTheme(const std::
     // }
 
     QString css{AscAppManager::getWindowStylesheets(m_dpiRatio)};
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     css.append(Utils::readStylesheets(":styles/styles_unix.qss"));
 #endif
     m_pMainPanel->setStyleSheet(css);
@@ -362,7 +362,7 @@ void CMainWindow::close()
 //    }
 //}
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 void CMainWindow::dragEnterEvent(QDragEnterEvent *event)
 {
     QList<QUrl> urls = event->mimeData()->urls();
@@ -628,7 +628,7 @@ void CMainWindow::onEditorAllowedClose(i
 void CMainWindow::onTabChanged(int index)
 {
     QString title("");
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (WindowHelper::getEnvInfo() == WindowHelper::KDE)
         title = tr("Main Window");
 #endif
@@ -1340,7 +1340,7 @@ void CMainWindow::onDocumentPrint(void *
         return;
 
     QWidget *parent = qobject_cast<QWidget*>(this);
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     WindowHelper::CParentDisable disabler(parent);
 #endif
 
@@ -1412,7 +1412,7 @@ void CMainWindow::onDocumentPrint(void *
 
             QVector<PageRanges> page_ranges;
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
             if ( printer->outputFormat() == QPrinter::PdfFormat ) {
                 if ( !AscAppManager::printData().isQuickPrint() ) {
                     info.setFile(printer->outputFileName());
@@ -1686,7 +1686,7 @@ void CMainWindow::setScreenScalingFactor
 {
     CWindowPlatform::setScreenScalingFactor(factor, resize);
     QString css(AscAppManager::getWindowStylesheets(factor));
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     css.append(Utils::readStylesheets(":styles/styles_unix.qss"));
 #endif
     if (!css.isEmpty()) {

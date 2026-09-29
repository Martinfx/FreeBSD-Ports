--- desktop-apps/win-linux/src/windows/ceditorwindow.cpp.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/src/windows/ceditorwindow.cpp
@@ -252,7 +252,7 @@ QWidget * CEditorWindow::createMainPanel
     mainPanel->setProperty("zoom", QString::number(m_dpiRatio) + "x");
     mainPanel->setProperty("uitheme", QString::fromStdWString(GetCurrentTheme().id()));
     QString css(AscAppManager::getWindowStylesheets(m_dpiRatio) + m_css);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     css.append(Utils::readStylesheets(":styles/styles_unix.qss"));
 #endif
     mainPanel->setStyleSheet(css);
@@ -291,7 +291,7 @@ void CEditorWindow::init(CTabPanel *pane
     d_ptr.get()->init(panel);
     m_pMainPanel = createMainPanel(this, d_ptr->panel()->data()->title());
     setCentralWidget(m_pMainPanel);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (isCustomWindowStyle()) {
         CX11Decoration::setTitleWidget(m_boxTitleBtns);
         m_pMainPanel->setMouseTracking(true);
@@ -519,7 +519,7 @@ void CEditorWindow::setScreenScalingFact
 
     QString css(AscAppManager::getWindowStylesheets(factor));
     css.append(m_css);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     css.append(Utils::readStylesheets(":styles/styles_unix.qss"));
 #endif
     m_pMainPanel->setStyleSheet(css);

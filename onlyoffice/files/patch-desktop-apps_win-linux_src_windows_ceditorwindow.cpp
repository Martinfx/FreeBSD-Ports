--- desktop-apps/win-linux/src/windows/ceditorwindow.cpp.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/windows/ceditorwindow.cpp
@@ -259,7 +259,7 @@
     mainPanel->setProperty("zoom", QString::number(m_dpiRatio) + "x");
     mainPanel->setProperty("uitheme", QString::fromStdWString(GetCurrentTheme().id()));
     QString css(AscAppManager::getWindowStylesheets(m_dpiRatio) + m_css);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     css.append(Utils::readStylesheets(":styles/styles_unix.qss"));
     if ( m_shouldUseThinFrame )
         mainPanel->setProperty("extended-title", true);
@@ -300,7 +300,7 @@
     d_ptr.get()->init(panel);
     m_pMainPanel = createMainPanel(this, d_ptr->panel()->data()->title());
     setCentralWidget(m_pMainPanel);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (isCustomWindowStyle()) {
         CX11Decoration::setTitleWidget(m_boxTitleBtns);
         m_pMainPanel->setMouseTracking(true);
@@ -534,7 +534,7 @@
 
     QString css(AscAppManager::getWindowStylesheets(factor));
     css.append(m_css);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     css.append(Utils::readStylesheets(":styles/styles_unix.qss"));
 #endif
     m_pMainPanel->setStyleSheet(css);

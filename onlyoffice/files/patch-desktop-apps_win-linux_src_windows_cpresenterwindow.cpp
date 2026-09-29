--- desktop-apps/win-linux/src/windows/cpresenterwindow.cpp.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/src/windows/cpresenterwindow.cpp
@@ -46,7 +46,7 @@ CPresenterWindow::CPresenterWindow(const
 {    
     m_pMainPanel = createMainPanel(this, title, static_cast<QWidget*>(view));
     setCentralWidget(m_pMainPanel);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (isCustomWindowStyle()) {
         CX11Decoration::setTitleWidget(m_boxTitleBtns);
         m_pMainPanel->setMouseTracking(true);
@@ -105,7 +105,7 @@ QWidget * CPresenterWindow::createMainPa
     mainPanel->setProperty("rtl-font", CLangater::isRtlLanguage(CLangater::getCurrentLangCode()));
     mainPanel->setProperty("uitheme", QString::fromStdWString(GetCurrentTheme().id()));
     QString css(AscAppManager::getWindowStylesheets(m_dpiRatio));
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     css.append(Utils::readStylesheets(":styles/styles_unix.qss"));
 #endif
     mainPanel->setStyleSheet(css);
@@ -131,7 +131,7 @@ QWidget * CPresenterWindow::createMainPa
         delete stretch;
 
     if (isCustomWindowStyle()) {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         m_labelTitle->setMouseTracking(true);
         //mainGridLayout->setMargin(CX11Decoration::customWindowBorderWith() * m_dpiRatio);
         /*QPalette _palette(palette());
@@ -173,7 +173,7 @@ void CPresenterWindow::setScreenScalingF
 {
     CWindowPlatform::setScreenScalingFactor(factor, resize);
     QString css(AscAppManager::getWindowStylesheets(factor));
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     css.append(Utils::readStylesheets(":styles/styles_unix.qss"));
 #endif
     if (!css.isEmpty()) {                

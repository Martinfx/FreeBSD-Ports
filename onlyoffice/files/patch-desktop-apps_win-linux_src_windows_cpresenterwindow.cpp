--- desktop-apps/win-linux/src/windows/cpresenterwindow.cpp.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/windows/cpresenterwindow.cpp
@@ -50,7 +50,7 @@
 {    
     m_pMainPanel = createMainPanel(this, title, static_cast<QWidget*>(view));
     setCentralWidget(m_pMainPanel);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (isCustomWindowStyle()) {
         CX11Decoration::setTitleWidget(m_boxTitleBtns);
         m_pMainPanel->setMouseTracking(true);
@@ -110,7 +110,7 @@
     mainPanel->setProperty("rtl-font", CLangater::isRtlLanguage(CLangater::getCurrentLangCode()));
     mainPanel->setProperty("uitheme", QString::fromStdWString(GetCurrentTheme().id()));
     QString css(AscAppManager::getWindowStylesheets(m_dpiRatio));
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     css.append(Utils::readStylesheets(":styles/styles_unix.qss"));
 #endif
     mainPanel->setStyleSheet(css);
@@ -136,7 +136,7 @@
         delete stretch;
 
     if (isCustomWindowStyle()) {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         m_labelTitle->setMouseTracking(true);
         //mainGridLayout->setMargin(CX11Decoration::effectiveFrameMargin());
         /*QPalette _palette(palette());
@@ -178,7 +178,7 @@
 {
     CWindowPlatform::setScreenScalingFactor(factor, resize);
     QString css(AscAppManager::getWindowStylesheets(factor));
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     css.append(Utils::readStylesheets(":styles/styles_unix.qss"));
 #endif
     if (!css.isEmpty()) {                

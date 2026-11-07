--- desktop-apps/win-linux/src/windows/cwindowbase.cpp.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/windows/cwindowbase.cpp
@@ -72,7 +72,7 @@
     const QRect minRect = adjustWindowRect(QRect(0, 0, WINDOW_MIN_WIDTH * m_dpiRatio,
                                                  WINDOW_MIN_HEIGHT * m_dpiRatio), m_dpiRatio);
     setMinimumSize(minRect.size());
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     setGeometry(m_window_rect); // for Windows is set in CWindowPlatform
 #endif
 }
@@ -114,7 +114,7 @@
 
 QRect CWindowBase::adjustWindowRect(const QRect &rc, double dpi) const
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (WindowHelper::shouldUseThinFrame())
     {
         const int shadow = SHADOW_WIDTH * dpi;
@@ -166,7 +166,7 @@
     btn->setProperty("class", "normal");
     btn->setProperty("act", "tool");
     btn->setFixedSize(int(TITLEBTN_WIDTH*m_dpiRatio), int(m_toolbtn_height * m_dpiRatio));
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     btn->setMouseTracking(true);
     btn->setProperty("unix", true);
     if (WindowHelper::getEnvInfo() == WindowHelper::KDE)
@@ -180,7 +180,7 @@
 QWidget* CWindowBase::createTopPanel(QWidget *parent)
 {
     QWidget *_boxTitleBtns;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     _boxTitleBtns = new QWidget(parent);
 #else
     _boxTitleBtns = static_cast<QWidget*>(new Caption(parent));

--- desktop-apps/win-linux/src/windows/cwindowbase.cpp.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/src/windows/cwindowbase.cpp
@@ -49,7 +49,7 @@ class CWindowBase::CWindowBasePrivate
 {
 public:
     CWindowBasePrivate() {
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
         GET_REGISTRY_SYSTEM(reg_system)
         GET_REGISTRY_USER(reg_user)
         if ( reg_user.value("titlebar") == "custom" ||
@@ -75,7 +75,7 @@ CWindowBase::CWindowBase(const QRect& re
     setWindowIcon(Utils::appIcon());
     m_window_rect = startRect(rect, m_dpiRatio);
     setMinimumSize(WINDOW_MIN_WIDTH * m_dpiRatio, WINDOW_MIN_HEIGHT * m_dpiRatio);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     setGeometry(m_window_rect); // for Windows is set in CWindowPlatform
 #endif
 }
@@ -146,7 +146,7 @@ CPushButton* CWindowBase::createToolButt
     btn->setProperty("class", "normal");
     btn->setProperty("act", "tool");
     btn->setFixedSize(int(TITLEBTN_WIDTH*m_dpiRatio), int(m_toolbtn_height * m_dpiRatio));
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     btn->setMouseTracking(true);
     btn->setProperty("unix", true);
     if (WindowHelper::getEnvInfo() == WindowHelper::KDE)
@@ -160,7 +160,7 @@ CPushButton* CWindowBase::createToolButt
 QWidget* CWindowBase::createTopPanel(QWidget *parent)
 {
     QWidget *_boxTitleBtns;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     _boxTitleBtns = new QWidget(parent);
 #else
     _boxTitleBtns = static_cast<QWidget*>(new Caption(parent));

--- desktop-apps/win-linux/src/utils.cpp.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/src/utils.cpp
@@ -30,7 +30,7 @@
  *
 */
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 # include "platform_linux/gtkutils.h"
 #endif
 #include "utils.h"
@@ -560,7 +560,7 @@ double Utils::getScreenDpiRatio(const QP
     QWidget _w;
     _w.setGeometry(QRect(pt, QSize(10,10)));
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     return getScreenDpiRatioByWidget(&_w);
 #else
     return getScreenDpiRatioByHWND(_w.winId());
@@ -583,7 +583,7 @@ double Utils::getScreenDpiRatioByWidget(
     unsigned int nDpiX = 0;
     unsigned int nDpiY = 0;
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     QDpiChecker * pChecker = (QDpiChecker *)AscAppManager::getInstance().GetDpiChecker();
     int nResult = pChecker->GetWidgetDpi(wid, &nDpiX, &nDpiY);
     double dpiApp = pChecker->GetScale(nDpiX, nDpiY);
@@ -930,7 +930,7 @@ std::wstring Utils::appUserName()
 
 
 namespace WindowHelper {
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     CParentDisable::CParentDisable(QWidget* &parent)
     {
         disable(parent);
@@ -1108,7 +1108,7 @@ namespace WindowHelper {
 //    }
 
     auto isLeftButtonPressed() -> bool {
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
         return check_button_state(Qt::LeftButton);
 #else
         return (::GetKeyState(VK_LBUTTON) & 0x8000) != 0;

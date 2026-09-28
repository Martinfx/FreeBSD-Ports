--- desktop-apps/win-linux/src/utils.cpp.orig	2026-09-28 08:45:35 UTC
+++ desktop-apps/win-linux/src/utils.cpp
@@ -30,7 +30,7 @@
  *
 */
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 # include "platform_linux/gtkutils.h"
 #endif
 #include "utils.h"
@@ -299,7 +299,7 @@ void Utils::keepLastPath(int t, const QS
 
 bool Utils::makepath(const QString& p)
 {
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
     mode_t _mask = umask(0);
     (_mask & S_IRWXO) && umask(_mask & ~S_IRWXO);
 #endif
@@ -321,7 +321,7 @@ QRect Utils::getScreenGeometry(const QPo
 {
 //    int _scr_num = QApplication::desktop()->screenNumber(leftTop); - return the wrong number
 //    return QApplication::desktop()->screenGeometry(_scr_num);
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
     auto pointToRect = [](const QPoint &p, const QRect &r) -> int {
         int dx = 0, dy = 0;
         if (p.x() < r.left()) dx = r.left() - p.x(); else
@@ -380,7 +380,7 @@ QString Utils::systemLocationCode()
 
 void Utils::openUrl(const QString& url)
 {
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
     QUrl _url(url);
     if ( _url.scheme() == "mailto" ) {
         system(QString("LD_LIBRARY_PATH='' xdg-email %1")                   // xdg-email filepath email
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

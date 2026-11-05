--- desktop-apps/win-linux/src/utils.cpp.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/utils.cpp
@@ -33,7 +33,7 @@
  * SPDX-License-Identifier: AGPL-3.0-only
  */
 
-#ifdef __linux__
+#if (defined(__linux__) || defined(__FreeBSD__)) || defined(__FreeBSD__)
 # include "platform_linux/gtkutils.h"
 #endif
 #include "utils.h"
@@ -164,7 +164,7 @@
     auto init() -> void {
 #if defined(__OS_WIN_XP)
         vars_object["os"] = "winxp";
-#elif defined(__linux__)
+#elif (defined(__linux__) || defined(__FreeBSD__))
         vars_object["os"] = "linux";
 #endif
         if ( InputArgs::contains(L"--help-url") )
@@ -309,7 +309,7 @@
 
 bool Utils::makepath(const QString& p)
 {
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
     mode_t _mask = umask(0);
     (_mask & S_IRWXO) && umask(_mask & ~S_IRWXO);
 #endif
@@ -331,7 +331,7 @@
 {
 //    int _scr_num = QApplication::desktop()->screenNumber(leftTop); - return the wrong number
 //    return QApplication::desktop()->screenGeometry(_scr_num);
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
     auto pointToRect = [](const QPoint &p, const QRect &r) -> int {
         int dx = 0, dy = 0;
         if (p.x() < r.left()) dx = r.left() - p.x(); else
@@ -388,7 +388,7 @@
 #endif
 }
 
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
 // Wrap an argument for /bin/sh in single quotes: inside them nothing is
 // interpreted ($(), backticks, ; ...), the only special case is ' itself.
 static std::string shell_quote(const std::string& s)
@@ -403,7 +403,7 @@
 
 void Utils::openUrl(const QString& url)
 {
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
     QUrl _url(url);
     if ( _url.scheme() == "mailto" ) {
         std::string sCommand = "LD_LIBRARY_PATH='' xdg-email " +
@@ -656,7 +656,7 @@
     unsigned int nDpiX = 0;
     unsigned int nDpiY = 0;
 
-#ifdef Q_OS_LINUX
+#if (defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)) || defined(Q_OS_FREEBSD)
     QDpiChecker * pChecker = (QDpiChecker *)AscAppManager::getInstance().GetDpiChecker();
     int nResult = pChecker->GetWidgetDpi(wid, &nDpiX, &nDpiY);
     double dpiApp = pChecker->GetScale(nDpiX, nDpiY);
@@ -1002,7 +1002,7 @@
 
 
 namespace WindowHelper {
-#ifdef Q_OS_LINUX
+#if (defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)) || defined(Q_OS_FREEBSD)
     CParentDisable::CParentDisable(QWidget* parent) : m_parent(parent)
     {
         enable(false);
@@ -1164,7 +1164,7 @@
 
     auto isCustomWindowStyle() -> bool {
         static const bool value = []() {
-#ifdef Q_OS_LINUX
+#if (defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)) || defined(Q_OS_FREEBSD)
             GET_REGISTRY_SYSTEM(reg_system)
             GET_REGISTRY_USER(reg_user)
             return (reg_user.value("titlebar") == "custom" ||
@@ -1179,7 +1179,7 @@
 
     auto shouldUseThinFrame() -> bool {
         static const bool value = []() {
-#ifdef Q_OS_LINUX
+#if (defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)) || defined(Q_OS_FREEBSD)
             return isCustomWindowStyle() && QX11Info::isCompositingManagerRunning();
 #else
             return isCustomWindowStyle() && Utils::getWinVersion() >= Utils::WinVer::Win10;
@@ -1190,7 +1190,7 @@
     }
 
     auto isLeftButtonPressed() -> bool {
-#ifdef Q_OS_LINUX
+#if (defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)) || defined(Q_OS_FREEBSD)
         return check_button_state(Qt::LeftButton);
 #else
         return (::GetKeyState(VK_LBUTTON) & 0x8000) != 0;

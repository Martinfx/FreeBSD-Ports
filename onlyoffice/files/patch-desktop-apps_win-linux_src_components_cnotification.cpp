--- desktop-apps/win-linux/src/components/cnotification.cpp.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/components/cnotification.cpp
@@ -56,7 +56,7 @@
 
 #define NOTIF_TIMEOUT_MS 10000
 
-#ifdef __linux__
+#if (defined(__linux__) || defined(__FreeBSD__)) || defined(__FreeBSD__)
 struct NtfData
 {
     FnVoidInt callback;
@@ -199,7 +199,7 @@
 class CNotification::CNotificationPrivate
 {
 public:
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     ~CNotificationPrivate()
     {
         clear();
@@ -227,7 +227,7 @@
                                                const QStringList &btns, const std::vector<int> &results,
                                                const FnVoidInt &callback)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (!isNotificationsEnabled())
         return false;
     QString lpText = QTextDocumentFragment::fromHtml(msg).toPlainText();
@@ -279,7 +279,7 @@
 CNotification::~CNotification()
 {
     delete pimpl, pimpl = nullptr;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (notify_is_initted())
         notify_uninit();
 #endif
@@ -290,7 +290,7 @@
     if (pimpl->isInit != -1)
         return pimpl->isInit;
 
-#ifdef __linux__
+#if (defined(__linux__) || defined(__FreeBSD__)) || defined(__FreeBSD__)
     pimpl->isInit = notify_init(WINDOW_TITLE);
 #else
     if (Utils::getWinVersion() < Utils::WinVer::Win10) {
@@ -321,7 +321,7 @@
 void CNotification::clear()
 {
     if (pimpl->isInit == 1)
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         pimpl->clear();
 #else
         WinToast::instance()->clear();

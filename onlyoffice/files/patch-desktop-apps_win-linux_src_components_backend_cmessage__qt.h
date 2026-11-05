--- desktop-apps/win-linux/src/components/backend/cmessage_qt.h.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/components/backend/cmessage_qt.h
@@ -377,7 +377,7 @@
 inline int MessageQtBackend::showMessage(QWidget *parent, const QString &msg, CMessage::Icon msgIcon,
                                          CMessage::Buttons msgBtns, const CMessage::Config &conf)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     WindowHelper::CParentDisable oDisabler(parent);
 #endif
     MessageQtBackend dlg(parent);

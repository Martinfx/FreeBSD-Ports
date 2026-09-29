--- desktop-apps/win-linux/src/ccefeventstransformer.cpp.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/src/ccefeventstransformer.cpp
@@ -121,7 +121,7 @@ void CCefEventsTransformer::OnEvent(QObj
     case ASC_MENU_EVENT_TYPE_CEF_ONBEFORE_PRINT_PROGRESS: break;
 
     case ASC_MENU_EVENT_TYPE_CEF_ONBEFORE_PRINT_END: {
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
         QTimer::singleShot(0, pObjTarget, [target]{
             QMetaObject::invokeMethod(target, "onDocumentPrint", Qt::QueuedConnection, Q_ARG(void*, nullptr));
         });

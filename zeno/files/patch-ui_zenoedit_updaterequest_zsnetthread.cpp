--- ui/zenoedit/updaterequest/zsnetthread.cpp.orig	2024-04-22 13:39:23 UTC
+++ ui/zenoedit/updaterequest/zsnetthread.cpp
@@ -37,7 +37,7 @@ void ZsNetThread::run()
 
 void ZsNetThread::netGet()
 {
-#ifdef __linux__
+#if defined( __linux__) || defined(__FreeBSD__)
     return;
 #else
     CURL* curl;
@@ -73,4 +73,4 @@ void ZsNetThread::netGet()
 
     emit netReqFinish(data, m_id);
 #endif
-}
\ No newline at end of file
+}

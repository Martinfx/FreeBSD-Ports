--- desktop-apps/win-linux/src/windows/cmainwindow.h.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/src/windows/cmainwindow.h
@@ -79,7 +79,7 @@ signals:
 
 private:
 //    void captureMouse(int);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     virtual void dragEnterEvent(QDragEnterEvent *event) final;
     virtual void dropEvent(QDropEvent *event) final;
 #endif

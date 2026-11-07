--- desktop-apps/win-linux/src/windows/cmainwindow.h.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/windows/cmainwindow.h
@@ -82,7 +82,7 @@
 
 private:
 //    void captureMouse(int);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     virtual void dragEnterEvent(QDragEnterEvent *event) final;
     virtual void dropEvent(QDropEvent *event) final;
 #endif
@@ -103,7 +103,7 @@
     bool slideshowHoldUrl(const QString&, AscEditorType) const;
     int  startPanelId();
     int  tabCloseRequest(int index = -1);
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
     void setMouseTracking(bool);
 #endif
     void doOpenLocalFile(COpenOptions&);

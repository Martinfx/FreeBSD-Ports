--- desktop-apps/win-linux/src/windows/cmainwindow.h.orig	2026-09-28 08:45:35 UTC
+++ desktop-apps/win-linux/src/windows/cmainwindow.h
@@ -79,7 +79,7 @@ signals:
 
 private:
 //    void captureMouse(int);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     virtual void dragEnterEvent(QDragEnterEvent *event) final;
     virtual void dropEvent(QDropEvent *event) final;
 #endif
@@ -100,7 +100,7 @@ public:
     bool slideshowHoldUrl(const QString&, AscEditorType) const;
     int  startPanelId();
     int  tabCloseRequest(int index = -1);
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
     void setMouseTracking(bool);
 #endif
     void doOpenLocalFile(COpenOptions&);

--- desktop-apps/win-linux/src/windows/cmainwindow.cpp.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/windows/cmainwindow.cpp
@@ -84,7 +84,7 @@
     m_pMainPanel = createMainPanel(this);
     setCentralWidget(m_pMainPanel);
     QString css{AscAppManager::getWindowStylesheets(m_dpiRatio)};
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (WindowHelper::getEnvInfo() == WindowHelper::KDE)
         setWindowTitle(tr("Main Window"));
     setAcceptDrops(true);
@@ -253,7 +253,7 @@
     // }
 
     QString css{AscAppManager::getWindowStylesheets(m_dpiRatio)};
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     css.append(Utils::readStylesheets(":styles/styles_unix.qss"));
 #endif
     m_pMainPanel->setStyleSheet(css);
@@ -371,7 +371,7 @@
 //    }
 //}
 
-#ifdef __linux__
+#if (defined(__linux__) || defined(__FreeBSD__)) || defined(__FreeBSD__)
 void CMainWindow::dragEnterEvent(QDragEnterEvent *event)
 {
     QList<QUrl> urls = event->mimeData()->urls();
@@ -511,8 +511,8 @@
     connect(pTabBar, SIGNAL(tabBarClicked(int)), this, SLOT(onTabClicked(int)), Qt::QueuedConnection);
     connect(pTabBar, SIGNAL(tabCloseRequested(int)), this, SLOT(onTabCloseRequest(int)));
     connect(pTabBar, &CTabBar::tabMenuRequested, this, &CMainWindow::setTabMenu);
-    connect(m_pTabs, &CAscTabWidget::editorInserted, bind(&CMainWindow::onTabsCountChanged, this, _2, _1, 1));
-    connect(m_pTabs, &CAscTabWidget::editorRemoved, bind(&CMainWindow::onTabsCountChanged, this, _2, _1, -1));
+    connect(m_pTabs, &CAscTabWidget::editorInserted, std::bind(&CMainWindow::onTabsCountChanged, this, _2, _1, 1));
+    connect(m_pTabs, &CAscTabWidget::editorRemoved, std::bind(&CMainWindow::onTabsCountChanged, this, _2, _1, -1));
     m_pTabs->setPalette(palette);
     m_pTabs->setCustomWindowParams(isCustomWindowStyle());
     return mainPanel;
@@ -521,7 +521,7 @@
 void CMainWindow::attachStartPanel(QCefView * const view)
 {
     m_pMainWidget = qobject_cast<QWidget *>(view);
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
     view->setMouseTracking(m_pButtonMain->hasMouseTracking());
 #endif
     m_pMainWidget->setParent(m_pMainPanel);
@@ -534,7 +534,7 @@
         m_pMainWidget->show();
 }
 
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
 void CMainWindow::setMouseTracking(bool enable)
 {
     QWidget::setMouseTracking(enable);
@@ -638,7 +638,7 @@
 void CMainWindow::onTabChanged(int index)
 {
     QString title("");
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (WindowHelper::getEnvInfo() == WindowHelper::KDE)
         title = tr("Main Window");
 #endif
@@ -1657,7 +1657,7 @@
 {
     CWindowPlatform::setScreenScalingFactor(factor, resize);
     QString css(AscAppManager::getWindowStylesheets(factor));
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     css.append(Utils::readStylesheets(":styles/styles_unix.qss"));
 #endif
     if (!css.isEmpty()) {

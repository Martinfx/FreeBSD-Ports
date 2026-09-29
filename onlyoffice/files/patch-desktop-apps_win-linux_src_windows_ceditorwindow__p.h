--- desktop-apps/win-linux/src/windows/ceditorwindow_p.h.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/src/windows/ceditorwindow_p.h
@@ -50,7 +50,7 @@
 #include <QPrintEngine>
 #include <QAction>
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 # include "platform_linux/gtkprintdialog.h"
 #else
 # include "platform_win/printdialog.h"
@@ -77,7 +77,7 @@ auto prepare_editor_css(AscEditorType ty
     case AscEditorType::etDraw: c = theme.value(CTheme::ColorRole::ecrTabDrawActive); break;
     }
     QString g_css(Utils::readStylesheets(":/styles/editor.qss"));
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     g_css.append(Utils::readStylesheets(":styles/editor_unix.qss"));
 #endif
     return g_css.arg(QString::fromStdWString(c), GetColorQValueByRole(ecrTextNormal), GetColorQValueByRole(ecrTextPretty));
@@ -541,7 +541,7 @@ public:
             window->m_css = prepare_editor_css(editor_type, GetCurrentTheme());
             QString css(AscAppManager::getWindowStylesheets(window->m_dpiRatio));
             css.append(window->m_css);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
             css.append(Utils::readStylesheets(":styles/styles_unix.qss"));
 #endif
             window->m_pMainPanel->setStyleSheet(css);
@@ -629,7 +629,7 @@ public:
         isPrinting = true;
 
         QWidget *parent = window->handle();
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
         WindowHelper::CParentDisable oDisabler(parent);
 #endif
         if ( !(pagescount < 1) ) {
@@ -693,7 +693,7 @@ public:
 
                 QVector<PageRanges> page_ranges;
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
                 if ( printer->outputFormat() == QPrinter::PdfFormat ) {
                     if ( !AscAppManager::printData().isQuickPrint() ) {
                         info.setFile(printer->outputFileName());

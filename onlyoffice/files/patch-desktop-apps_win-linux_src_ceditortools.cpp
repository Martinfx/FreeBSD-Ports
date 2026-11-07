--- desktop-apps/win-linux/src/ceditortools.cpp.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/ceditortools.cpp
@@ -120,7 +120,7 @@
         }
 #endif
 
-#ifdef Q_OS_LINUX
+#if (defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)) || defined(Q_OS_FREEBSD)
         WindowHelper::CParentDisable disabler(parent);
 #endif
         if (pView && !(pagesCount < 1)) {
@@ -188,7 +188,7 @@
 
                 QVector<PageRanges> page_ranges;
 
-#ifdef Q_OS_LINUX
+#if (defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)) || defined(Q_OS_FREEBSD)
                 if ( printer->outputFormat() == QPrinter::PdfFormat ) {
                     if ( !AscAppManager::printData().isQuickPrint() ) {
                         info.setFile(printer->outputFileName());

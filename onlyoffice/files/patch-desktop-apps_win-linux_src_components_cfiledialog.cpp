--- desktop-apps/win-linux/src/components/cfiledialog.cpp.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/components/cfiledialog.cpp
@@ -59,7 +59,7 @@
 
 namespace CFileDialogHelper {
     auto useModalDialog() -> bool {
-#if defined(__linux__) && defined(FILEDIALOG_DONT_USE_MODAL)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(FILEDIALOG_DONT_USE_MODAL)
         return false;
 #else
         return true;
@@ -184,7 +184,7 @@
         const QString title = (m_title.isEmpty()) ? tr("Save As") : m_title;
 
         if (WindowHelper::useNativeDialog()) {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
             QStringList result;
             if (WindowHelper::useGtkDialog()) {
                 result = Gtk::openGtkFileChooser(p, Gtk::Mode::SAVE, title,
@@ -330,13 +330,13 @@
     QWidget * _parent = CFileDialogHelper::useModalDialog() ?
                 (QWidget *)parent() : nullptr;
     QFileDialog::Options _opts;       
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     WindowHelper::CParentDisable oDisabler(_parent);
 #endif
     const QString title = (m_title.isEmpty()) ? tr("Open Document") : m_title;
 
     if (WindowHelper::useNativeDialog()) {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         if (WindowHelper::useGtkDialog()) {
             return Gtk::openGtkFileChooser(_parent, Gtk::Mode::OPEN, title, "",
                                            path, _filter_, &_sel_filter, multi);
@@ -495,13 +495,13 @@
                 (QWidget *)parent() : nullptr;
     QFileDialog::Options _opts{QFileDialog::ShowDirsOnly};
 
-#ifdef __linux__
+#if (defined(__linux__) || defined(__FreeBSD__)) || defined(__FreeBSD__)
     WindowHelper::CParentDisable oDisabler(_parent);
 #endif
     const QString title = (m_title.isEmpty()) ? tr("Select Folder") : m_title;
 
     if (WindowHelper::useNativeDialog()) {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         QStringList result;
         if (WindowHelper::useGtkDialog()) {
             result = Gtk::openGtkFileChooser(_parent, Gtk::Mode::FOLDER, title,
@@ -543,7 +543,7 @@
 
 int CFileDialogWrapper::getKey(const QString &value)
 {
-#ifdef Q_OS_LINUX
+#if (defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)) || defined(Q_OS_FREEBSD)
     QString _sv{value};
     if ( WindowHelper::getEnvInfo() == WindowHelper::GNOME ) {
         QRegularExpression _re_strbegin("^(.+)\\s\\（", QRegularExpression::CaseInsensitiveOption);

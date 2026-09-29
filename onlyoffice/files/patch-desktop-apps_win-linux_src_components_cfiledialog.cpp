--- desktop-apps/win-linux/src/components/cfiledialog.cpp.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/src/components/cfiledialog.cpp
@@ -54,7 +54,7 @@ static const char *IMAGE_TYPE = "image",
 
 namespace CFileDialogHelper {
     auto useModalDialog() -> bool {
-#if defined(__linux__) && defined(FILEDIALOG_DONT_USE_MODAL)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(FILEDIALOG_DONT_USE_MODAL)
         return false;
 #else
         return true;
@@ -164,7 +164,7 @@ bool CFileDialogWrapper::modalSaveAs(QSt
         const QString title = (m_title.isEmpty()) ? tr("Save As") : m_title;
 
         if (WindowHelper::useNativeDialog()) {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
             QStringList result;
             if (WindowHelper::useGtkDialog()) {
                 result = Gtk::openGtkFileChooser(p, Gtk::Mode::SAVE, title,
@@ -279,13 +279,13 @@ QStringList CFileDialogWrapper::modalOpe
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
@@ -424,13 +424,13 @@ QString CFileDialogWrapper::selectFolder
                 (QWidget *)parent() : nullptr;
     QFileDialog::Options _opts{QFileDialog::ShowDirsOnly};
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     WindowHelper::CParentDisable oDisabler(_parent);
 #endif
     const QString title = (m_title.isEmpty()) ? tr("Select Folder") : m_title;
 
     if (WindowHelper::useNativeDialog()) {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         QStringList result;
         if (WindowHelper::useGtkDialog()) {
             result = Gtk::openGtkFileChooser(_parent, Gtk::Mode::FOLDER, title,
@@ -472,7 +472,7 @@ void CFileDialogWrapper::setFormats(std:
 
 int CFileDialogWrapper::getKey(const QString &value)
 {
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     QString _sv{value};
     if ( WindowHelper::getEnvInfo() == WindowHelper::GNOME ) {
         QRegularExpression _re_strbegin("^(.+)\\s\\（", QRegularExpression::CaseInsensitiveOption);

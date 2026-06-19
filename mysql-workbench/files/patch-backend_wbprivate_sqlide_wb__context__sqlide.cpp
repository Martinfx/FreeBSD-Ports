--- backend/wbprivate/sqlide/wb_context_sqlide.cpp.orig	2024-05-20 06:21:54 UTC
+++ backend/wbprivate/sqlide/wb_context_sqlide.cpp
@@ -602,7 +602,7 @@ bool WBContextSQLIDE::auto_save_workspaces() {
   WBContext *wb = WBContextUI::get()->get_wb();
   ssize_t interval = wb->get_root()->options()->options().get_int("workbench:AutoSaveSQLEditorInterval", 60);
   if (interval <= 0 || !_auto_save_active) {
-    _auto_save_handle = static_cast<mforms::TimeoutHandle>(NULL);
+    _auto_save_handle = 0;
     _auto_save_active = false;
     return false;
   }
@@ -770,7 +770,7 @@ void WBContextSQLIDE::init() {
 void WBContextSQLIDE::finalize() {
   if (_auto_save_handle) {
     mforms::Utilities::cancel_timeout(_auto_save_handle);
-    _auto_save_handle = static_cast<mforms::TimeoutHandle>(NULL);
+    _auto_save_handle = 0;
   }
   std::list<SqlEditorForm::Ptr>::iterator next, ed = _open_editors.begin();
   while (ed != _open_editors.end()) {

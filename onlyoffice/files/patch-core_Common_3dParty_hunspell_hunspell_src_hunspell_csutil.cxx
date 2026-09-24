--- core/Common/3dParty/hunspell/hunspell/src/hunspell/csutil.cxx.orig	2026-09-24 21:58:50 UTC
+++ core/Common/3dParty/hunspell/hunspell/src/hunspell/csutil.cxx
@@ -2442,6 +2442,9 @@ void initialize_utf_tbl() {
 #endif
 
 void free_utf_tbl() {
+  // Keep the table, like core/Common/3dParty/hunspell/before.py does: it is
+  // shared by the Hunspell objects of the editors.
+  return;
   if (utf_tbl_count > 0)
     utf_tbl_count--;
   if (utf_tbl && (utf_tbl_count == 0)) {

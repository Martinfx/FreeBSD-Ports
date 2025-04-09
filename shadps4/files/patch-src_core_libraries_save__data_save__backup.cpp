--- src/core/libraries/save_data/save_backup.cpp.orig	2025-04-07 16:52:23 UTC
+++ src/core/libraries/save_data/save_backup.cpp
@@ -4,6 +4,7 @@
 #include <deque>
 #include <mutex>
 #include <semaphore>
+#include <thread>
 
 #include <magic_enum/magic_enum.hpp>
 
@@ -258,4 +259,4 @@ void ClearProgress() {
     g_backup_progress = 0;
 }
 
-} // namespace Libraries::SaveData::Backup
\ No newline at end of file
+} // namespace Libraries::SaveData::Backup

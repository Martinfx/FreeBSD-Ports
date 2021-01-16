--- build/src/tools/gn/src/base/files/file_posix.cc.orig	2021-01-15 20:16:07 UTC
+++ build/src/tools/gn/src/base/files/file_posix.cc
@@ -372,7 +372,7 @@ void File::DoInitialize(const FilePath& path, uint32_t
 bool File::Flush() {
   DCHECK(IsValid());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return !HANDLE_EINTR(fdatasync(file_.get()));
 #else
   return !HANDLE_EINTR(fsync(file_.get()));

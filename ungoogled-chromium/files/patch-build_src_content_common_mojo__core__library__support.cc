--- build/src/content/common/mojo_core_library_support.cc.orig	2021-01-15 20:30:57 UTC
+++ build/src/content/common/mojo_core_library_support.cc
@@ -15,7 +15,7 @@ bool IsMojoCoreSharedLibraryEnabled() {
 }
 
 base::Optional<base::FilePath> GetMojoCoreSharedLibraryPath() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   const base::CommandLine& command_line =
       *base::CommandLine::ForCurrentProcess();
   if (!command_line.HasSwitch(switches::kMojoCoreLibraryPath))

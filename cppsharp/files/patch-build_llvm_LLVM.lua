--- build/llvm/LLVM.lua.orig	2023-10-18 15:27:43 UTC
+++ build/llvm/LLVM.lua
@@ -32,7 +32,7 @@ function clone_llvm()
     extract = extract_tar_gz
   end
 
-  local archive = 'llvm-'..llvm_release..'.tar.gz'
+  local archive = '6eb36aed86ea276695697093eb8136554c29286b.tar.gz'
   if os.isfile(archive) then
     print('Archive '..archive..' already exists.')
   else

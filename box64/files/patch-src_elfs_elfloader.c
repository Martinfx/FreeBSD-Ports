--- src/elfs/elfloader.c.orig	2025-04-11 15:05:44 UTC
+++ src/elfs/elfloader.c
@@ -5,7 +5,11 @@
 #include <elf.h>
 #include <sys/mman.h>
 #include <sys/stat.h>
+#if __FreeBSD__
+#include <sys/types.h>
+#else
 #include <sys/sysmacros.h>
+#endif
 #include <sys/types.h>
 #include <link.h>
 #include <unistd.h>
@@ -236,10 +240,10 @@ int AllocLoadElfMemory(box64context_t* context, elfhea
     void* image = NULL;
     if(!head->vaddr) {
         sz += head->align;
-        raw = mmap64((void*)offs, sz, 0, MAP_ANONYMOUS|MAP_PRIVATE|MAP_NORESERVE, -1, 0);
+        raw = mmap64((void*)offs, sz, 0, MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);
         image = (void*)(((uintptr_t)raw+max_align)&~max_align);
     } else {
-        image = raw = mmap64((void*)head->vaddr, sz, 0, MAP_ANONYMOUS|MAP_PRIVATE|MAP_NORESERVE, -1, 0);
+        image = raw = mmap64((void*)head->vaddr, sz, 0, MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);
         if(head->vaddr&(box64_pagesize-1)) {
             // load address might be lower
             if((uintptr_t)image == (head->vaddr&~(box64_pagesize-1))) {

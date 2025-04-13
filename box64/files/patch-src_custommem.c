--- src/custommem.c.orig	2025-04-11 14:36:36 UTC
+++ src/custommem.c
@@ -6,8 +6,13 @@
 #include <signal.h>
 #include <pthread.h>
 #include <errno.h>
+#if __FreeBSD__
+#include <sys/syscall.h>
+#include <unistd.h>
+#else
 #include <syscall.h>
 #include <sys/personality.h>
+#endif
 
 #include "box64context.h"
 #include "elfloader.h"
@@ -377,20 +382,36 @@ void testAllBlocks()
     size_t total = 0;
     size_t fragmented_free = 0;
     size_t max_free = 0;
+    size_t total32 = 0;
+    size_t fragmented_free32 = 0;
+    size_t max_free32 = 0;
+    int n_blocks32 = 0;
     for(int i=0; i<n_blocks; ++i) {
-        if(!printBlockCoherent(i))
-            printBlock(p_blocks[i].block, p_blocks[i].first);
-        total += p_blocks[i].size;
-        if(max_free<p_blocks[i].maxfree)
-            max_free = p_blocks[i].maxfree;
-        blockmark_t* m = (blockmark_t*)p_blocks[i].block;
-        while(m->next.x32) {
-            if(!m->next.fill)
-                fragmented_free += SIZE_BLOCK(m->next);
-            m = NEXT_BLOCK(m);
+        // just silently skip blocks with 0 size, as they are not finished and so might be not coherent
+        if(p_blocks[i].size) {
+            int is32bits = (box64_is32bits && p_blocks[i].block<(void*)0x100000000LL);
+            if(is32bits) ++n_blocks32;
+            if(!printBlockCoherent(i))
+                printBlock(p_blocks[i].block, p_blocks[i].first);
+            total += p_blocks[i].size;
+            if(is32bits) total32 += p_blocks[i].size;
+            if(max_free<p_blocks[i].maxfree)
+                max_free = p_blocks[i].maxfree;
+            if(is32bits && max_free32<p_blocks[i].maxfree)
+                max_free32 = p_blocks[i].maxfree;
+            blockmark_t* m = (blockmark_t*)p_blocks[i].block;
+            while(m->next.x32) {
+                if(!m->next.fill)
+                    fragmented_free += SIZE_BLOCK(m->next);
+                if(is32bits && !m->next.fill)
+                    fragmented_free32 += SIZE_BLOCK(m->next);
+                m = NEXT_BLOCK(m);
+            }
         }
     }
-    printf_log(LOG_NONE, "CustomMem: Total %d blocks, for %zd allocated memory, max_free %zd, total fragmented free %zd\n", n_blocks, total, max_free, fragmented_free);
+    printf_log(LOG_NONE, "CustomMem: Total %d blocks, for %zd (0x%zx) allocated memory, max_free %zd (0x%zx), total fragmented free %zd (0x%zx)\n", n_blocks, total, total, max_free, max_free, fragmented_free, fragmented_free);
+    if(box64_is32bits)
+        printf_log(LOG_NONE, "   32bits: Total %d blocks, for %zd (0x%zx) allocated memory, max_free %zd (0x%zx), total fragmented free %zd (0x%zx)\n", n_blocks32, total32, total32, max_free32, max_free32, fragmented_free32, fragmented_free32);
 }
 
 static size_t roundSize(size_t size)
@@ -419,6 +440,7 @@ blocklist_t* findBlock(uintptr_t addr)
     }
     return NULL;
 }
+void* box32_dynarec_mmap(size_t size);
 #ifdef BOX32
 int isCustomAddr(void* p)
 {
@@ -482,7 +504,7 @@ void* internal_customMalloc(size_t size, int is32bits)
     size_t fullsize = size+2*sizeof(blockmark_t);
     mutex_lock(&mutex_blocks);
     for(int i=0; i<n_blocks; ++i) {
-        if(p_blocks[i].block && p_blocks[i].maxfree>=init_size && ((!is32bits) || (p_blocks[i].block<(void*)0x100000000LL))) {
+        if(p_blocks[i].block && p_blocks[i].maxfree>=init_size && (!box64_is32bits || ((!is32bits && p_blocks[i].block>(void*)0xffffffffLL)) || (is32bits && p_blocks[i].block<(void*)0x100000000LL))) {
             size_t rsize = 0;
             sub = getFirstBlock(p_blocks[i].block, init_size, &rsize, p_blocks[i].first);
             if(sub) {
@@ -501,11 +523,12 @@ void* internal_customMalloc(size_t size, int is32bits)
     // add a new block
     int i = n_blocks++;
     if(n_blocks>c_blocks) {
-        c_blocks += box64_is32bits?8:256;
+        c_blocks += box64_is32bits?256:8;
         p_blocks = (blocklist_t*)box_realloc(p_blocks, c_blocks*sizeof(blocklist_t));
     }
     size_t allocsize = (fullsize>MMAPSIZE)?fullsize:MMAPSIZE;
     allocsize = (allocsize+box64_pagesize-1)&~(box64_pagesize-1);
+    if(is32bits) allocsize = (allocsize+0xffffLL)&~(0xffffLL);
     p_blocks[i].block = NULL;   // incase there is a re-entrance
     p_blocks[i].first = NULL;
     p_blocks[i].size = 0;
@@ -513,7 +536,7 @@ void* internal_customMalloc(size_t size, int is32bits)
         mutex_unlock(&mutex_blocks);
     void* p = is32bits
                 ?box_mmap(NULL, allocsize, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE|MAP_32BIT, -1, 0)
-                :internal_mmap(NULL, allocsize, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);
+                :(box64_is32bits?box32_dynarec_mmap(allocsize):internal_mmap(NULL, allocsize, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1, 0));
     if(is32bits)
         mutex_lock(&mutex_blocks);
 #ifdef TRACE_MEMSTAT
@@ -530,6 +553,30 @@ void* internal_customMalloc(size_t size, int is32bits)
     blockmark_t* n = NEXT_BLOCK(m);
     n->next.x32 = 0;
     n->prev.x32 = m->next.x32;
+    if(is32bits && p>(void*)0xffffffffLL) {
+        printf_log(LOG_INFO, "Warning: failled to allocate 0x%x (0x%x) bytes in 32bits address space (block %d)\n", size, allocsize, i);
+        // failled to allocate memory
+        if(BOX64ENV(showbt) || BOX64ENV(showsegv)) {
+            // mask size from this block
+            p_blocks[i].size = 0;
+            showNativeBT(LOG_NONE);
+            testAllBlocks();
+            if(BOX64ENV(log)>=LOG_DEBUG) {
+                printf_log(LOG_NONE, "Used 32bits address space map:\n");
+                uintptr_t addr = rb_get_lefter(mapallmem);
+                while(addr<0x100000000LL) {
+                    uintptr_t bend;
+                    uint32_t val;
+                    if(rb_get_end(mapallmem, addr, &val, &bend))
+                        printf_log(LOG_NONE, "\t%p - %p\n", (void*)addr, (void*)bend);
+                    addr = bend;
+                }
+            }
+            p_blocks[i].size = allocsize;
+        }
+        p_blocks[i].maxfree = allocsize - sizeof(blockmark_t)*2;
+        return NULL;
+    }
     // alloc 1st block
     void* ret  = allocBlock(p_blocks[i].block, p, size, &p_blocks[i].first);
     p_blocks[i].maxfree = getMaxFreeBlock(p_blocks[i].block, p_blocks[i].size, p_blocks[i].first);
@@ -793,6 +840,33 @@ size_t customGetUsableSize(void* p)
     return 0;
 }
 
+void* box32_dynarec_mmap(size_t size)
+{
+#ifdef BOX32
+    // find a block that was prereserve before and big enough
+    size = (size+box64_pagesize-1)&~(box64_pagesize-1);
+    uint32_t flag;
+    static uintptr_t cur = 0x100000000LL;
+    uintptr_t bend = 0;
+    while(bend<0x800000000000LL) {
+        if(rb_get_end(mapallmem, cur, &flag, &bend)) {
+            if(flag==2 && bend-cur>=size) {
+                void* ret = internal_mmap((void*)cur, size, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_FIXED|MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);
+                if(ret!=MAP_FAILED)
+                    rb_set(mapallmem, cur, cur+size, 1);    // mark as allocated
+                else
+                    printf_log(LOG_INFO, "BOX32: Error allocating Dynarec memory: %s\n", strerror(errno));
+                cur = cur+size;
+                return ret;
+            }
+        }
+        cur = bend;
+    }
+#endif
+    //printf_log(LOG_INFO, "BOX32: Error allocating Dynarec memory: %s\n", "fallback to internal mmap");
+    return internal_mmap((void*)0x100000000LL, size, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_FIXED|MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);;
+}
+
 #ifdef DYNAREC
 #define NCHUNK          64
 typedef struct mapchunk_s {
@@ -819,32 +893,6 @@ dynablock_t* FindDynablockFromNativeAddress(void* p)
     return NULL;
 }
 
-#ifdef BOX32
-void* box32_dynarec_mmap(size_t size)
-{
-    // find a block that was prereserve before and big enough
-    size = (size+box64_pagesize-1)&~(box64_pagesize-1);
-    uint32_t flag;
-    static uintptr_t cur = 0x100000000LL;
-    uintptr_t bend = 0;
-    while(bend<0x800000000000LL) {
-        if(rb_get_end(mapallmem, cur, &flag, &bend)) {
-            if(flag==2 && bend-cur>=size) {
-                void* ret = internal_mmap((void*)cur, size, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_FIXED|MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);
-                if(ret!=MAP_FAILED)
-                    rb_set(mapallmem, cur, cur+size, 1);    // mark as allocated
-                else
-                    printf_log(LOG_INFO, "BOX32: Error allocating Dynarec memory: %s\n", strerror(errno));
-                cur = cur+size;
-                return ret;
-            }
-        }
-        cur = bend;
-    }
-    return MAP_FAILED;
-}
-#endif
-
 #ifdef TRACE_MEMSTAT
 static uint64_t dynarec_allocated = 0;
 #endif
@@ -1446,7 +1494,48 @@ void unprotectDB(uintptr_t addr, size_t size, int mark
     }
     UNLOCK_PROT();
 }
+// Add the NEVERCLEAN flag for an adress range, mark all block as dirty, and lift write protection if needed
+void neverprotectDB(uintptr_t addr, size_t size, int mark)
+{
+    dynarec_log(LOG_DEBUG, "neverprotectDB %p -> %p (mark=%d)\n", (void*)addr, (void*)(addr+size-1), mark);
 
+    uintptr_t cur = addr&~(box64_pagesize-1);
+    uintptr_t end = ALIGN(addr+size);
+
+    LOCK_PROT();
+    while(cur!=end) {
+        uint32_t prot = 0, oprot;
+        uintptr_t bend = 0;
+        if (!rb_get_end(memprot, cur, &prot, &bend)) {
+            if(bend>=end) break;
+            else {
+                cur = bend;
+                continue;
+            }
+        }
+        oprot = prot;
+        if(bend>end)
+            bend = end;
+        if(!(prot&PROT_NEVERPROT)) {
+            if(prot&PROT_DYNAREC) {
+                prot&=~PROT_DYN;
+                if(mark)
+                    cleanDBFromAddressRange(cur, bend-cur, 0);
+                mprotect((void*)cur, bend-cur, prot);
+            } else if(prot&PROT_DYNAREC_R) {
+                if(mark)
+                    cleanDBFromAddressRange(cur, bend-cur, 0);
+                prot &= ~PROT_DYN;
+            }
+            prot |= PROT_NEVERCLEAN;
+        }
+        if (prot != oprot)
+            rb_set(memprot, cur, bend, prot);
+        cur = bend;
+    }
+    UNLOCK_PROT();
+}
+
 int isprotectedDB(uintptr_t addr, size_t size)
 {
     dynarec_log(LOG_DEBUG, "isprotectedDB %p -> %p => ", (void*)addr, (void*)(addr+size-1));
@@ -1484,8 +1573,13 @@ void CheckHotPage(uintptr_t addr)
 {
     uintptr_t page = (uintptr_t)addr&~(box64_pagesize-1);
     if(repeated_count==1 && repeated_page==page) {
-        dynarec_log(LOG_DEBUG, "Detecting a Hotpage at %p (%d)\n", (void*)repeated_page, repeated_count);
-        SetHotPage(repeated_page);
+        if(BOX64ENV(dynarec_dirty)>1) {
+            dynarec_log(LOG_INFO, "Detecting a Hotpage at %p (%d), marking page as NEVERCLEAN\n", (void*)repeated_page, repeated_count);
+            neverprotectDB(repeated_page, box64_pagesize, 1);
+        } else {
+            dynarec_log(LOG_INFO, "Detecting a Hotpage at %p (%d)\n", (void*)repeated_page, repeated_count);
+            SetHotPage(repeated_page);
+        }
         repeated_count = 0;
         repeated_page = 0;
     } else {
@@ -1883,50 +1977,21 @@ void reverveHigMem32(void)
         cur = internal_mmap(NULL, cur_size, 0, MAP_ANONYMOUS|MAP_PRIVATE|MAP_NORESERVE, -1, 0);
         if((cur==MAP_FAILED) || (cur<(void*)0x100000000LL)) {
             if(cur!=MAP_FAILED) {
-                //printf_log(LOG_DEBUG, " Failed to reserve high %p (%zx)\n", cur, cur_size);
+                //printf_log(LOG_INFO, " Failed to reserve high %p (%zx)\n", cur, cur_size);
                 internal_munmap(cur, cur_size);
             } //else 
-              //  printf_log(LOG_DEBUG, " Failed to reserve %zx sized block\n", cur_size);
+                //printf_log(LOG_INFO, " Failed to reserve %zx sized block\n", cur_size);
             cur_size>>=1;
         } else {
             rb_set(mapallmem, (uintptr_t)cur, (uintptr_t)cur+cur_size, 2);
-            //printf_log(LOG_DEBUG, "Reserved high %p (%zx)\n", cur, cur_size);
+            //printf_log(LOG_INFO, "Reserved high %p (%zx)\n", cur, cur_size);
         }
     }
-    // try again, but specifying a high address, just in case
-    if(0)
-    {
-        uintptr_t cur = 0xffff00000000LL;
-        uintptr_t bend = 0;
-        uint32_t prot;
-        while (bend!=0xffffffffffffffffLL) {
-            if(!rb_get_end(mapallmem, cur, &prot, &bend)) {
-                // create a border at 48bits
-                if(cur<(1ULL<<48) && bend>(1ULL<<48))
-                    bend = 1ULL<<48;
-                cur = (cur+0xffffLL)&~0xffffLL; // round to 64K page size
-                if(bend>cur) {
-                    void* p = internal_mmap((void*)cur, bend-cur, 0, MAP_FIXED|MAP_ANONYMOUS|MAP_PRIVATE|MAP_NORESERVE, -1, 0);
-                    if((p==MAP_FAILED) || (p<(void*)0x100000000LL)) {
-                        if(p!=MAP_FAILED) {
-                            printf_log(LOG_DEBUG, " Failed to reserve high %p (%zx) => %p\n", (void*)cur, bend-cur, p);
-                            internal_munmap(p, bend-cur);
-                        } else 
-                        printf_log(LOG_DEBUG, " Failed to reserve %zx sized block (%s)\n", bend-cur, strerror(errno));
-                    } else {
-                        rb_set(mapallmem, (uintptr_t)cur, (uintptr_t)bend, 2);
-                        printf_log(LOG_DEBUG, "Reserved high %p (%zx)\n", cur, bend-cur);
-                    }
-                }
-            }
-            cur = bend;
-        }
-    }
     printf_log(LOG_INFO, "Memory higher than 32bits reserved\n");
     if (BOX64ENV(log)>=LOG_DEBUG) {
         uintptr_t start=0x100000000LL;
         int prot;
-        uintptr_t bend;
+        uintptr_t bend = start;
         while (bend!=0xffffffffffffffffLL) {
             if(rb_get_end(mapallmem, start, &prot, &bend)) {
                 printf_log(LOG_NONE, " Reserved: %p - %p (%d)\n", (void*)start, (void*)bend, prot);
@@ -1946,20 +2011,6 @@ void my_reserveHighMem()
     #ifdef BOX32
     if(box64_is32bits) {
         reverveHigMem32();
-        // now reserve some memory in low address (because wine tend to allocate everything for itself)
-        void* p[20];
-        #define SZ 2*1024*1024
-        size_t n = sizeof(p)/sizeof(p[0]);
-        for(size_t i=0; i<n; ++i)
-            p[i] = box32_malloc(SZ-128);
-        if (BOX64ENV(log)>=LOG_DEBUG) {
-            printf_log(LOG_DEBUG, "Reserved %u MB of low memory [", (SZ)*n);
-            for(size_t i=0; i<n; ++i)
-                printf_log(LOG_DEBUG, "%p%s", p[i], (i==(n-1))?"]\n":", ");
-        }
-        for(size_t i=0; i<n; ++i)
-            box32_free(p[i]);
-        #undef SZ
         return;
     }
     #endif
@@ -1977,7 +2028,11 @@ void my_reserveHighMem()
             // create a border at 48bits
             if(cur<(1ULL<<48) && bend>(1ULL<<48))
                 bend = 1ULL<<48;
+#if __FreeBSD__
+	    void* ret = internal_mmap((void*)cur, bend-cur, 0, MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);
+#else
             void* ret = internal_mmap((void*)cur, bend-cur, 0, MAP_ANONYMOUS|MAP_PRIVATE|MAP_NORESERVE, -1, 0);
+#endif
             printf_log(LOG_DEBUG, "Reserve %p-%p => %p (%s)\n", (void*)cur, bend, ret, (ret==MAP_FAILED)?strerror(errno):"ok");
             if(ret!=(void*)-1) {
                 rb_set(mapallmem, cur, bend, 1);
@@ -2162,7 +2217,7 @@ void* internal_mmap(void *addr, unsigned long length, 
 
 void* internal_mmap(void *addr, unsigned long length, int prot, int flags, int fd, ssize_t offset)
 {
-    #if 1//def STATICBUILD
+    #if 0//def STATICBUILD
     void* ret = (void*)syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
     #else
     static int grab = 1;
@@ -2177,7 +2232,7 @@ int internal_munmap(void* addr, unsigned long length)
 }
 int internal_munmap(void* addr, unsigned long length)
 {
-    #if 1//def STATICBUILD
+    #if 0//def STATICBUILD
     int ret = syscall(__NR_munmap, addr, length);
     #else
     static int grab = 1;

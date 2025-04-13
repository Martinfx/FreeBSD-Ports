--- src/elfs/elfhash.c.orig	2025-04-11 15:12:48 UTC
+++ src/elfs/elfhash.c
@@ -5,8 +5,12 @@
 #include <elf.h>
 #include <sys/mman.h>
 #include <sys/stat.h>
+#if __FreeBSD__
+#include <sys/types.h>
+#else
 #include <sys/sysmacros.h>
 #include <sys/types.h>
+#endif
 #include <link.h>
 #include <unistd.h>
 #include <errno.h>

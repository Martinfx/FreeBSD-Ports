--- library/sql.parser/source/my_global.h.orig	2024-05-20 10:54:13 UTC
+++ library/sql.parser/source/my_global.h
@@ -400,7 +400,11 @@ C_MODE_END
 #undef HAVE_ALLOCA_H
 #endif
 #ifdef HAVE_ALLOCA_H
+#if defined(__FreeBSD__)
+#include <stdlib.h>
+#else
 #include <alloca.h>
+#endif
 #endif
 #ifdef HAVE_ATOMIC_ADD
 #define new my_arg_new

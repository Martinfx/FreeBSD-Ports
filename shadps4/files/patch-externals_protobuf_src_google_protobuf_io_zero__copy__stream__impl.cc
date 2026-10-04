--- externals/protobuf/src/google/protobuf/io/zero_copy_stream_impl.cc.orig	2026-10-02 12:00:00 UTC
+++ externals/protobuf/src/google/protobuf/io/zero_copy_stream_impl.cc
@@ -10,7 +10,11 @@
 //  Sanjay Ghemawat, Jeff Dean, and others.
 
 // We request posix_close if available. See the comment on "robust_close".
+// FreeBSD does not know this POSIX revision and would hide everything outside
+// strict POSIX, including isascii() which libc++ <__locale> needs.
+#if !defined(__FreeBSD__)
 #define _POSIX_C_SOURCE 202405L
+#endif
 
 #ifndef _MSC_VER
 #include <fcntl.h>

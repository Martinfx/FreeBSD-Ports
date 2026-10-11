--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/Buffers.h.orig	2026-02-24 00:10:13 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/Buffers.h
@@ -19,6 +19,8 @@
 #ifndef BUFFERS_H_
 #define BUFFERS_H_
 
+#include <sys/endian.h>
+
 #include "lib/Streams.h"
 #include "lib/Compressions.h"
 #include "lib/Constants.h"
@@ -79,11 +81,11 @@
   }
 
   /**
-   * read to outside buffer, use simple_memcpy
+   * read to outside buffer, use memcpy
    */
   inline void readUnsafe(char * buff, uint32_t len) {
     if (likely(len <= _remain)) {
-      simple_memcpy(buff, current(), len);
+      memcpy(buff, current(), len);
       _remain -= len;
       return;
     }
@@ -115,7 +117,7 @@
    * read uint32_t big endian
    */
   inline uint32_t read_uint32_be() {
-    return bswap(read_uint32_le());
+    return bswap32(read_uint32_le());
   }
 };
 
@@ -181,7 +183,7 @@
 
   inline void write(const void * data, uint32_t len) {
     if (likely(len <= _remain)) { // append directly
-      simple_memcpy(current(), data, len);
+      memcpy(current(), data, len);
       _remain -= len;
       return;
     }
@@ -198,7 +200,7 @@
   }
 
   inline void write_uint32_be(uint32_t v) {
-    write_uint32_le(bswap(v));
+    write_uint32_le(bswap32(v));
   }
 
   inline void write_uint64_le(uint64_t v) {
@@ -291,10 +293,10 @@
     valueLength = vallen;
 
     if (keylen > 0) {
-      simple_memcpy(getKey(), key, keylen);
+      memcpy(getKey(), key, keylen);
     }
     if (vallen > 0) {
-      simple_memcpy(getValue(), value, vallen);
+      memcpy(getValue(), value, vallen);
     }
   }
 
@@ -479,7 +481,7 @@
     }
     uint32_t remain = _size - _pos;
     uint32_t length = (maxSize < remain) ? maxSize : remain;
-    simple_memcpy(_buff + _pos, source, length);
+    memcpy(_buff + _pos, source, length);
     _pos += length;
     return length;
   }

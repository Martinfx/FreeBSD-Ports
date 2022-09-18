--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/Buffers.h.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/Buffers.h
@@ -79,11 +79,11 @@ class ReadBuffer { (public)
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
@@ -115,7 +115,7 @@ class ReadBuffer { (public)
    * read uint32_t big endian
    */
   inline uint32_t read_uint32_be() {
-    return bswap(read_uint32_le());
+    return bswap32(read_uint32_le());
   }
 };
 
@@ -181,7 +181,7 @@ class AppendBuffer { (public)
 
   inline void write(const void * data, uint32_t len) {
     if (likely(len <= _remain)) { // append directly
-      simple_memcpy(current(), data, len);
+      memcpy(current(), data, len);
       _remain -= len;
       return;
     }
@@ -198,7 +198,7 @@ class AppendBuffer { (public)
   }
 
   inline void write_uint32_be(uint32_t v) {
-    write_uint32_le(bswap(v));
+    write_uint32_le(bswap32(v));
   }
 
   inline void write_uint64_le(uint64_t v) {
@@ -291,10 +291,10 @@ struct KVBuffer {
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
 
@@ -479,7 +479,7 @@ class FixSizeContainer { (public)
     }
     uint32_t remain = _size - _pos;
     uint32_t length = (maxSize < remain) ? maxSize : remain;
-    simple_memcpy(_buff + _pos, source, length);
+    memcpy(_buff + _pos, source, length);
     _pos += length;
     return length;
   }

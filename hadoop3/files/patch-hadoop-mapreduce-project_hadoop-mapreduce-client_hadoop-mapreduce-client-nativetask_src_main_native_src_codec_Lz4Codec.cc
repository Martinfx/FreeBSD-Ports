--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/codec/Lz4Codec.cc.orig	2026-02-24 00:10:13 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/codec/Lz4Codec.cc
@@ -38,8 +38,8 @@
   int ret = LZ4_compress_default((char*)buff, _tempBuffer + 8, length, LZ4_compressBound(length));
   if (ret > 0) {
     compressedLength = ret;
-    ((uint32_t*)_tempBuffer)[0] = bswap(length);
-    ((uint32_t*)_tempBuffer)[1] = bswap((uint32_t)compressedLength);
+    ((uint32_t*)_tempBuffer)[0] = bswap32(length);
+    ((uint32_t*)_tempBuffer)[1] = bswap32((uint32_t)compressedLength);
     _stream->write(_tempBuffer, compressedLength + 8);
     _compressedBytesWritten += (compressedLength + 8);
   } else {

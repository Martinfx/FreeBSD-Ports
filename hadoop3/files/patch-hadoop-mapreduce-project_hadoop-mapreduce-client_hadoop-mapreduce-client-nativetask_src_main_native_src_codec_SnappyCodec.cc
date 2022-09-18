--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/codec/SnappyCodec.cc.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/codec/SnappyCodec.cc
@@ -37,8 +37,8 @@ void SnappyCompressStream::compressOneBlock(const void
   snappy_status ret = snappy_compress((const char*)buff, length, _tempBuffer + 8,
       &compressedLength);
   if (ret == SNAPPY_OK) {
-    ((uint32_t*)_tempBuffer)[0] = bswap(length);
-    ((uint32_t*)_tempBuffer)[1] = bswap((uint32_t)compressedLength);
+    ((uint32_t*)_tempBuffer)[0] = bswap32(length);
+    ((uint32_t*)_tempBuffer)[1] = bswap32((uint32_t)compressedLength);
     _stream->write(_tempBuffer, compressedLength + 8);
     _compressedBytesWritten += (compressedLength + 8);
   } else if (ret == SNAPPY_INVALID_INPUT) {

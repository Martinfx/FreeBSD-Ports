--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/codec/BlockCodec.cc.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/codec/BlockCodec.cc
@@ -104,8 +104,8 @@ int32_t BlockDecompressStream::read(void * buff, uint3
       THROW_EXCEPTION(IOException, "readFully get incomplete data");
     }
     _compressedBytesRead += rd;
-    sizes[0] = bswap(sizes[0]);
-    sizes[1] = bswap(sizes[1]);
+    sizes[0] = bswap32(sizes[0]);
+    sizes[1] = bswap32(sizes[1]);
     if (sizes[0] <= length) {
       uint32_t len = decompressOneBlock(sizes[1], buff, sizes[0]);
       if (len != sizes[0]) {

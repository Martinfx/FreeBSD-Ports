--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/handler/MCollectorOutputHandler.cc.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/handler/MCollectorOutputHandler.cc
@@ -74,9 +74,9 @@ void MCollectorOutputHandler::handleInput(ByteBuffer &
     }
 
     if (_endium == LARGE_ENDIUM) {
-      kvBuffer->partitionId = bswap(kvBuffer->partitionId);
-      kvBuffer->buffer.keyLength = bswap(kvBuffer->buffer.keyLength);
-      kvBuffer->buffer.valueLength = bswap(kvBuffer->buffer.valueLength);
+      kvBuffer->partitionId = bswap32(kvBuffer->partitionId);
+      kvBuffer->buffer.keyLength = bswap32(kvBuffer->buffer.keyLength);
+      kvBuffer->buffer.valueLength = bswap32(kvBuffer->buffer.valueLength);
     }
 
     uint32_t kvLength = kvBuffer->buffer.length();

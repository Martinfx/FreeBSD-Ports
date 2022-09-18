--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/handler/CombineHandler.cc.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/handler/CombineHandler.cc
@@ -48,8 +48,8 @@ uint32_t CombineHandler::feedDataToJavaInWritableSeria
 
   if (_kvCached) {
     uint32_t kvLength = _key.outerLength + _value.outerLength + KVBuffer::headerLength();
-    outputInt(bswap(_key.outerLength));
-    outputInt(bswap(_value.outerLength));
+    outputInt(bswap32(_key.outerLength));
+    outputInt(bswap32(_value.outerLength));
     outputKeyOrValue(_key, _kType);
     outputKeyOrValue(_value, _vType);
 
@@ -73,8 +73,8 @@ uint32_t CombineHandler::feedDataToJavaInWritableSeria
     } else {
       firstKV = false;
       //write final key length and final value length
-      outputInt(bswap(_key.outerLength));
-      outputInt(bswap(_value.outerLength));
+      outputInt(bswap32(_key.outerLength));
+      outputInt(bswap32(_value.outerLength));
       outputKeyOrValue(_key, _kType);
       outputKeyOrValue(_value, _vType);
 
@@ -101,7 +101,7 @@ void CombineHandler::outputKeyOrValue(SerializeInfo & 
     output(KV.buffer.data(), KV.buffer.length());
     break;
   case BytesType:
-    outputInt(bswap(KV.buffer.length()));
+    outputInt(bswap32(KV.buffer.length()));
     output(KV.buffer.data(), KV.buffer.length());
     break;
   default:
@@ -202,8 +202,8 @@ void CombineHandler::write(char * buf, uint32_t length
   uint32_t outputRecordCount = 0;
   while (remain > 0) {
     kv = (KVBuffer *)pos;
-    kv->keyLength = bswap(kv->keyLength);
-    kv->valueLength = bswap(kv->valueLength);
+    kv->keyLength = bswap32(kv->keyLength);
+    kv->valueLength = bswap32(kv->valueLength);
     _writer->write(kv->getKey(), kv->keyLength, kv->getValue(), kv->valueLength);
     outputRecordCount++;
     remain -= kv->length();

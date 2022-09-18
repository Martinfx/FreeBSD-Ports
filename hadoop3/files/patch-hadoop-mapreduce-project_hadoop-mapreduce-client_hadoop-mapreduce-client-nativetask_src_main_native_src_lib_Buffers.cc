--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/Buffers.cc.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/Buffers.cc
@@ -206,7 +206,7 @@ void AppendBuffer::write_inner(const void * data, uint
     _dest->write(data, len);
     _counter += len;
   } else {
-    simple_memcpy(_buff, data, len);
+    memcpy(_buff, data, len);
     _remain -= len;
   }
 }

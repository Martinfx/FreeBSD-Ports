--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/handler/BatchHandler.h.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/handler/BatchHandler.h
@@ -108,7 +108,7 @@ class BatchHandler : public Configurable { (protected)
         flushOutput();
       }
       uint32_t cp = length < remain ? length : remain;
-      simple_memcpy(_out.current(), buff, cp);
+      memcpy(_out.current(), buff, cp);
       buff += cp;
       length -= cp;
       _out.advance(cp);

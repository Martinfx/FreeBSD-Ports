--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/IFile.h.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/IFile.h
@@ -74,7 +74,7 @@ class IFileReader { (public)
       keyLen = WritableUtils::ReadVInt(kvbuff, len);
       break;
     case BytesType:
-      keyLen = bswap(*(uint32_t*)kvbuff);
+      keyLen = bswap32(*(uint32_t*)kvbuff);
       len = 4;
       break;
     default:
@@ -89,7 +89,7 @@ class IFileReader { (public)
       _valuePos = vbuff + len;
       break;
     case BytesType:
-      _valueLen = bswap(*(uint32_t*)vbuff);
+      _valueLen = bswap32(*(uint32_t*)vbuff);
       _valuePos = vbuff + 4;
       break;
     default:

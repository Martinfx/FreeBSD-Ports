--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/util/WritableUtils.cc.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/util/WritableUtils.cc
@@ -120,22 +120,22 @@ void WritableUtils::WriteVLongInner(int64_t v, char * 
     len = 4;
   } else if (value < (1ULL << 32)) {
     *(pos++) = base - 3;
-    *(uint32_t*)(pos) = bswap((uint32_t)value);
+    *(uint32_t*)(pos) = bswap32((uint32_t)value);
     len = 5;
   } else if (value < (1ULL << 40)) {
     *(pos++) = base - 4;
-    *(uint32_t*)(pos) = bswap((uint32_t)(value >> 8));
+    *(uint32_t*)(pos) = bswap32((uint32_t)(value >> 8));
     *(uint8_t*)(pos + 4) = value;
     len = 6;
   } else if (value < (1ULL << 48)) {
     *(pos++) = base - 5;
-    *(uint32_t*)(pos) = bswap((uint32_t)(value >> 16));
+    *(uint32_t*)(pos) = bswap32((uint32_t)(value >> 16));
     *(uint8_t*)(pos + 4) = value >> 8;
     *(uint8_t*)(pos + 5) = value;
     len = 7;
   } else if (value < (1ULL << 56)) {
     *(pos++) = base - 6;
-    *(uint32_t*)(pos) = bswap((uint32_t)(value >> 24));
+    *(uint32_t*)(pos) = bswap32((uint32_t)(value >> 24));
     *(uint8_t*)(pos + 4) = value >> 16;
     *(uint8_t*)(pos + 5) = value >> 8;
     *(uint8_t*)(pos + 6) = value;
@@ -176,7 +176,7 @@ int32_t WritableUtils::ReadInt(InputStream * stream) {
   if (stream->readFully(&ret, 4) != 4) {
     THROW_EXCEPTION(IOException, "ReadInt reach EOF");
   }
-  return (int32_t)bswap(ret);
+  return (int32_t)bswap32(ret);
 }
 
 int16_t WritableUtils::ReadShort(InputStream * stream) {
@@ -192,7 +192,7 @@ float WritableUtils::ReadFloat(InputStream * stream) {
   if (stream->readFully(&ret, 4) != 4) {
     THROW_EXCEPTION(IOException, "ReadFloat reach EOF");
   }
-  ret = bswap(ret);
+  ret = bswap32(ret);
   return *(float*)&ret;
 }
 
@@ -237,7 +237,7 @@ void WritableUtils::WriteLong(OutputStream * stream, i
 }
 
 void WritableUtils::WriteInt(OutputStream * stream, int32_t v) {
-  uint32_t be = bswap((uint32_t)v);
+  uint32_t be = bswap32((uint32_t)v);
   stream->write(&be, 4);
 }
 
@@ -249,7 +249,7 @@ void WritableUtils::WriteShort(OutputStream * stream, 
 
 void WritableUtils::WriteFloat(OutputStream * stream, float v) {
   uint32_t intv = *(uint32_t*)&v;
-  intv = bswap(intv);
+  intv = bswap32(intv);
   stream->write(&intv, 4);
 }
 
@@ -286,7 +286,7 @@ void WritableUtils::toString(string & dest, KeyValueTy
     dest.append(*(uint8_t*)data ? "true" : "false");
     break;
   case IntType:
-    dest.append(StringUtil::ToString((int32_t)bswap(*(uint32_t*)data)));
+    dest.append(StringUtil::ToString((int32_t)bswap32(*(uint32_t*)data)));
     break;
   case LongType:
     dest.append(StringUtil::ToString((int64_t)bswap64(*(uint64_t*)data)));

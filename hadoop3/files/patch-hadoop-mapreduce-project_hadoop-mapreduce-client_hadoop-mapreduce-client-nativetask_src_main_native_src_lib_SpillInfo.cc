--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/SpillInfo.cc.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/SpillInfo.cc
@@ -58,7 +58,7 @@ void SingleSpillInfo::writeSpillInfo(const std::string
     appendBuffer.flush();
     uint32_t chsum = dest.getChecksum();
 #ifdef SPILLRECORD_CHECKSUM_UINT
-    chsum = bswap(chsum);
+    chsum = bswap32(chsum);
     fout->write(&chsum, sizeof(uint32_t));
 #else
     uint64_t wtchsum = bswap64((uint64_t)chsum);

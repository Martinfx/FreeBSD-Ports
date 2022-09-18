--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/IFile.cc.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/IFile.cc
@@ -60,7 +60,7 @@ bool IFileReader::nextPartition() {
     if (4 != _stream->readFully(&chsum, 4)) {
       THROW_EXCEPTION(IOException, "read ifile checksum failed");
     }
-    uint32_t actual = bswap(chsum);
+    uint32_t actual = bswap32(chsum);
     uint32_t expect = _source->getChecksum();
     if (actual != expect) {
       THROW_EXCEPTION_EX(IOException, "read ifile checksum not match, actual %x expect %x", actual,
@@ -130,7 +130,7 @@ void IFileWriter::endPartition() {
   }
 
   uint32_t chsum = _dest->getChecksum();
-  chsum = bswap(chsum);
+  chsum = bswap32(chsum);
   _stream->write(&chsum, sizeof(chsum));
   _stream->flush();
   IFileSegment * info = &(_spillFileSegments[_spillFileSegments.size() - 1]);

--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/test/TestCompressions.cc.orig	2019-04-21 10:30:06 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/test/TestCompressions.cc
@@ -269,7 +269,7 @@ TEST(Perf, RawCompressionSnappy) {
   vector<FileEntry> inputfiles;
   FileSystem::getLocal().list(inputdir, inputfiles);
   CompressResult total;
-  printf("Block size: %"PRId64"K\n", blockSize / 1024);
+  printf("Block size: %" PRId64"K\n", blockSize / 1024);
   for (size_t i = 0; i < inputfiles.size(); i++) {
     if (!inputfiles[i].isDirectory) {
       MeasureSingleFileSnappy((inputdir + "/" + inputfiles[i].name).c_str(), total, blockSize,

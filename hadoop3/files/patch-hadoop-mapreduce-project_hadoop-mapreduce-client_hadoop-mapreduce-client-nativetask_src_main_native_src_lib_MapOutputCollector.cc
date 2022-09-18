--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/MapOutputCollector.cc.orig	2019-04-21 10:25:54 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/MapOutputCollector.cc
@@ -302,10 +302,10 @@ void MapOutputCollector::middleSpill(const std::string
     uint64_t spillTime = timer.now() - timer.last() - metrics.sortTime;
 
     const uint64_t M = 1000000; // million
-    LOG("%s-spill: { id: %d, collect: %"PRIu64" ms, "
-        "in-memory sort: %"PRIu64" ms, in-memory records: %"PRIu64", "
-        "merge&spill: %"PRIu64" ms, uncompressed size: %"PRIu64", "
-        "real size: %"PRIu64" path: %s }",
+    LOG("%s-spill: { id: %d, collect: %" PRIu64" ms, "
+        "in-memory sort: %" PRIu64" ms, in-memory records: %" PRIu64", "
+        "merge&spill: %" PRIu64" ms, uncompressed size: %" PRIu64", "
+        "real size: %" PRIu64" path: %s }",
         final ? "Final" : "Mid",
         _spillInfos.getSpillCount(),
         collecttime / M,
@@ -370,10 +370,10 @@ void MapOutputCollector::finalSpill(const std::string 
   writer->getStatistics(outputSize, realOutputSize, recordCount);
 
   const uint64_t M = 1000000; // million
-  LOG("Final-merge-spill: { id: %d, in-memory sort: %"PRIu64" ms, "
-      "in-memory records: %"PRIu64", merge&spill: %"PRIu64" ms, "
-      "records: %"PRIu64", uncompressed size: %"PRIu64", "
-      "real size: %"PRIu64" path: %s }",
+  LOG("Final-merge-spill: { id: %d, in-memory sort: %" PRIu64" ms, "
+      "in-memory records: %" PRIu64", merge&spill: %" PRIu64" ms, "
+      "records: %" PRIu64", uncompressed size: %" PRIu64", "
+      "real size: %" PRIu64" path: %s }",
       _spillInfos.getSpillCount(),
       metrics.sortTime / M,
       metrics.recordCount,

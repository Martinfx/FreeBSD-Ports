--- hadoop-common-project/hadoop-common/src/main/java/org/apache/hadoop/util/StringUtils.java.orig	2026-03-12 22:36:48 UTC
+++ hadoop-common-project/hadoop-common/src/main/java/org/apache/hadoop/util/StringUtils.java
@@ -808,7 +808,7 @@
     final String classname = clazz.getSimpleName();
     log.info(createStartupShutdownMessage(classname, hostname, args));
 
-    if (SystemUtils.IS_OS_UNIX) {
+    if (true) {
       try {
         SignalLogger.INSTANCE.register(log);
       } catch (Throwable t) {

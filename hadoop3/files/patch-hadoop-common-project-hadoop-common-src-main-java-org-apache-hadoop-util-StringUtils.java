--- hadoop-common-project/hadoop-common/src/main/java/org/apache/hadoop/util/StringUtils.java.orig	2023-06-14 01:21:13 UTC
+++ hadoop-common-project/hadoop-common/src/main/java/org/apache/hadoop/util/StringUtils.java
@@ -765,7 +765,8 @@ public class StringUtils {
     final String classname = clazz.getSimpleName();
     LOG.info(createStartupShutdownMessage(classname, hostname, args));
 
-    if (SystemUtils.IS_OS_UNIX) {
+
+    if (true) {
       try {
         SignalLogger.INSTANCE.register(LOG);
       } catch (Throwable t) {

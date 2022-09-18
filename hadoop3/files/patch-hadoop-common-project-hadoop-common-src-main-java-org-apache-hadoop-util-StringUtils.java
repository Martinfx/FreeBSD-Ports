--- hadoop-common-project/hadoop-common/src/main/java/org/apache/hadoop/util/StringUtils.java.orig	2018-07-07 08:16:53 UTC
+++ hadoop-common-project/hadoop-common/src/main/java/org/apache/hadoop/util/StringUtils.java
@@ -713,7 +713,7 @@ public class StringUtils {
     final String classname = clazz.getSimpleName();
     LOG.info(createStartupShutdownMessage(classname, hostname, args));
 
-    if (SystemUtils.IS_OS_UNIX) {
+    if (true) {
       try {
         SignalLogger.INSTANCE.register(LOG);
       } catch (Throwable t) {

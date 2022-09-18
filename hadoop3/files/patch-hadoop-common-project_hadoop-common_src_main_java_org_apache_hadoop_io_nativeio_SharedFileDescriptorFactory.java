--- hadoop-common-project/hadoop-common/src/main/java/org/apache/hadoop/io/nativeio/SharedFileDescriptorFactory.java.orig	2018-03-21 17:57:55 UTC
+++ hadoop-common-project/hadoop-common/src/main/java/org/apache/hadoop/io/nativeio/SharedFileDescriptorFactory.java
@@ -54,7 +54,7 @@ public class SharedFileDescriptorFactory {
     if (!NativeIO.isAvailable()) {
       return "NativeIO is not available.";
     }
-    if (!SystemUtils.IS_OS_UNIX) {
+    if (false) {
       return "The OS is not UNIX.";
     }
     return null;

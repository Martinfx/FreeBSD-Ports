--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-core/src/main/java/org/apache/hadoop/mapreduce/util/ProcessTree.java.orig	2019-04-21 12:22:36 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-core/src/main/java/org/apache/hadoop/mapreduce/util/ProcessTree.java
@@ -53,14 +53,14 @@ public class ProcessTree {
     ShellCommandExecutor shexec = null;
     boolean setsidSupported = true;
     try {
-      String[] args = {"setsid", "bash", "-c", "echo $$"};
+      String[] args = {"ssid", "bash", "-c", "echo $$"};
       shexec = new ShellCommandExecutor(args);
       shexec.execute();
     } catch (IOException ioe) {
-      LOG.warn("setsid is not available on this machine. So not using it.");
+      LOG.warn("ssid is not available on this machine. So not using it.");
       setsidSupported = false;
     } finally { // handle the exit code
-      LOG.info("setsid exited with exit code " + shexec.getExitCode());
+      LOG.info("ssid exited with exit code " + shexec.getExitCode());
     }
     return setsidSupported;
   }

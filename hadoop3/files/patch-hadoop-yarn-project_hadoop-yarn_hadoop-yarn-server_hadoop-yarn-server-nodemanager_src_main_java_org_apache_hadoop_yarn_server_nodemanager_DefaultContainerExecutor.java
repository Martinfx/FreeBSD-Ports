--- hadoop-yarn-project/hadoop-yarn/hadoop-yarn-server/hadoop-yarn-server-nodemanager/src/main/java/org/apache/hadoop/yarn/server/nodemanager/DefaultContainerExecutor.java.orig	2018-10-19 02:30:34 UTC
+++ hadoop-yarn-project/hadoop-yarn/hadoop-yarn-server/hadoop-yarn-server-nodemanager/src/main/java/org/apache/hadoop/yarn/server/nodemanager/DefaultContainerExecutor.java
@@ -480,8 +480,8 @@ public class DefaultContainerExecutor ex
       String exitCodeFile = ContainerLaunch.getExitCodeFile(
           pidFile.toString());
       String tmpFile = exitCodeFile + ".tmp";
-      pout.println("#!/bin/bash");
-      pout.println("/bin/bash \"" + sessionScriptPath.toString() + "\"");
+      pout.println("#!/usr/local/bin/bash");
+      pout.println("/usr/local/bin/bash \"" + sessionScriptPath.toString() + "\"");
       pout.println("rc=$?");
       pout.println("echo $rc > \"" + tmpFile + "\"");
       pout.println("/bin/mv -f \"" + tmpFile + "\" \"" + exitCodeFile + "\"");
@@ -497,12 +497,12 @@ public class DefaultContainerExecutor ex
         // We need to do a move as writing to a file is not atomic
         // Process reading a file being written to may get garbled data
         // hence write pid to tmp file first followed by a mv
-        pout.println("#!/bin/bash");
+        pout.println("#!/usr/local/bin/bash");
         pout.println();
         pout.println("echo $$ > " + pidFile.toString() + ".tmp");
         pout.println("/bin/mv -f " + pidFile.toString() + ".tmp " + pidFile);
-        String exec = Shell.isSetsidAvailable? "exec setsid" : "exec";
-        pout.printf("%s /bin/bash \"%s\"", exec, launchDst.toUri().getPath());
+        String exec = Shell.isSetsidAvailable? "exec ssid" : "exec";
+        pout.printf("%s /usr/local/bin/bash \"%s\"", exec, launchDst.toUri().getPath());
       }
       lfs.setPermission(sessionScriptPath,
           ContainerExecutor.TASK_LAUNCH_SCRIPT_PERMISSION);

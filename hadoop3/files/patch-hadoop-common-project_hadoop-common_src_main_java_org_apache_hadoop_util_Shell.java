--- hadoop-common-project/hadoop-common/src/main/java/org/apache/hadoop/util/Shell.java.orig	2023-06-14 01:21:13 UTC
+++ hadoop-common-project/hadoop-common/src/main/java/org/apache/hadoop/util/Shell.java
@@ -848,14 +848,14 @@ public abstract class Shell {
     ShellCommandExecutor shexec = null;
     boolean setsidSupported = true;
     try {
-      String[] args = {"setsid", "bash", "-c", "echo $$"};
+      String[] args = {"ssid", "bash", "-c", "echo $$"};
       shexec = new ShellCommandExecutor(args);
       shexec.execute();
     } catch (IOException ioe) {
-      LOG.debug("setsid is not available on this machine. So not using it.");
+      LOG.debug("ssid is not available on this machine. So not using it.");
       setsidSupported = false;
     } catch (SecurityException se) {
-      LOG.debug("setsid is not allowed to run by the JVM "+
+      LOG.debug("ssid is not allowed to run by the JVM "+
           "security manager. So not using it.");
       setsidSupported = false;
     } catch (Error err) {
@@ -870,7 +870,7 @@ public abstract class Shell {
       }
     }  finally { // handle the exit code
       if (LOG.isDebugEnabled()) {
-        LOG.debug("setsid exited with exit code "
+        LOG.debug("ssid exited with exit code "
                  + (shexec != null ? shexec.getExitCode() : "(null executor)"));
       }
     }

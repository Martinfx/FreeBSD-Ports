--- src/System.Management.Automation/utils/tracing/SysLogProvider.cs.orig	2024-09-21 21:06:29 UTC
+++ src/System.Management.Automation/utils/tracing/SysLogProvider.cs
@@ -290,7 +290,7 @@ namespace System.Management.Automation.Tracing
             int threadId = Environment.CurrentManagedThreadId;
             string message = string.Format(CultureInfo.InvariantCulture,
                                            "({0}:{1:X}:{2:X}) [Transfer]:{3} {4}",
-                                           PSVersionInfo.GitCommitId, threadId, PSChannel.Operational,
+                                           "0", threadId, PSChannel.Operational,
                                            parentActivityId.ToString("B"),
                                            Activity.ToString("B"));
 
@@ -309,7 +309,7 @@ namespace System.Management.Automation.Tracing
             // NOTE: always log
             string message = string.Format(CultureInfo.InvariantCulture,
                                            "({0:X}:{1:X}:{2:X}) [Activity] {3}",
-                                           PSVersionInfo.GitCommitId, threadId, PSChannel.Operational, activity.ToString("B"));
+                                           "0", threadId, PSChannel.Operational, activity.ToString("B"));
             NativeMethods.SysLog(NativeMethods.SysLogPriority.Info, message);
         }
 
@@ -335,7 +335,7 @@ namespace System.Management.Automation.Tracing
                 // add the message preamble
                 sb.AppendFormat(CultureInfo.InvariantCulture,
                                 "({0}:{1:X}:{2:X}) [{3:G}:{4:G}.{5:G}.{6:G}] ",
-                                PSVersionInfo.GitCommitId, threadId, channel, eventId, task, opcode, level);
+                                "0", threadId, channel, eventId, task, opcode, level);
 
                 // add the message
                 GetEventMessage(sb, eventId, args);

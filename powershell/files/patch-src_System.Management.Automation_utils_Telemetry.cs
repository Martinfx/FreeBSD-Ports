--- src/System.Management.Automation/utils/Telemetry.cs.orig	2024-09-21 20:59:37 UTC
+++ src/System.Management.Automation/utils/Telemetry.cs
@@ -862,7 +862,7 @@ namespace Microsoft.PowerShell.Telemetry
             // Construct the payload for the OS and shell details.
             properties.Add("SessionId", s_sessionId);
             properties.Add("UUID", s_uniqueUserIdentifier);
-            properties.Add("GitCommitID", PSVersionInfo.GitCommitId);
+            //properties.Add("GitCommitID", PSVersionInfo.GitCommitId);
             properties.Add("OSDescription", RuntimeInformation.OSDescription);
             properties.Add("RuntimeIdentifier", RuntimeInformation.RuntimeIdentifier);
             properties.Add("OSChannel", string.IsNullOrEmpty(channel) ? "unknown" : channel);

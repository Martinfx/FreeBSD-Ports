--- src/System.Management.Automation/utils/Telemetry.cs.orig	2024-11-14 22:14:58 UTC
+++ src/System.Management.Automation/utils/Telemetry.cs
@@ -927,7 +927,7 @@ namespace Microsoft.PowerShell.Telemetry
             // Construct the payload for the OS and shell details.
             properties.Add("SessionId", s_sessionId);
             properties.Add("UUID", s_uniqueUserIdentifier);
-            properties.Add("GitCommitID", PSVersionInfo.GitCommitId);
+            //properties.Add("GitCommitID", PSVersionInfo.GitCommitId);
             properties.Add("OSDescription", RuntimeInformation.OSDescription);
             properties.Add("RuntimeIdentifier", RuntimeInformation.RuntimeIdentifier);
             properties.Add("OSChannel", string.IsNullOrEmpty(channel) ? "unknown" : channel);

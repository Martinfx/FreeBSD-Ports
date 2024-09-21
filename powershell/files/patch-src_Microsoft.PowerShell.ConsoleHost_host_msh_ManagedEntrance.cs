--- src/Microsoft.PowerShell.ConsoleHost/host/msh/ManagedEntrance.cs.orig	2024-09-21 21:28:00 UTC
+++ src/Microsoft.PowerShell.ConsoleHost/host/msh/ManagedEntrance.cs
@@ -89,7 +89,7 @@ namespace Microsoft.PowerShell
                 var banner = string.Format(
                     CultureInfo.InvariantCulture,
                     ManagedEntranceStrings.ShellBannerNonWindowsPowerShell,
-                    PSVersionInfo.GitCommitId);
+                    "null");
 
                 ConsoleHost.DefaultInitialSessionState = InitialSessionState.CreateDefault2();
 

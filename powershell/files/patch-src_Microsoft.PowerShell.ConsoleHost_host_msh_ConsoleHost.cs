--- src/Microsoft.PowerShell.ConsoleHost/host/msh/ConsoleHost.cs.orig	2024-09-21 21:25:26 UTC
+++ src/Microsoft.PowerShell.ConsoleHost/host/msh/ConsoleHost.cs
@@ -181,7 +181,7 @@ namespace Microsoft.PowerShell
                     // Alternatively, we could call s_theConsoleHost.UI.WriteLine(s_theConsoleHost.Version.ToString());
                     // or start up the engine and retrieve the information via $psversiontable.GitCommitId
                     // but this returns the semantic version and avoids executing a script
-                    s_theConsoleHost.UI.WriteLine($"PowerShell {PSVersionInfo.GitCommitId}");
+                    s_theConsoleHost.UI.WriteLine($"PowerShell {0}");
                     return 0;
                 }
 

--- src/Microsoft.PowerShell.ConsoleHost/host/msh/ConsoleHost.cs.orig	2024-11-14 22:14:58 UTC
+++ src/Microsoft.PowerShell.ConsoleHost/host/msh/ConsoleHost.cs
@@ -193,7 +193,7 @@ namespace Microsoft.PowerShell
                     // Alternatively, we could call s_theConsoleHost.UI.WriteLine(s_theConsoleHost.Version.ToString());
                     // or start up the engine and retrieve the information via $psversiontable.GitCommitId
                     // but this returns the semantic version and avoids executing a script
-                    s_theConsoleHost.UI.WriteLine($"PowerShell {PSVersionInfo.GitCommitId}");
+                    s_theConsoleHost.UI.WriteLine($"PowerShell {0}");
                     return 0;
                 }
 

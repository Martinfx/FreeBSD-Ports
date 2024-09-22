--- src/System.Management.Automation/security/SecuritySupport.cs.orig	2024-09-21 21:01:33 UTC
+++ src/System.Management.Automation/security/SecuritySupport.cs
@@ -1361,13 +1361,13 @@ namespace System.Management.Automation
                 string appName;
                 try
                 {
-                    appName = string.Concat("PowerShell_", Environment.ProcessPath, "_", PSVersionInfo.ProductVersion);
+                    appName = string.Concat("PowerShell_", Environment.ProcessPath, "_"); // PSVersionInfo.ProductVersion);
                 }
                 catch (Exception)
                 {
                     // Fall back to 'Process.ProcessName' in case 'Environment.ProcessPath' throws exception.
                     Process currentProcess = Process.GetCurrentProcess();
-                    appName = string.Concat("PowerShell_", currentProcess.ProcessName, ".exe_", PSVersionInfo.ProductVersion);
+                    appName = string.Concat("PowerShell_", currentProcess.ProcessName, ".exe_"); // PSVersionInfo.ProductVersion);
                 }
 
                 AppDomain.CurrentDomain.ProcessExit += CurrentDomain_ProcessExit;

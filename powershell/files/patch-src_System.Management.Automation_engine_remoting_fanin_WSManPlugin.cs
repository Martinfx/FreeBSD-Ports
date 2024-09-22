--- src/System.Management.Automation/engine/remoting/fanin/WSManPlugin.cs.orig	2024-09-21 21:14:43 UTC
+++ src/System.Management.Automation/engine/remoting/fanin/WSManPlugin.cs
@@ -1227,7 +1227,7 @@ namespace System.Management.Automation.Remoting
                             StringUtil.Format(
                                 RemotingErrorIdStrings.WSManPluginOptionNotUnderstood,
                                 option.name,
-                                System.Management.Automation.PSVersionInfo.GitCommitId,
+                                null,
                                 WSManPluginConstants.PowerShellStartupProtocolVersionValue));
                         return false;
                     }
@@ -1242,7 +1242,7 @@ namespace System.Management.Automation.Remoting
                     StringUtil.Format(
                         RemotingErrorIdStrings.WSManPluginProtocolVersionNotFound,
                         WSManPluginConstants.PowerShellStartupProtocolVersionName,
-                        System.Management.Automation.PSVersionInfo.GitCommitId,
+                        null,
                         WSManPluginConstants.PowerShellStartupProtocolVersionValue));
                 return false;
             }
@@ -1284,7 +1284,7 @@ namespace System.Management.Automation.Remoting
                 StringUtil.Format(
                     RemotingErrorIdStrings.WSManPluginProtocolVersionNotMatch,
                     WSManPluginConstants.PowerShellStartupProtocolVersionValue,
-                    System.Management.Automation.PSVersionInfo.GitCommitId,
+                    null,
                     clientVersionString));
             return false;
         }

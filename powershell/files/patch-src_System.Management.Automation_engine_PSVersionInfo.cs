--- src/System.Management.Automation/engine/PSVersionInfo.cs.orig	2024-04-11 18:38:22 UTC
+++ src/System.Management.Automation/engine/PSVersionInfo.cs
@@ -85,14 +85,14 @@ namespace System.Management.Automation
         {
             s_psVersionTable = new PSVersionHashTable(StringComparer.OrdinalIgnoreCase);
 
-            s_psSemVersion = Version_Label == string.Empty
+            /*s_psSemVersion = Version_Label == string.Empty
                 ? new SemanticVersion(Version_Major, Version_Minor, Version_Patch)
-                : new SemanticVersion(Version_Major, Version_Minor, Version_Patch, Version_Label, buildLabel: null);
-            s_psVersion = (Version)s_psSemVersion;
+                : new SemanticVersion(Version_Major, Version_Minor, Version_Patch, Version_Label, buildLabel: null);*/
+            s_psVersion = Version.Parse("7.2.4");
 
             s_psVersionTable[PSVersionName] = s_psSemVersion;
             s_psVersionTable[PSEditionName] = PSEditionValue;
-            s_psVersionTable[PSGitCommitIdName] = GitCommitId;
+            s_psVersionTable[PSGitCommitIdName] = 0;
             s_psVersionTable[PSCompatibleVersionsName] = new Version[] { s_psV1Version, s_psV2Version, s_psV3Version, s_psV4Version, s_psV5Version, s_psV51Version, s_psV6Version, s_psV7Version };
             s_psVersionTable[SerializationVersionName] = new Version(InternalSerializer.DefaultVersion);
             s_psVersionTable[PSRemotingProtocolVersionName] = RemotingConstants.ProtocolVersion;

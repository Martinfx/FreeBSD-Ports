--- src/Microsoft.PowerShell.ConsoleHost/host/msh/UpdatesNotification.cs.orig	2024-09-21 21:22:08 UTC
+++ src/Microsoft.PowerShell.ConsoleHost/host/msh/UpdatesNotification.cs
@@ -62,7 +62,7 @@ namespace Microsoft.PowerShell
             if (CanNotifyUpdates)
             {
                 s_enumOptions = new EnumerationOptions();
-                s_cacheDirectory = Path.Combine(Platform.CacheDirectory, PSVersionInfo.GitCommitId);
+                s_cacheDirectory = Path.Combine(Platform.CacheDirectory, "null");
 
                 // Build the template/pattern strings for the configured notification type.
                 string typeNum = ((int)s_notificationType).ToString();
@@ -139,10 +139,10 @@ namespace Microsoft.PowerShell
             // A self-built pwsh for development purpose has the SHA1 commit hash baked in 'GitCommitId',
             // which is 40 characters long. So we can quickly check the length of 'GitCommitId' to tell
             // if this is a self-built pwsh, and skip the update check if so.
-            if (PSVersionInfo.GitCommitId.Length > 40)
-            {
-                return;
-            }
+            //if (PSVersionInfo.GitCommitId.Length > 40)
+            //{
+            //    return;
+            //}
 
             // Daily builds do not support update notifications
             string preReleaseLabel = PSVersionInfo.PSCurrentVersion.PreReleaseLabel;
@@ -353,7 +353,7 @@ namespace Microsoft.PowerShell
 
             using var client = new HttpClient();
 
-            string userAgent = string.Create(CultureInfo.InvariantCulture, $"PowerShell {PSVersionInfo.GitCommitId}");
+            string userAgent = string.Create(CultureInfo.InvariantCulture, $"PowerShell {0}");
             client.DefaultRequestHeaders.Add("User-Agent", userAgent);
             client.DefaultRequestHeaders.Accept.Add(new MediaTypeWithQualityHeaderValue("application/json"));
 

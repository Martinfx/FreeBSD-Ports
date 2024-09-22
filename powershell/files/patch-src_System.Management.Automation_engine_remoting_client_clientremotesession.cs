--- src/System.Management.Automation/engine/remoting/client/clientremotesession.cs.orig	2024-09-21 21:15:52 UTC
+++ src/System.Management.Automation/engine/remoting/client/clientremotesession.cs
@@ -528,7 +528,7 @@ namespace System.Management.Automation.Remoting
                     new PSRemotingDataStructureException(RemotingErrorIdStrings.ClientNegotiationFailed,
                         RemoteDataNameStrings.PS_STARTUP_PROTOCOL_VERSION_NAME,
                         serverProtocolVersion,
-                        PSVersionInfo.GitCommitId,
+                        null,
                         RemotingConstants.ProtocolVersion);
                 throw reasonOfFailure;
             }
@@ -542,7 +542,7 @@ namespace System.Management.Automation.Remoting
                     new PSRemotingDataStructureException(RemotingErrorIdStrings.ClientNegotiationFailed,
                         RemoteDataNameStrings.PSVersion,
                         serverPSVersion.ToString(),
-                        PSVersionInfo.GitCommitId,
+                        null,
                         RemotingConstants.ProtocolVersion);
                 throw reasonOfFailure;
             }
@@ -556,7 +556,7 @@ namespace System.Management.Automation.Remoting
                     new PSRemotingDataStructureException(RemotingErrorIdStrings.ClientNegotiationFailed,
                         RemoteDataNameStrings.SerializationVersion,
                         serverSerVersion.ToString(),
-                        PSVersionInfo.GitCommitId,
+                        null,
                         RemotingConstants.ProtocolVersion);
                 throw reasonOfFailure;
             }

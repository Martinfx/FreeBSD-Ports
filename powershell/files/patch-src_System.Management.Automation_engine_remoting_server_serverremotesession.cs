--- src/System.Management.Automation/engine/remoting/server/serverremotesession.cs.orig	2024-09-21 21:12:37 UTC
+++ src/System.Management.Automation/engine/remoting/server/serverremotesession.cs
@@ -1006,7 +1006,7 @@ namespace System.Management.Automation.Remoting
                         new PSRemotingDataStructureException(RemotingErrorIdStrings.ServerConnectFailedOnNegotiation,
                             RemoteDataNameStrings.PS_STARTUP_PROTOCOL_VERSION_NAME,
                             clientProtocolVersion,
-                            PSVersionInfo.GitCommitId,
+                            null,
                             RemotingConstants.ProtocolVersion);
                     throw reasonOfFailure;
                 }
@@ -1056,7 +1056,7 @@ namespace System.Management.Automation.Remoting
                         new PSRemotingDataStructureException(RemotingErrorIdStrings.ServerNegotiationFailed,
                             RemoteDataNameStrings.PS_STARTUP_PROTOCOL_VERSION_NAME,
                             clientProtocolVersion,
-                            PSVersionInfo.GitCommitId,
+                            null,
                             RemotingConstants.ProtocolVersion);
                     throw reasonOfFailure;
                 }
@@ -1072,7 +1072,7 @@ namespace System.Management.Automation.Remoting
                     new PSRemotingDataStructureException(RemotingErrorIdStrings.ServerNegotiationFailed,
                         RemoteDataNameStrings.PSVersion,
                         clientPSVersion,
-                        PSVersionInfo.GitCommitId,
+                        null,
                         RemotingConstants.ProtocolVersion);
                 throw reasonOfFailure;
             }
@@ -1087,7 +1087,7 @@ namespace System.Management.Automation.Remoting
                     new PSRemotingDataStructureException(RemotingErrorIdStrings.ServerNegotiationFailed,
                         RemoteDataNameStrings.SerializationVersion,
                         clientSerVersion,
-                        PSVersionInfo.GitCommitId,
+                        null,
                         RemotingConstants.ProtocolVersion);
                 throw reasonOfFailure;
             }

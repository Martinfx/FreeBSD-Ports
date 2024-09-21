--- src/System.Management.Automation/engine/remoting/client/remotingprotocolimplementation.cs.orig	2024-09-21 21:17:14 UTC
+++ src/System.Management.Automation/engine/remoting/client/remotingprotocolimplementation.cs
@@ -637,7 +637,7 @@ namespace System.Management.Automation.Remoting
                         // this will happen if expected properties are not
                         // received for session capability
                         throw new PSRemotingDataStructureException(RemotingErrorIdStrings.ClientNotFoundCapabilityProperties,
-                            dse.Message, PSVersionInfo.GitCommitId, RemotingConstants.ProtocolVersion);
+                            dse.Message, null, RemotingConstants.ProtocolVersion);
                     }
 
                     RemoteSessionStateMachineEventArgs capabilityArg = new RemoteSessionStateMachineEventArgs(RemoteSessionEvent.NegotiationReceived);

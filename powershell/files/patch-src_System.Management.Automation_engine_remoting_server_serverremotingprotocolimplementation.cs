--- src/System.Management.Automation/engine/remoting/server/serverremotingprotocolimplementation.cs.orig	2024-09-21 21:09:29 UTC
+++ src/System.Management.Automation/engine/remoting/server/serverremotingprotocolimplementation.cs
@@ -210,7 +210,7 @@ namespace System.Management.Automation.Remoting
                         // this will happen if expected properties are not
                         // received for session capability
                         throw new PSRemotingDataStructureException(RemotingErrorIdStrings.ServerNotFoundCapabilityProperties,
-                            dse.Message, PSVersionInfo.GitCommitId, RemotingConstants.ProtocolVersion);
+                            dse.Message, null, RemotingConstants.ProtocolVersion);
                     }
 
                     RemoteSessionStateMachineEventArgs capabilityArg = new RemoteSessionStateMachineEventArgs(RemoteSessionEvent.NegotiationReceived);

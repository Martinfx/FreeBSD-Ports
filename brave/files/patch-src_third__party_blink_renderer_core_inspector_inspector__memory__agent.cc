--- src/third_party/blink/renderer/core/inspector/inspector_memory_agent.cc.orig	2026-11-24 12:50:30 UTC
+++ src/third_party/blink/renderer/core/inspector/inspector_memory_agent.cc
@@ -210,7 +210,7 @@ InspectorMemoryAgent::GetSamplingProfile
 
 Vector<String> InspectorMemoryAgent::Symbolize(
     const std::vector<const void*>& addresses) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // TODO(alph): Move symbolization to the client.
   Vector<const void*> addresses_to_symbolize;
   for (const void* address : addresses) {

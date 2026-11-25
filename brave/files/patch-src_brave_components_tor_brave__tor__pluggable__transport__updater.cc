--- src/brave/components/tor/brave_tor_pluggable_transport_updater.cc.orig	2026-11-24 12:50:30 UTC
+++ src/brave/components/tor/brave_tor_pluggable_transport_updater.cc
@@ -23,7 +23,10 @@ namespace tor {
 constexpr const char kComponentName[] = "Brave Pluggable Transports (Windows)";
 #elif BUILDFLAG(IS_MAC)
 constexpr const char kComponentName[] = "Brave Pluggable Transports (Mac)";
-#elif BUILDFLAG(IS_LINUX)
+// As in components/tor/constants.h: this chain declares the component name
+// once per platform and has no fallback, so FreeBSD needs a branch of its own
+// to declare it at all.
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr const char kComponentName[] = "Brave Pluggable Transports (Linux)";
 #endif
 

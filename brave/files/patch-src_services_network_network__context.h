--- src/services/network/network_context.h.orig	2026-11-24 12:50:30 UTC
+++ src/services/network/network_context.h
@@ -837,7 +837,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE)
    public:
     explicit NetworkContextHttpAuthPreferences(NetworkService* network_service);
     ~NetworkContextHttpAuthPreferences() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     bool AllowGssapiLibraryLoad() const override;
 #endif  // BUILDFLAG(IS_LINUX)
    private:

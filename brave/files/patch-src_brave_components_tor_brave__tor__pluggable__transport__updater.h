--- src/brave/components/tor/brave_tor_pluggable_transport_updater.h.orig	2026-11-02 23:22:33 UTC
+++ src/brave/components/tor/brave_tor_pluggable_transport_updater.h
@@ -43,7 +43,9 @@ inline constexpr uint8_t kTorPluggableTr
     0xaa, 0xb0, 0xf4, 0xda, 0x33, 0x5c, 0x23, 0x2a, 0x37, 0xd9};
 static_assert(std::size(kTorPluggableTransportComponentPublicKeySHA256) ==
               crypto::kSHA256Length);
-#elif BUILDFLAG(IS_LINUX)
+// No branch here would leave the key undeclared on FreeBSD, see
+// components/tor/constants.h.
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 inline constexpr uint8_t kTorPluggableTransportComponentPublicKeySHA256[32] = {
     0x0f, 0x56, 0x68, 0x05, 0xe1, 0x0a, 0x90, 0x7d, 0xa2, 0x78, 0x42,
     0x1e, 0xc9, 0x68, 0x6a, 0xad, 0x02, 0x8f, 0x08, 0xf0, 0xb1, 0x3e,

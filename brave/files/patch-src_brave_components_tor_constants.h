--- src/brave/components/tor/constants.h.orig	2026-11-02 23:22:33 UTC
+++ src/brave/components/tor/constants.h
@@ -35,7 +35,11 @@ inline constexpr uint8_t kTorClientCompo
     0x2e, 0xce, 0xfa, 0x83, 0x65, 0xd5, 0x33, 0x2c, 0x13, 0xb2};
 static_assert(std::size(kTorClientComponentPublicKeySHA256) ==
               crypto::kSHA256Length);
-#elif BUILDFLAG(IS_LINUX)
+// The Tor client component is not published for FreeBSD.  Nothing here
+// selects a fallback, so without a branch the names below are undeclared and
+// every user of them fails to compile; the Linux component is the one a
+// FreeBSD build would ask for.
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 inline constexpr char kTorClientComponentName[] =
     "Brave Tor Client Updater (Linux)";
 #if defined(ARCH_CPU_ARM64)

--- src/extensions/common/command.cc.orig	2026-11-02 23:22:33 UTC
+++ src/extensions/common/command.cc
@@ -117,7 +117,7 @@ std::string Command::CommandPlatform() {
   return ui::kKeybindingPlatformMac;
 #elif BUILDFLAG(IS_CHROMEOS)
   return ui::kKeybindingPlatformChromeOs;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ui::kKeybindingPlatformLinux;
 #elif BUILDFLAG(IS_ANDROID)
   // For now, we use linux keybindings on desktop android.

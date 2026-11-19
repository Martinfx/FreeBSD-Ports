--- ui/linux/linux_ui.cc.orig	2026-11-19 22:06:00 UTC
+++ ui/linux/linux_ui.cc
@@ -44,7 +44,7 @@ PrintingContextLinuxDelegate* PrintingCo
 
 // static
 LinuxUi* LinuxUi::SetInstance(LinuxUi* instance) {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(ENABLE_PRINTING)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_PRINTING)
   PrintingContextLinuxDelegate::SetInstance(instance);
 #endif
 

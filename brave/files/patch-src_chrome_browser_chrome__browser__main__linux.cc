--- src/chrome/browser/chrome_browser_main_linux.cc.orig	2026-11-02 23:22:33 UTC
+++ src/chrome/browser/chrome_browser_main_linux.cc
@@ -24,7 +24,7 @@
 #include "device/bluetooth/dbus/bluez_dbus_manager.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/public/ozone_platform.h"
 #if BUILDFLAG(USE_DBUS)
 #include "components/dbus/thread_linux/dbus_thread_linux.h"
@@ -82,8 +82,10 @@ void ChromeBrowserMainPartsLinux::PostCr
 
 #if !BUILDFLAG(IS_CHROMEOS)
 #if BUILDFLAG(USE_DBUS)
+#if !BUILDFLAG(IS_BSD)
   bluez::BluezDBusManager::Initialize(
       dbus_thread_linux::GetSharedSystemBus().get());
+#endif
   session_end_listener_ = SessionEndListenerLinux::Create();
 #endif  // BUILDFLAG(USE_DBUS)
 #endif  // !BUILDFLAG(IS_CHROMEOS)
@@ -91,7 +93,7 @@ void ChromeBrowserMainPartsLinux::PostCr
   ChromeBrowserMainPartsPosix::PostCreateMainMessageLoop();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromeBrowserMainPartsLinux::PostMainMessageLoopRun() {
   ChromeBrowserMainPartsPosix::PostMainMessageLoopRun();
   ui::OzonePlatform::GetInstance()->PostMainMessageLoopRun();
@@ -125,7 +127,7 @@ void ChromeBrowserMainPartsLinux::PostBr
 #endif  // BUILDFLAG(USE_DBUS) && !BUILDFLAG(IS_CHROMEOS)
 
 void ChromeBrowserMainPartsLinux::PostDestroyThreads() {
-#if BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // No-op; per PostBrowserStart() comment, this is done elsewhere.
 #else
 #if BUILDFLAG(USE_DBUS)

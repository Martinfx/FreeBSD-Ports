--- content/browser/renderer_host/render_widget_host_view_aura.cc.orig	2024-04-19 13:02:56 UTC
+++ content/browser/renderer_host/render_widget_host_view_aura.cc
@@ -119,7 +119,7 @@
 #include "ui/gfx/gdi_util.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/browser/accessibility/browser_accessibility_auralinux.h"
 #include "ui/base/ime/linux/text_edit_command_auralinux.h"
 #include "ui/base/ime/text_input_flags.h"
@@ -452,7 +452,7 @@ gfx::NativeViewAccessible RenderWidgetHostViewAura::Ge
     return ToBrowserAccessibilityWin(manager->GetBrowserAccessibilityRoot())
         ->GetCOM();
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   BrowserAccessibilityManager* manager =
       host()->GetOrCreateRootBrowserAccessibilityManager();
   if (manager && manager->GetBrowserAccessibilityRoot())
@@ -1705,7 +1705,7 @@ bool RenderWidgetHostViewAura::ShouldDoLearning() {
   return host_->delegate() && host_->delegate()->ShouldDoLearning();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool RenderWidgetHostViewAura::SetCompositionFromExistingText(
     const gfx::Range& range,
     const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) {
@@ -2538,7 +2538,7 @@ bool RenderWidgetHostViewAura::NeedsInputGrab() {
 }
 
 bool RenderWidgetHostViewAura::NeedsMouseCapture() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   return NeedsInputGrab();
 #else
   return false;
@@ -2722,7 +2722,7 @@ void RenderWidgetHostViewAura::ForwardKeyboardEventWit
   if (!target_host)
     return;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* linux_ui = ui::LinuxUi::instance();
   std::vector<ui::TextEditCommandAuraLinux> commands;
   if (!event.skip_if_unhandled && linux_ui && event.os_event &&

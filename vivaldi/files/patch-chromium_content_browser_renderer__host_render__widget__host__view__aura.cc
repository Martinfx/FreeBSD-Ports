--- chromium/content/browser/renderer_host/render_widget_host_view_aura.cc.orig	2026-09-02 06:36:52 UTC
+++ chromium/content/browser/renderer_host/render_widget_host_view_aura.cc
@@ -134,7 +134,7 @@
 #include "ui/gfx/win/gdi_util.h"
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/accessibility/platform/browser_accessibility_auralinux.h"
 #include "ui/base/ime/linux/text_edit_command_auralinux.h"
 #include "ui/base/ime/text_input_flags.h"
@@ -583,7 +583,7 @@ gfx::NativeViewAccessible RenderWidgetHo
     return ToBrowserAccessibilityWin(manager->GetBrowserAccessibilityRoot())
         ->GetCOM();
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ui::BrowserAccessibilityManager* manager =
       host()->GetOrCreateRootBrowserAccessibilityManager();
   if (manager && manager->GetBrowserAccessibilityRoot())
@@ -1438,7 +1438,7 @@ RenderWidgetHostViewAura::CreateSyntheti
 
 blink::mojom::InputEventResultState RenderWidgetHostViewAura::FilterInputEvent(
     const blink::WebInputEvent& input_event) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (vivaldi::IsVivaldiRunning()) {
     // The renderer will send a ViewHostMsg_SelectionChanged whenever there has
     // been a change in the selected text and for whatever reason. The host
@@ -2079,7 +2079,7 @@ bool RenderWidgetHostViewAura::ShouldDoL
   return host() && host()->delegate() && host()->delegate()->ShouldDoLearning();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool RenderWidgetHostViewAura::SetCompositionFromExistingText(
     const gfx::Range& range,
     const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) {
@@ -3168,7 +3168,7 @@ bool RenderWidgetHostViewAura::NeedsInpu
 }
 
 bool RenderWidgetHostViewAura::NeedsMouseCapture() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return NeedsInputGrab();
 #else
   return false;
@@ -3396,7 +3396,7 @@ void RenderWidgetHostViewAura::ForwardKe
   if (!target_host)
     return;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* linux_ui = ui::LinuxUi::instance();
   if (!event.skip_if_unhandled && linux_ui && event.os_event) {
     const auto command = linux_ui->GetTextEditCommandForEvent(
@@ -3610,7 +3610,7 @@ void RenderWidgetHostViewAura::OnTextSel
   if (ui::Clipboard::IsSupportedClipboardBuffer(
           ui::ClipboardBuffer::kSelection)) {
     if (vivaldi::IsVivaldiRunning()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Selection changes from both UI (this) and document arrive here. We need
       // to test for UI and possibly reject a selection change from being
       // written to the selection buffer further down as a change will happen

--- src/main.rs.orig
+++ src/main.rs
@@ -31,6 +31,9 @@
         winapi::um::shellscalingapi::SetProcessDpiAwareness(2);
     }
     if let Some(args) = crate::core_main::core_main().as_mut() {
+        #[cfg(feature = "egui")]
+        ui_egui::start(args);
+        #[cfg(not(feature = "egui"))]
         ui::start(args);
     }
     common::global_clean();

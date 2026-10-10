--- gui/src/taskconfigdialog.cpp.orig	2026-10-10 00:00:00 UTC
+++ gui/src/taskconfigdialog.cpp
@@ -475,7 +475,8 @@
 
     // EncoderConfig
     taskConfig.outputSuffix = ui->suffixLineEdit->text();
-    taskConfig.encCfg.copy_streams = ui->copyStreamsCheckBox->isChecked();
+    taskConfig.encCfg.copy_audio_streams = ui->copyStreamsCheckBox->isChecked();
+    taskConfig.encCfg.copy_subtitle_streams = ui->copyStreamsCheckBox->isChecked();
 
     // Rate control and compression
     taskConfig.encCfg.bit_rate = ui->bitRateSpinBox->value();
@@ -680,8 +681,9 @@
     // Suffix
     ui->suffixLineEdit->setText(taskConfig.outputSuffix);
 
-    // copy_streams
-    ui->copyStreamsCheckBox->setChecked(taskConfig.encCfg.copy_streams);
+    // copy_audio_streams and copy_subtitle_streams
+    ui->copyStreamsCheckBox->setChecked(taskConfig.encCfg.copy_audio_streams
+                                        || taskConfig.encCfg.copy_subtitle_streams);
 
     // frameRateMultiplier (only relevant if Interpolate)
     if (procMode == video2x::processors::ProcessingMode::Interpolate) {

--- SeerMainWindow.cpp.orig	2023-03-05 22:19:00 UTC
+++ SeerMainWindow.cpp
@@ -1080,7 +1080,7 @@ void SeerMainWindow::readConfigSettings () {
     } settings.endGroup();
 
     settings.beginGroup("gdb"); {
-        gdbWidget->setGdbProgram(settings.value("program", "/usr/bin/gdb").toString());
+        gdbWidget->setGdbProgram(settings.value("program", "%%LOCALBASE%%/bin/gdb").toString());
         gdbWidget->setGdbArguments(settings.value("arguments", "--interpreter=mi").toString());
         gdbWidget->setGdbAsyncMode(settings.value("asyncmode", true).toBool());
         gdbWidget->setGdbNonStopMode(settings.value("nonstopmode", false).toBool());

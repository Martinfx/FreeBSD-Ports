--- SeerGdbWidget.cpp.orig	2023-01-02 17:28:30 UTC
+++ SeerGdbWidget.cpp
@@ -47,7 +47,7 @@ SeerGdbWidget::SeerGdbWidget (QWidget* parent) : QWidg
     _catchpointsBrowserWidget           = 0;
     _gdbOutputLog                       = 0;
     _seerOutputLog                      = 0;
-    _gdbProgram                         = "/usr/bin/gdb";
+    _gdbProgram                         = "%%LOCALBASE%%/bin/gdb";
     _gdbArguments                       = "--interpreter=mi";
     _gdbASyncMode                       = true;
     _gdbNonStopMode                     = false;

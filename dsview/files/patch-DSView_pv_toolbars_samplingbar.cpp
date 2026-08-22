--- DSView/pv/toolbars/samplingbar.cpp.orig	2026-08-07 20:27:38 UTC
+++ DSView/pv/toolbars/samplingbar.cpp
@@ -25,7 +25,7 @@
 #include <QLabel>
 #include <QAbstractItemView>
 #include <math.h>
-#include <libusb-1.0/libusb.h>
+#include "libusb.h"
 #include "../dialogs/deviceoptions.h"
 #include "../dialogs/waitingdialog.h"
 #include "../dialogs/dsmessagebox.h"

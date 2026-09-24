--- desktop-apps/win-linux/src/windows/platform_linux/cwindowplatform.cpp.orig	2026-09-24 22:04:11 UTC
+++ desktop-apps/win-linux/src/windows/platform_linux/cwindowplatform.cpp
@@ -36,6 +36,7 @@
 #include "utils.h"
 #include <QTimer>
 #include <QPainter>
+#include <QPainterPath>
 #include <QX11Info>
 #include <xcb/xcb.h>
 

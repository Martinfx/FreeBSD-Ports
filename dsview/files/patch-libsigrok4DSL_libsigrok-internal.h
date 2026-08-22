--- libsigrok4DSL/libsigrok-internal.h.orig	2026-08-07 20:38:53 UTC
+++ libsigrok4DSL/libsigrok-internal.h
@@ -24,7 +24,7 @@
 #include <glib.h>
 #include <ds_types.h>
 #include "config.h" /* Needed for HAVE_LIBUSB_1_0 and others. */
-#include <libusb-1.0/libusb.h>
+#include <libusb.h>
 #include "libsigrok.h"
 
 /**

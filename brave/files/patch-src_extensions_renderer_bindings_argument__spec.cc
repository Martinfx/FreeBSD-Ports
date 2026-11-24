--- src/extensions/renderer/bindings/argument_spec.cc.orig	2026-11-24 12:50:30 UTC
+++ src/extensions/renderer/bindings/argument_spec.cc
@@ -20,6 +20,8 @@
 #include "gin/data_object_builder.h"
 #include "gin/dictionary.h"
 
+#include <cmath>
+
 namespace extensions {
 
 namespace {

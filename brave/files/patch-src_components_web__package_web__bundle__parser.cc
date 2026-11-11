--- src/components/web_package/web_bundle_parser.cc.orig	2026-11-02 23:22:33 UTC
+++ src/components/web_package/web_bundle_parser.cc
@@ -2,6 +2,8 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#if 0
+// XXX crubit
 #include "components/web_package/web_bundle_parser.h"
 
 #include <algorithm>
@@ -547,3 +549,4 @@ bool WebBundleParser::CheckIfClosed() {
 }
 
 }  // namespace web_package
+#endif 

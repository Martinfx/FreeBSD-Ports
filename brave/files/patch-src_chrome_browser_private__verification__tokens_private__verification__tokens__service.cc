--- src/chrome/browser/private_verification_tokens/private_verification_tokens_service.cc.orig	2026-11-02 23:22:33 UTC
+++ src/chrome/browser/private_verification_tokens/private_verification_tokens_service.cc
@@ -2,6 +2,7 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#if 0
 #include "chrome/browser/private_verification_tokens/private_verification_tokens_service.h"
 
 #include <map>
@@ -695,3 +696,4 @@ void PrivateVerificationTokensService::O
     std::move(operation).Run();
   }
 }
+#endif

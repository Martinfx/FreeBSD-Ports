--- web-apps/apps/api/documents/api.js.orig	2026-09-29 05:02:10 UTC
+++ web-apps/apps/api/documents/api.js
@@ -999,7 +999,10 @@
 
         var _onMessage = function(msg) {
             // TODO: check message origin
-            if (msg && window.JSON && _scope.frameOrigin==msg.origin ) {
+            // The pages of the desktop editors are file:// ones, whose messages
+            // newer Chromium gives the origin "null" (Gateway.js of the editors
+            // takes that into account too)
+            if (msg && window.JSON && (_scope.frameOrigin==msg.origin || (msg.origin==="null" && _scope.frameOrigin==="file://")) ) {
                 if (msg.data && msg.data.event === 'onSaveDocument') {
                     if (_fn) {
                         _fn.call(_scope, msg.data);

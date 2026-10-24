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
@@ -1274,7 +1277,14 @@
         iframe.allowFullscreen = true;
         iframe.setAttribute("allowfullscreen",""); // for IE11
         iframe.setAttribute("onmousewheel",""); // for Safari on Mac
-        iframe.setAttribute("allow", "autoplay; camera; microphone; display-capture; clipboard-write;");
+        // Newer Chromium enforces the permissions policy of the asynchronous
+        // Clipboard API, which the editors copy with.  An allow attribute
+        // without an origin only delegates a feature to the origin of the
+        // src, and the file:// pages of the desktop editors do not match it,
+        // so navigator.clipboard.write() is refused: nothing copied in the
+        // editors reaches the clipboard.  Delegate it to the frame whatever
+        // its origin.
+        iframe.setAttribute("allow", "autoplay; camera; microphone; display-capture; clipboard-write *;");
 
 		if (config.type == "mobile")
 		{

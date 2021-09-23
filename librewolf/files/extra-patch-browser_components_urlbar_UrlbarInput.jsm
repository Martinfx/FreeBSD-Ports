--- browser/components/urlbar/UrlbarInput.jsm.orig	2021-09-23 14:10:03 UTC
+++ browser/components/urlbar/UrlbarInput.jsm
@@ -1692,13 +1692,13 @@ class UrlbarInput {
 
     // Enable the animation only after the first extend call to ensure it
     // doesn't run when opening a new window.
-    if (!this.hasAttribute("breakout-extend-animate")) {
-      this.window.promiseDocumentFlushed(() => {
-        this.window.requestAnimationFrame(() => {
-          this.setAttribute("breakout-extend-animate", "true");
-        });
-      });
-    }
+//    if (!this.hasAttribute("breakout-extend-animate")) {
+//      this.window.promiseDocumentFlushed(() => {
+//        this.window.requestAnimationFrame(() => {
+//          this.setAttribute("breakout-extend-animate", "true");
+//        });
+//      });
+//    }
   }
 
   endLayoutExtend() {

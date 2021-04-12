--- node_modules/mocha/lib/reporters/base.js.orig	2021-03-20 17:12:17 UTC
+++ node_modules/mocha/lib/reporters/base.js
@@ -208,20 +208,9 @@ exports.list = function (failures) {
     if (err.uncaught) {
       msg = 'Uncaught ' + msg;
     }
-
     // explicitly show diff
-<<<<<<< HEAD
-    if (showDiff(err)) {
+    if (!exports.hideDiff && showDiff(err)) {
       stringifyDiffObjs(err);
-=======
-    if (exports.hideDiff !== true && err.showDiff !== false && sameType(actual, expected) && expected !== undefined) {
-      escape = false;
-      if (!(utils.isString(actual) && utils.isString(expected))) {
-        err.actual = actual = utils.stringify(actual);
-        err.expected = expected = utils.stringify(expected);
-      }
-
->>>>>>> Add --no-diff option (fixes mochajs/mocha#2514)
       fmt = color('error title', '  %s) %s:\n%s') + color('error stack', '\n%s\n');
       var match = message.match(/^([^:]+): expected/);
       msg = '\n      ' + color('error message', match ? match[1] : msg);

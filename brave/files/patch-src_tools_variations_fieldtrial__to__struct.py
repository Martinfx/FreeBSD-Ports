--- src/tools/variations/fieldtrial_to_struct.py.orig	2026-11-24 12:50:30 UTC
+++ src/tools/variations/fieldtrial_to_struct.py
@@ -31,6 +31,8 @@ _platforms = [
   'linux',
   'mac',
   'windows',
+  'openbsd',
+  'freebsd',
 ]
 
 _form_factors = [

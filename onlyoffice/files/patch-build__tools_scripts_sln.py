--- build_tools/scripts/sln.py.orig	2025-09-23 21:37:40 UTC
+++ build_tools/scripts/sln.py
@@ -30,6 +30,7 @@ def adjust_project_params(params):
   all_windows = []
   all_windows_xp = []
   all_linux = []
+  all_freebsd = []
   all_mac = []
   all_android = []
 
@@ -40,6 +41,8 @@ def adjust_project_params(params):
         all_windows_xp.append(i)
     elif (0 == i.find("linux")):
       all_linux.append(i)
+    elif (0 == i.find("freebsd")):
+      all_freebsd.append(i)
     elif (0 == i.find("mac")):
       all_mac.append(i)
     elif (0 == i.find("android")):
@@ -60,6 +63,11 @@ def adjust_project_params(params):
   if is_exist_in_array(params, "!linux"):
     ret_params += ["!" + x for x in all_linux]
 
+  if is_exist_in_array(params, "freebsd"):
+    ret_params += all_freebsd
+  if is_exist_in_array(params, "!freebsd"):
+    ret_params += ["!" + x for x in all_freebsd]
+
   if is_exist_in_array(params, "mac"):
     ret_params += all_mac
   if is_exist_in_array(params, "!mac"):
@@ -127,7 +135,7 @@ def get_projects(pro_json_path, platform):
 
       platform_records = []
       platform_records += config.platforms
-      platform_records += ["win", "win_xp", "linux", "mac", "android"]
+      platform_records += ["win", "win_xp", "linux", "freebsd", "mac", "android"]
 
       # if one platform exists => all needed must exists
       is_needed_platform_exist = False

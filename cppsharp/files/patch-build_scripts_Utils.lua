--- build/scripts/Utils.lua.orig	2024-06-05 21:44:33 UTC
+++ build/scripts/Utils.lua
@@ -96,10 +96,12 @@ end
 function download(url, file, try)
   print("Downloading: " .. url)
   local prev = 0
-  local res, code = http.download(url, file, function(total, curr)
-    http.progress(total, prev, curr)
-    prev = curr
-  end)
+  local cmd = "wget " ..  url
+  local res = execute(cmd)
+--  local res, code = http.download(url, file, function(total, curr)
+--    http.progress(total, prev, curr)
+--    prev = curr
+--  end)
 
   if res ~= "OK" then
     os.remove(file)
@@ -109,7 +111,12 @@ function download(url, file, try)
     end
   end
   
-  return res, code
+  return "OK"
+end
+
+function unix_host_architecture()
+  result, errorCode = os.outputof("uname -m")
+  return result
 end
 
 --
@@ -202,4 +209,4 @@ function os.rmfiles(src_dir, filter)
     print( "Error: " .. counter .. "/" .. #matches .. " files removed.")
     return nil
   end
-end
\ No newline at end of file
+end

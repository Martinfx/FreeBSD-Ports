--- premake5.lua.orig	2024-05-25 13:31:50 UTC
+++ premake5.lua
@@ -11,6 +11,8 @@ if os.istarget("linux") then
 -- Only use this to enable architecture-specific functionality.
 if os.istarget("linux") then
   ARCH = os.outputof("uname -p")
+elseif os.istarget("freebsd") then
+  ARCH = os.outputof("uname -p")
 else
   ARCH = "unknown"
 end
@@ -39,9 +41,6 @@ characterset("Unicode")
 end
 
 characterset("Unicode")
-flags({
-  "FatalWarnings",        -- Treat warnings as errors.
-})
 
 filter("kind:StaticLib")
   defines({
@@ -75,6 +74,11 @@ filter({"configurations:Debug", "platforms:Linux"})
     "_GLIBCXX_DEBUG",   -- make dbg symbols work on some distros
   })
 
+filter({"configurations:Debug", "platforms:FreeBSD"})
+  defines({
+    "_GLIBCXX_DEBUG",   -- make dbg symbols work on some distros
+  })
+
 filter("configurations:Release")
   runtime("Release")
   defines({
@@ -107,6 +111,21 @@ filter("platforms:Linux")
     "rt",
   })
 
+filter("platforms:FreeBSD")
+  system("bsd")
+  toolset("clang")
+  buildoptions({
+    -- "-mlzcnt",  -- (don't) Assume lzcnt is supported.
+  })
+  pkg_config.all("gtk+-x11-3.0")
+  links({
+    "stdc++fs",
+    "lz4",
+    "pthread",
+  })
+
+
+
 filter({"platforms:Linux", "kind:*App"})
   linkgroups("On")
 
@@ -136,6 +155,16 @@ filter({"platforms:Linux", "language:C++", "toolset:cl
     "-stdlib=libstdc++",
   })
 
+
+filter({"platforms:FreeBSD", "language:C++", "toolset:clang"})
+  disablewarnings({
+    "deprecated-register"
+  })
+filter({"platforms:FreeBSD", "language:C++", "toolset:clang", "files:*.cc or *.cpp"})
+  buildoptions({
+    "-stdlib=libstdc++",
+  })
+
 filter("platforms:Android-*")
   system("android")
   systemversion("24")
@@ -222,6 +251,10 @@ workspace("xenia")
     architecture("x86_64")
     if os.istarget("linux") then
       platforms({"Linux"})
+    elseif os.istarget("freebsd") then
+      platforms({"FreeBSD"})
+      ["ARCHS"] = "x86_64"
+      systemversion(uname -r)
     elseif os.istarget("macosx") then
       platforms({"Mac"})
       xcodebuildsettings({           
@@ -277,6 +310,9 @@ workspace("xenia")
     })
   end
 
+  includedirs { "/usr/local/include",
+  		"/usr/local/include/gtk-3.0" }
+  
   include("src/xenia")
   include("src/xenia/app")
   include("src/xenia/app/discord")

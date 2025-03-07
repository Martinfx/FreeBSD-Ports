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
@@ -107,6 +111,35 @@ filter("platforms:Linux")
     "rt",
   })
 
+filter { "configurations:Debug" }
+    defines { "DEBUG" }
+
+filter("system:bsd")
+  includedirs {
+    "/usr/local/include",
+    "/usr/local/include/gtk-3.0"
+  }
+  libdirs { "/usr/local/lib" }
+  links {
+    "gtk-3",
+    "gdk-3",
+    "pangocairo-1.0",
+    "pango-1.0",
+    "atk-1.0",
+    "cairo-gobject",
+    "cairo",
+    "gdk_pixbuf-2.0",
+    "gio-2.0",
+    "glib-2.0",
+    "gobject-2.0",
+    "gthread-2.0",
+    "pthread",
+    "SDL2"
+  }
+  buildoptions { "`pkg-config --cflags gtk+-3.0`" }
+  linkoptions { "`pkg-config --libs gtk+-3.0`" }
+  linkgroups("On")	
+
 filter({"platforms:Linux", "kind:*App"})
   linkgroups("On")
 
@@ -136,6 +169,16 @@ filter({"platforms:Linux", "language:C++", "toolset:cl
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
@@ -222,6 +265,9 @@ workspace("xenia")
     architecture("x86_64")
     if os.istarget("linux") then
       platforms({"Linux"})
+    elseif os.istarget("freebsd") then
+      platforms({"FreeBSD"})
+      systemversion(uname -r)
     elseif os.istarget("macosx") then
       platforms({"Mac"})
       xcodebuildsettings({           
@@ -276,7 +322,7 @@ workspace("xenia")
       "FatalWarnings",
     })
   end
-
+  
   include("src/xenia")
   include("src/xenia/app")
   include("src/xenia/app/discord")

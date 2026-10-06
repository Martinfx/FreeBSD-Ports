--- external/CppCommon/source/environment.cpp.orig	2026-10-06 04:21:17 UTC
+++ external/CppCommon/source/environment.cpp
@@ -53,6 +53,16 @@ std::string Environment::OSVersion() {
     }
 
     return "<cygwin>";
+#elif defined(__FreeBSD__)
+    struct utsname name;
+    if (uname(&name) == 0) {
+        std::string result(name.sysname);
+        result.append(" ");
+        result.append(name.release);
+        return result;
+    }
+
+    return "<freebsd>";
 #elif defined(linux) || defined(__linux) || defined(__linux__)
     static std::regex pattern("DISTRIB_DESCRIPTION=\"(.*)\"");
 

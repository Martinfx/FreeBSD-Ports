--- src/Target.cpp.orig	2019-09-28 00:30:49 UTC
+++ src/Target.cpp
@@ -61,6 +61,9 @@ static void cpuid(int info[4], int infoType, int extra
 
 Target calculate_host_target() {
     Target::OS os = Target::OSUnknown;
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+    os = Target::BSD;
+#endif
 #ifdef __linux__
     os = Target::Linux;
 #endif
@@ -264,6 +267,7 @@ Target::Feature get_host_cuda_capability(Target t) {
 
 const std::map<std::string, Target::OS> os_name_map = {
     {"os_unknown", Target::OSUnknown},
+    {"bsd", Target::BSD},
     {"linux", Target::Linux},
     {"windows", Target::Windows},
     {"osx", Target::OSX},

--- externals/hwinfo/src/linux/ram.cpp.orig	2025-09-25 06:31:59 UTC
+++ externals/hwinfo/src/linux/ram.cpp
@@ -13,6 +13,13 @@
 #include <string>
 #include <vector>
 
+#if defined(__linux__)
+  #include <sys/sysinfo.h>
+#elif defined(__FreeBSD__)
+  #include <sys/types.h>
+  #include <sys/sysctl.h>
+#endif
+
 namespace hwinfo {
 
 // _____________________________________________________________________________________________________________________
@@ -23,15 +30,25 @@ void get_from_sysconf(MemInfo& mi) {
 };
 
 void get_from_sysconf(MemInfo& mi) {
-  int64_t pages = sysconf(_SC_PHYS_PAGES);
-  int64_t available_pages = sysconf(_SC_AVPHYS_PAGES);
-  int64_t page_size = sysconf(_SC_PAGESIZE);
-  if (pages > 0 && page_size > 0) {
-    mi.total = pages * page_size;
-  }
-  if (available_pages > 0 && page_size > 0) {
-    mi.available = available_pages * page_size;
-  }
+#if defined(__linux__)
+	int64_t pages = sysconf(_SC_PHYS_PAGES);
+	int64_t available_pages = sysconf(_SC_AVPHYS_PAGES);
+	int64_t page_size = sysconf(_SC_PAGESIZE);
+	if (pages > 0 && page_size > 0) {
+     	mi.total = pages * page_size;
+	}
+  	if (available_pages > 0 && page_size > 0) {
+    	mi.available = available_pages * page_size;
+  	}
+
+
+#elif defined(__FreeBSD__)
+    int page_sz = 0;
+    size_t sz = sizeof(page_sz);
+    if (sysctlbyname("hw.pagesize", &page_sz, &sz, nullptr, 0) != 0 || page_sz <= 0) {
+        mi.total = page_sz;
+	}
+#endif
 }
 
 void set_value(std::string& line, int64_t* dst) {

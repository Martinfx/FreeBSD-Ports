--- src/components/update_client/update_query_params.cc.orig	2026-11-24 12:50:30 UTC
+++ src/components/update_client/update_query_params.cc
@@ -33,7 +33,12 @@ constexpr std::string_view kOs =
     "android";
 #elif BUILDFLAG(IS_CHROMEOS)
     "cros";
-#elif BUILDFLAG(IS_LINUX)
+// FreeBSD says "linux" here on purpose.  This string goes into the update
+// protocol as the platform, and no update server knows a "freebsd" one, so
+// announcing it gets every component rejected -- CRLSet, the ad block list
+// catalog and the rest all stay at 0.0.0.0 with an update error.  Keep the
+// OpenBSD branch below untouched, hence IS_FREEBSD and not IS_BSD.
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FREEBSD)
     "linux";
 #elif BUILDFLAG(IS_FUCHSIA)
     "fuchsia";

--- components/datasource/vivaldi_data_source.cc.orig	2026-08-25 00:00:00 UTC
+++ components/datasource/vivaldi_data_source.cc
@@ -91,7 +91,7 @@ std::string VivaldiDataSource::GetMimeTy
   // drag the image they get no extension.
   // The |path| received here had its first '/' stripped
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Determining mime-type triggers file access on Linux. We must keep this
   // synchronous. TODO: Can we avoid it? Original issue VB-109734
   base::VivaldiScopedAllowBlocking allow_blocking;

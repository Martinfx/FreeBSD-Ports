--- library/forms/password_cache.cpp.orig	2024-05-18 21:40:29 UTC
+++ library/forms/password_cache.cpp
@@ -46,14 +46,14 @@ PasswordCache::PasswordCache() {
     logError("Unable to allocate memory for password cache, caching will be disabled (errno %i)\n", errno);
 #ifdef HAVE_MLOCK
   else {
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
+//#pragma GCC diagnostic push
+//#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
     if (mlock(storage, storage_size) < 0) {
       logError("mlock password cache (errno %i)\n", errno);
       free(storage);
       storage = NULL;
     }
-#pragma GCC diagnostic pop
+//#pragma GCC diagnostic pop
   }
 #endif
 }

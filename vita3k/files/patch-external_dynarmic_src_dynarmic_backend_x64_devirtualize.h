--- external/dynarmic/src/dynarmic/backend/x64/devirtualize.h.orig	2026-10-06 04:22:04 UTC
+++ external/dynarmic/src/dynarmic/backend/x64/devirtualize.h
@@ -66,7 +66,7 @@ ArgCallback DevirtualizeItanium(mcl::cla
 
 template<auto mfp>
 ArgCallback Devirtualize(mcl::class_type<decltype(mfp)>* this_) {
-#if defined(__APPLE__) || defined(linux) || defined(__linux) || defined(__linux__)
+#if defined(__APPLE__) || defined(linux) || defined(__linux) || defined(__linux__) || defined(__FreeBSD__)
     return DevirtualizeItanium<mfp>(this_);
 #elif defined(__MINGW64__)
     return DevirtualizeItanium<mfp>(this_);

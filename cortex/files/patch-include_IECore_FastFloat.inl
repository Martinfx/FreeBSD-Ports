--- include/IECore/FastFloat.inl.orig	2026-09-24 18:05:26 UTC
+++ include/IECore/FastFloat.inl
@@ -41,7 +41,7 @@ namespace IECore
 {
 #define IECORE_DOUBLEMAGICROUNDEPS	(.5-1.4e-11)
 
-#if (defined(__linux__) && ( defined(__i386__) || defined(__x86_64__) ) ) || defined(WIN32)
+#if ( ( defined(__linux__) || defined(__FreeBSD__) ) && ( defined(__i386__) || defined(__x86_64__) ) ) || defined(WIN32)
 	#define IECORE_DOUBLEMAGIC			double (6755399441055744.0)
 
 	inline int fastFloat2Int( double v )

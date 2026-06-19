--- core/DesktopEditor/common/Types.h.orig	2025-09-24 10:40:53 UTC
+++ core/DesktopEditor/common/Types.h
@@ -78,7 +78,7 @@ typedef wchar_t			WCHAR;
 typedef unsigned int	UINT, *PUINT;
 typedef wchar_t			WCHAR;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <inttypes.h>
 typedef int64_t     T_LONG64;
 typedef uint64_t    T_ULONG64;

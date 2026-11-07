--- core/DesktopEditor/common/Types.h.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/common/Types.h
@@ -81,7 +81,7 @@
 typedef unsigned int	UINT, *PUINT;
 typedef wchar_t			WCHAR;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <inttypes.h>
 typedef int64_t     T_LONG64;
 typedef uint64_t    T_ULONG64;

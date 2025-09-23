--- core/DesktopEditor/common/Types.h.orig	2025-09-23 23:07:02 UTC
+++ core/DesktopEditor/common/Types.h
@@ -78,7 +78,7 @@ typedef wchar_t			WCHAR;
 typedef unsigned int	UINT, *PUINT;
 typedef wchar_t			WCHAR;
 
-#ifdef __linux__
+#ifdef __linux__ || __FreeBSD__
 #include <inttypes.h>
 typedef int64_t     T_LONG64;
 typedef uint64_t    T_ULONG64;

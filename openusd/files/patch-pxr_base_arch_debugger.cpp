--- pxr/base/arch/debugger.cpp.orig	2025-10-24 16:21:56 UTC
+++ pxr/base/arch/debugger.cpp
@@ -14,7 +14,7 @@
 #include "pxr/base/arch/export.h"
 #include "pxr/base/arch/stackTrace.h"
 #include "pxr/base/arch/systemInfo.h"
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN) || defined(ARCH_OS_FREEBSD)
 #include "pxr/base/arch/inttypes.h"
 #include <sys/types.h>
 #if !defined(ARCH_OS_IPHONE)
@@ -35,9 +35,12 @@
 #include <string_view>
 #include <system_error>
 #endif
-#if defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_DARWIN) || defined(ARCH_OS_FREEBSD)
 #include <sys/sysctl.h>
 #endif
+#if defined(ARCH_OS_FREEBSD)
+#include <sys/user.h>
+#endif
 #if defined(ARCH_OS_WINDOWS)
 #include <Windows.h>
 #endif
@@ -59,7 +62,7 @@ static char** _archDebuggerAttachArgs = 0;
 
 static char** _archDebuggerAttachArgs = 0;
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN) || defined(ARCH_OS_FREEBSD)
 static
 void
 Arch_DebuggerTrapHandler(int)
@@ -74,7 +77,7 @@ Arch_DebuggerTrapHandler(int)
 }
 #endif
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN) || defined(ARCH_OS_FREEBSD)
 static
 void
 Arch_DebuggerInitPosix()
@@ -108,7 +111,7 @@ Arch_DebuggerInit()
 void
 Arch_DebuggerInit()
 {
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN) || defined(ARCH_OS_FREEBSD)
 #if defined(ARCH_CPU_INTEL) && defined(ARCH_BITS_64)
     // Save some registers that normally don't have to be preserved.  We
     // do this so the caller of ArchDebuggerTrap() can see its arguments
@@ -153,7 +156,7 @@ Arch_DebuggerInit()
 }
 
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN) || defined(ARCH_OS_FREEBSD)
 // Use a 'non-locking' fork so that we won't get hung up if we've
 // had malloc corruption.  We can't prevent fork() from using the
 // heap, unfortunately, since fork handlers can do whatever they
@@ -429,6 +432,19 @@ AmIBeingDebugged()
     return junk == 0 && ( (info.kp_proc.p_flag & P_TRACED) != 0 );
 }
 
+#elif defined(ARCH_OS_FREEBSD)
+static bool
+AmIBeingDebugged()
+{
+    int junk;
+    struct kinfo_proc info;
+    size_t size;
+    int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, getpid() };
+    size = sizeof(info);
+
+    junk = sysctl(mib, sizeof(mib) / sizeof(*mib), &info, &size, NULL, 0);
+    return (junk == 0);
+}
 #endif // defined(ARCH_OS_LINUX)
 
 static
@@ -443,7 +459,7 @@ Arch_DebuggerAttach()
         return false;
     }
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN) || defined(ARCH_OS_FREEBSD)
 
     // To attach to gdb under Unix/Linux and Gnome:
     //   ARCH_DEBUGGER="gnome-terminal -e 'gdb -p %p'"
@@ -500,7 +516,7 @@ Arch_InitDebuggerAttach()
 void
 Arch_InitDebuggerAttach()
 {
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN) || defined(ARCH_OS_FREEBSD)
     // Maximum length of a pid written as a decimal.  It's okay for this
     // to be greater than that.
     static const size_t _decimalPidLength = 20;
@@ -631,6 +647,8 @@ ArchDebuggerIsAttached()
 #if defined(ARCH_OS_WINDOWS)
     return IsDebuggerPresent() == TRUE;
 #elif defined(ARCH_OS_DARWIN)
+    return AmIBeingDebugged();
+#elif defined(ARCH_OS_FREEBSD)
     return AmIBeingDebugged();
 #elif defined(ARCH_OS_LINUX)
     return Arch_DebuggerIsAttachedPosix();

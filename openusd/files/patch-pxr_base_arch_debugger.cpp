--- pxr/base/arch/debugger.cpp.orig	2026-04-24 18:55:54 UTC
+++ pxr/base/arch/debugger.cpp
@@ -14,7 +14,7 @@
 #include "pxr/base/arch/export.h"
 #include "pxr/base/arch/stackTrace.h"
 #include "pxr/base/arch/systemInfo.h"
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 #include "pxr/base/arch/inttypes.h"
 #include <sys/types.h>
 #if !defined(ARCH_OS_IPHONE)
@@ -39,6 +39,10 @@
 #if defined(ARCH_OS_DARWIN)
 #include <sys/sysctl.h>
 #endif
+#if defined(ARCH_OS_FREEBSD)
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#endif
 #if defined(ARCH_OS_WINDOWS)
 #include <Windows.h>
 #endif
@@ -60,7 +64,7 @@ static std::atomic<bool> _archDebuggerWa
 
 static char** _archDebuggerAttachArgs = 0;
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 static
 void
 Arch_DebuggerTrapHandler(int)
@@ -75,7 +79,7 @@ Arch_DebuggerTrapHandler(int)
 }
 #endif
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 static
 void
 Arch_DebuggerInitPosix()
@@ -109,7 +113,7 @@ static
 void
 Arch_DebuggerInit()
 {
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 #if defined(ARCH_CPU_INTEL) && defined(ARCH_BITS_64)
     // Save some registers that normally don't have to be preserved.  We
     // do this so the caller of ArchDebuggerTrap() can see its arguments
@@ -154,7 +158,7 @@ Arch_DebuggerInit()
 }
 
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 // Use a 'non-locking' fork so that we won't get hung up if we've
 // had malloc corruption.  We can't prevent fork() from using the
 // heap, unfortunately, since fork handlers can do whatever they
@@ -436,6 +440,23 @@ AmIBeingDebugged()
     return junk == 0 && ( (info.kp_proc.p_flag & P_TRACED) != 0 );
 }
 
+#elif defined(ARCH_OS_FREEBSD)
+
+// Returns true if the current process is being traced, i.e. a debugger
+// started it or has been attached post facto.  Unlike the Linux code this
+// does not need procfs.
+static bool
+Arch_DebuggerIsAttachedFreeBSD()
+{
+    struct kinfo_proc info;
+    size_t size = sizeof(info);
+    int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, getpid() };
+
+    info.ki_flag = 0;
+    return sysctl(mib, 4, &info, &size, NULL, 0) == 0 &&
+        (info.ki_flag & P_TRACED) != 0;
+}
+
 #endif // defined(ARCH_OS_LINUX)
 
 static
@@ -450,7 +471,7 @@ Arch_DebuggerAttach()
         return false;
     }
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 
     // To attach to gdb under Unix/Linux and Gnome:
     //   ARCH_DEBUGGER="gnome-terminal -e 'gdb -p %p'"
@@ -507,7 +528,7 @@ ARCH_HIDDEN
 void
 Arch_InitDebuggerAttach()
 {
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
     // Maximum length of a pid written as a decimal.  It's okay for this
     // to be greater than that.
     static const size_t _decimalPidLength = 20;
@@ -641,6 +662,8 @@ ArchDebuggerIsAttached()
     return AmIBeingDebugged();
 #elif defined(ARCH_OS_LINUX)
     return Arch_DebuggerIsAttachedPosix();
+#elif defined(ARCH_OS_FREEBSD)
+    return Arch_DebuggerIsAttachedFreeBSD();
 #endif
     return false;
 }

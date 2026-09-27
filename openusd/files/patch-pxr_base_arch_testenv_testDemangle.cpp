--- pxr/base/arch/testenv/testDemangle.cpp.orig	2026-04-24 18:55:54 UTC
+++ pxr/base/arch/testenv/testDemangle.cpp
@@ -121,6 +121,10 @@ int main()
     const char* const badType = "type_that_doesnt_exist";
 #if defined(ARCH_OS_WINDOWS)
     ARCH_AXIOM(ArchGetDemangled(badType) == badType);
+#elif defined(ARCH_OS_FREEBSD)
+    // libcxxrt's __cxa_demangle() ignores trailing garbage, so this
+    // "demangles" to "unsigned short" ('t') instead of failing.
+    (void)badType;
 #else
     ARCH_AXIOM(ArchGetDemangled(badType) == "");
 #endif

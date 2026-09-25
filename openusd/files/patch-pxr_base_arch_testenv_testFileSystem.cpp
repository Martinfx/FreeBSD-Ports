--- pxr/base/arch/testenv/testFileSystem.cpp.orig	2026-04-24 18:55:54 UTC
+++ pxr/base/arch/testenv/testFileSystem.cpp
@@ -105,6 +105,12 @@ int main()
     // Test utf-8 path
     std::string secondName = ArchMakeTmpFileName("测试");
     ARCH_AXIOM((firstFile = ArchOpenFile(secondName.c_str(), "w")) != NULL);
+#if defined(ARCH_OS_FREEBSD)
+    // FreeBSD finds the name of an open file in the name cache, to which
+    // open(2) does not add the files it creates, and UFS cannot find the name
+    // of a file otherwise.  Looking the name up adds it.
+    ArchGetFileLength(secondName.c_str());
+#endif
     filePath = ArchGetFileName(firstFile);
     ARCH_AXIOM(std::filesystem::equivalent(std::filesystem::u8path(filePath),
                std::filesystem::u8path(secondName)));

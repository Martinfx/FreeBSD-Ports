--- src/lib/utility/Platform.cpp.orig	2025-09-10 13:57:11 UTC
+++ src/lib/utility/Platform.cpp
@@ -7,7 +7,7 @@ static_assert(BOOST_ARCH_WORD_BITS == 32 || BOOST_ARCH
 
 // Can't use BOOST_ARCH_WORD_BITS_32/BOOST_ARCH_WORD_BITS_64 because they are *both* defined!
 static_assert(BOOST_ARCH_WORD_BITS == 32 || BOOST_ARCH_WORD_BITS == 64, "Unknown architecture!");
-static_assert(BOOST_OS_WINDOWS || BOOST_OS_MACOS || BOOST_OS_LINUX, "Unknown operating system!");
+static_assert(BOOST_OS_WINDOWS || BOOST_OS_MACOS || BOOST_OS_LINUX || BOOST_OS_BSD_FREE, "Unknown operating system!");
 
 string Platform::getName()
 {
@@ -17,6 +17,9 @@ string Platform::getName()
 		return "Windows"s;
 	else if constexpr (isMac())
 		return "Mac"s;
+	else if constexpr (isBSD())
+		return "FreeBSD"s;
+
 }
 
 Platform::Architecture Platform::getArchitecture()

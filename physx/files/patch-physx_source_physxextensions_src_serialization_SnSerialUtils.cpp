--- physx/source/physxextensions/src/serialization/SnSerialUtils.cpp.orig	2024-07-05 09:57:32 UTC
+++ physx/source/physxextensions/src/serialization/SnSerialUtils.cpp
@@ -39,7 +39,7 @@ using namespace physx;
 namespace
 {
 
-#define SN_NUM_BINARY_PLATFORMS 16
+#define SN_NUM_BINARY_PLATFORMS 17
 const PxU32 sBinaryPlatformTags[SN_NUM_BINARY_PLATFORMS] =
 {
 	PX_MAKE_FOURCC('W','_','3','2'),
@@ -78,6 +78,7 @@ const char* sBinaryPlatformNames[SN_NUM_BINARY_PLATFOR
 	"linuxaarch64",
 	"uwparm",
 	"uwparm64",
+	"freebsd",
 };
 
 }
@@ -118,6 +119,8 @@ PxU32 getBinaryPlatformTag()
 	return sBinaryPlatformTags[14];
 #elif PX_UWP && PX_A64
 	return sBinaryPlatformTags[15];
+#elif PX_FREEBSD
+        return sBinaryPlatformTags[16];
 #else
 	#error Unknown binary platform
 #endif

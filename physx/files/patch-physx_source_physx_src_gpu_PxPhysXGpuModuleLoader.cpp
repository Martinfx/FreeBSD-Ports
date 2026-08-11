--- physx/source/physx/src/gpu/PxPhysXGpuModuleLoader.cpp.orig	2024-07-05 09:55:45 UTC
+++ physx/source/physx/src/gpu/PxPhysXGpuModuleLoader.cpp
@@ -40,7 +40,7 @@
 #include "common/windows/PxWindowsDelayLoadHook.h"
 #include "windows/PsWindowsInclude.h"
 #include "windows/CmWindowsModuleUpdateLoader.h"
-#elif PX_LINUX
+#elif PX_LINUX || PX_FREEBSD
 #include <dlfcn.h>
 #endif // ~PX_LINUX
 
@@ -131,7 +131,7 @@ namespace physx
 		}
 	}
 
-#elif PX_LINUX
+#elif PX_LINUX || PX_FREEBSD
 
 	void PxLoadPhysxGPUModule(const char*)
 	{

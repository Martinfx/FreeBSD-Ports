--- contrib/IECoreUSD/src/IECoreUSD/bindings/IEUSDModule.cpp.orig	2026-09-10 21:49:58 UTC
+++ contrib/IECoreUSD/src/IECoreUSD/bindings/IEUSDModule.cpp
@@ -39,8 +39,11 @@
 
 #include "IECore/IndexedIO.h"
 
-#if PXR_VERSION >= 2505
-#include "pxr/external/boost/python.hpp"
+#if PXR_VERSION >= 2505 && defined( PXR_PYTHON_SUPPORT_ENABLED )
+// Only `object` is needed. The umbrella header also includes `dealloc.hpp`,
+// whose `extern "C"` `dealloc()` is the same function as the one from
+// `boost/python/detail/dealloc.hpp`, and clang rejects the redefinition.
+#include "pxr/external/boost/python/object.hpp"
 #endif
 
 #include "boost/python.hpp"
@@ -90,7 +93,7 @@
 	return vectorToList( path );
 }
 
-#if PXR_VERSION >= 2505
+#if PXR_VERSION >= 2505 && defined( PXR_PYTHON_SUPPORT_ENABLED )
 
 // Registers `boost::python` converters for types
 // wrapped using `pxr_boost::python`.
@@ -119,13 +122,13 @@
 
 };
 
-#endif // PXR_VERSION >= 2505
+#endif // PXR_VERSION >= 2505 && defined( PXR_PYTHON_SUPPORT_ENABLED )
 
 } // namespace
 
 BOOST_PYTHON_MODULE( _IECoreUSD )
 {
-#if PXR_VERSION >= 2505
+#if PXR_VERSION >= 2505 && defined( PXR_PYTHON_SUPPORT_ENABLED )
 	PxrBoostConverter<pxr::TfToken>::registerConverters();
 	PxrBoostConverter<pxr::VtValue>::registerConverters();
 	PxrBoostConverter<pxr::SdfValueTypeName>::registerConverters();

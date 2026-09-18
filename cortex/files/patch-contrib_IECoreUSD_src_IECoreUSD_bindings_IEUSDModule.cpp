--- contrib/IECoreUSD/src/IECoreUSD/bindings/IEUSDModule.cpp.orig	2026-09-10 21:49:58 UTC
+++ contrib/IECoreUSD/src/IECoreUSD/bindings/IEUSDModule.cpp
@@ -39,7 +39,7 @@
 
 #include "IECore/IndexedIO.h"
 
-#if PXR_VERSION >= 2505
+#if PXR_VERSION >= 2505 && defined( PXR_PYTHON_SUPPORT_ENABLED )
 #include "pxr/external/boost/python.hpp"
 #endif
 
@@ -90,7 +90,7 @@
 	return vectorToList( path );
 }
 
-#if PXR_VERSION >= 2505
+#if PXR_VERSION >= 2505 && defined( PXR_PYTHON_SUPPORT_ENABLED )
 
 // Registers `boost::python` converters for types
 // wrapped using `pxr_boost::python`.
@@ -119,13 +119,13 @@
 
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

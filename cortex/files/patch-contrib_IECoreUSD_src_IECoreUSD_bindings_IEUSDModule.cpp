--- contrib/IECoreUSD/src/IECoreUSD/bindings/IEUSDModule.cpp.orig	2026-09-24 18:05:26 UTC
+++ contrib/IECoreUSD/src/IECoreUSD/bindings/IEUSDModule.cpp
@@ -39,8 +39,10 @@
 
 #include "IECore/IndexedIO.h"
 
-#if PXR_VERSION >= 2505
-#include "pxr/external/boost/python.hpp"
+#if PXR_VERSION >= 2505 && defined( PXR_PYTHON_SUPPORT_ENABLED )
+// Only include what we need, as `pxr/external/boost/python.hpp` pulls in an
+// `extern "C" dealloc()` which conflicts with the one from Boost.Python.
+#include "pxr/external/boost/python/object.hpp"
 #endif
 
 #include "boost/python.hpp"
@@ -90,7 +92,7 @@ static list fromInternalPath( list l )
 	return vectorToList( path );
 }
 
-#if PXR_VERSION >= 2505
+#if PXR_VERSION >= 2505 && defined( PXR_PYTHON_SUPPORT_ENABLED )
 
 // Registers `boost::python` converters for types
 // wrapped using `pxr_boost::python`.
@@ -119,13 +121,13 @@ struct PxrBoostConverter
 
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

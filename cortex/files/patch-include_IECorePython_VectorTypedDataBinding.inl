--- include/IECorePython/VectorTypedDataBinding.inl.orig	2026-09-10 21:49:58 UTC
+++ include/IECorePython/VectorTypedDataBinding.inl
@@ -36,6 +36,7 @@
 #define IECOREPYTHON_VECTORTYPEDDATABINDING_INL
 
 #include "boost/python.hpp"
+#include "boost/numeric/conversion/cast.hpp"
 
 #include "IECorePython/IECoreBinding.h"
 #include "IECorePython/RunTimeTypedBinding.h"

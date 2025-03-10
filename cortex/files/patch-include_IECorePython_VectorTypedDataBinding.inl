--- include/IECorePython/VectorTypedDataBinding.inl.orig	2024-11-29 12:43:42 UTC
+++ include/IECorePython/VectorTypedDataBinding.inl
@@ -36,7 +36,7 @@
 #define IECOREPYTHON_VECTORTYPEDDATABINDING_INL
 
 #include "boost/python.hpp"
-
+#include "boost/numeric/conversion/cast.hpp"
 #include "IECorePython/IECoreBinding.h"
 #include "IECorePython/RunTimeTypedBinding.h"
 

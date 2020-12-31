--- Engine/NatronEngine/appsettings_wrapper.cpp.orig	2020-12-31 15:05:21 UTC
+++ Engine/NatronEngine/appsettings_wrapper.cpp
@@ -1,17 +1,10 @@
 
 // default includes
 #include "Global/Macros.h"
-CLANG_DIAG_OFF(mismatched-tags)
-GCC_DIAG_OFF(unused-parameter)
-GCC_DIAG_OFF(missing-field-initializers)
-GCC_DIAG_OFF(missing-declarations)
-GCC_DIAG_OFF(uninitialized)
-GCC_DIAG_UNUSED_LOCAL_TYPEDEFS_OFF
 #include <shiboken.h> // produces many warnings
 #include <pysidesignal.h>
 #include <pysideproperty.h>
 #include <pyside.h>
-#include <typeresolver.h>
 #include <typeinfo>
 #include "natronengine_python.h"
 
@@ -21,8 +14,6 @@ GCC_DIAG_UNUSED_LOCAL_TYPEDEFS_OFF
 NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
 #include <PyParameter.h>
 #include <list>
-
-
 
 // Target ---------------------------------------------------------
 

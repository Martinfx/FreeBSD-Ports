--- pxr/base/tf/safeTypeCompare.h.orig	2026-04-24 18:55:54 UTC
+++ pxr/base/tf/safeTypeCompare.h
@@ -12,7 +12,9 @@
 /// Safely compare C++ RTTI type structures.
 
 #include "pxr/pxr.h"
+#include "pxr/base/arch/defines.h"
 
+#include <cstring>
 #include <typeinfo>
 
 PXR_NAMESPACE_OPEN_SCOPE
@@ -21,7 +23,18 @@
 ///
 /// Returns \c true if \p t1 and \p t2 denote the same type.
 inline bool TfSafeTypeCompare(const std::type_info& t1, const std::type_info& t2) {
+#if defined(ARCH_OS_FREEBSD)
+    // libc++ compares std::type_info by the address of the type name.  A type
+    // without a key function (e.g. SdfAssetPath) has its std::type_info in each
+    // shared object and executable that uses it, and these are only merged if
+    // they are exported from all of them.  Blender hides all its symbols, so
+    // VtValue::IsHolding<SdfAssetPath>() was false in Blender for the asset
+    // paths from USD.  Also compare the names, as libstdc++ does.
+    return t1 == t2 ||
+        (t1.name()[0] != '*' && std::strcmp(t1.name(), t2.name()) == 0);
+#else
     return t1 == t2;
+#endif
 }
 
 /// Safely perform a dynamic cast.

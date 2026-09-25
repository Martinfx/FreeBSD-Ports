--- include/IECoreGL/TypedStateComponent.h.orig	2026-09-10 21:49:58 UTC
+++ include/IECoreGL/TypedStateComponent.h
@@ -49,8 +49,13 @@
 namespace IECoreGL
 {
 
+// Note the IECOREGL_API : without it the instantiations get the build's default
+// hidden visibility, so libIECoreGL and the Python module end up with distinct
+// RTTI for the same type. Boost.Python then treats them as unrelated classes
+// ("did not match C++ signature: typeId(IECoreGL::TypedStateComponent<bool,
+// 105047>)"). IECore::TypedData is exported for the same reason.
 template<typename T, unsigned int TId>
-class TypedStateComponent : public StateComponent
+class IECOREGL_API TypedStateComponent : public StateComponent
 {
 	public :
 

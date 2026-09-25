--- include/IECoreGL/TypedStateComponent.h.orig	2026-09-25 06:01:36 UTC
+++ include/IECoreGL/TypedStateComponent.h
@@ -49,8 +49,13 @@ IECORE_POP_DEFAULT_VISIBILITY
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
 
@@ -139,7 +144,9 @@ typedef TypedStateComponent<Imath::Color
 /// Specifies the color to draw points in
 typedef TypedStateComponent<Imath::Color4f, PointColorStateComponentTypeId> PointColorStateComponent;
 
-enum GLPointsUsage
+// Exported for the same reason as TypedStateComponent : instantiations
+// inherit the hidden visibility of their template arguments.
+enum IECOREGL_API GLPointsUsage
 {
 	ForPointsOnly,
 	ForPointsAndDisks,
@@ -219,7 +226,8 @@ template<>
 IECOREGL_API void DepthMaskStateComponent::bind() const;
 
 // \todo: implement CurrentSpace, ShaderSpace, CameraSpace, ScreenSpace, RasterSpace and NDCSpace like in Renderman interface.
-enum RendererSpace
+// Exported for the same reason as GLPointsUsage.
+enum IECOREGL_API RendererSpace
 {
 	ObjectSpace,
 	WorldSpace

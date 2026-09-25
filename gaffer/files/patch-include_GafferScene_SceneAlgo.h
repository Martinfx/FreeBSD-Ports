--- include/GafferScene/SceneAlgo.h.orig	2026-09-25 06:15:48 UTC
+++ include/GafferScene/SceneAlgo.h
@@ -225,7 +225,11 @@ GAFFERSCENE_API IECore::ConstCompoundDat
 /// Methods to query the tree of upstream computations involved in computing
 /// a property of the scene.
 
-struct History : public IECore::RefCounted
+// Note : the History classes are exported so that there is a single copy of
+// their RTTI. The `dynamic_cast`s to the derived classes in GafferSceneUI and
+// the Python bindings fail otherwise on platforms that compare `type_info` by
+// address, such as FreeBSD.
+struct GAFFERSCENE_API History : public IECore::RefCounted
 {
 	IE_CORE_DECLAREMEMBERPTR( History )
 	using Predecessors = std::vector<Ptr>;
@@ -244,7 +248,7 @@ GAFFERSCENE_API History::Ptr history( co
 /// Extends History to provide information on the history of a specific attribute.
 /// Attributes may be renamed by ShuffleAttributes nodes and this is reflected
 /// in the `attributeName` field.
-struct AttributeHistory : public History
+struct GAFFERSCENE_API AttributeHistory : public History
 {
 	IE_CORE_DECLAREMEMBERPTR( AttributeHistory )
 	AttributeHistory(
@@ -267,7 +271,7 @@ GAFFERSCENE_API AttributeHistory::Ptr at
 GAFFERSCENE_API AttributeHistory::Ptr attributeHistory( const History *attributesHistory, const IECore::InternedString &attribute );
 
 /// Extends History to provide information on the history of a specific option.
-struct OptionHistory : public History
+struct GAFFERSCENE_API OptionHistory : public History
 {
 	IE_CORE_DECLAREMEMBERPTR( OptionHistory )
 	OptionHistory(
@@ -286,7 +290,7 @@ GAFFERSCENE_API OptionHistory::Ptr optio
 /// Extends History to provide information on the history of a specific primitive variable.
 /// Primitive variables may be renamed by ShufflePrimitiveVariables nodes and this is reflected
 /// in the `primitiveVariableName` field.
-struct PrimitiveVariableHistory : public History
+struct GAFFERSCENE_API PrimitiveVariableHistory : public History
 {
 	IE_CORE_DECLAREMEMBERPTR( PrimitiveVariableHistory )
 	PrimitiveVariableHistory(

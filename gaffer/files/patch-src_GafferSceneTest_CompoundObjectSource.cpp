--- src/GafferSceneTest/CompoundObjectSource.cpp.orig	2026-09-25 06:15:48 UTC
+++ src/GafferSceneTest/CompoundObjectSource.cpp
@@ -80,7 +80,7 @@ void CompoundObjectSource::affects( cons
 void CompoundObjectSource::hashBound( const ScenePath &path, const Gaffer::Context *context, const GafferScene::ScenePlug *parent, IECore::MurmurHash &h ) const
 {
 	SceneNode::hashBound( path, context, parent, h );
-	h.append( &path.front(), path.size() );
+	h.append( path.data(), path.size() );
 	inPlug()->hash( h );
 }
 
@@ -92,7 +92,7 @@ Imath::Box3f CompoundObjectSource::compu
 void CompoundObjectSource::hashTransform( const ScenePath &path, const Gaffer::Context *context, const GafferScene::ScenePlug *parent, IECore::MurmurHash &h ) const
 {
 	SceneNode::hashTransform( path, context, parent, h );
-	h.append( &path.front(), path.size() );
+	h.append( path.data(), path.size() );
 	inPlug()->hash( h );
 }
 
@@ -109,7 +109,7 @@ Imath::M44f CompoundObjectSource::comput
 void CompoundObjectSource::hashAttributes( const ScenePath &path, const Gaffer::Context *context, const GafferScene::ScenePlug *parent, IECore::MurmurHash &h ) const
 {
 	SceneNode::hashAttributes( path, context, parent, h );
-	h.append( &path.front(), path.size() );
+	h.append( path.data(), path.size() );
 	inPlug()->hash( h );
 }
 
@@ -129,7 +129,7 @@ IECore::ConstCompoundObjectPtr CompoundO
 void CompoundObjectSource::hashObject( const ScenePath &path, const Gaffer::Context *context, const GafferScene::ScenePlug *parent, IECore::MurmurHash &h ) const
 {
 	SceneNode::hashObject( path, context, parent, h );
-	h.append( &path.front(), path.size() );
+	h.append( path.data(), path.size() );
 	inPlug()->hash( h );
 }
 
@@ -149,7 +149,7 @@ IECore::ConstObjectPtr CompoundObjectSou
 void CompoundObjectSource::hashChildNames( const ScenePath &path, const Gaffer::Context *context, const GafferScene::ScenePlug *parent, IECore::MurmurHash &h ) const
 {
 	SceneNode::hashChildNames( path, context, parent, h );
-	h.append( &path.front(), path.size() );
+	h.append( path.data(), path.size() );
 	inPlug()->hash( h );
 }
 

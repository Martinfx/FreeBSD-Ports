--- src/GafferScene/Cryptomatte.cpp.orig	2026-09-25 06:15:48 UTC
+++ src/GafferScene/Cryptomatte.cpp
@@ -591,7 +591,8 @@ void Cryptomatte::hash( const Gaffer::Va
 	else if( output == manifestScenePlug()->childNamesPlug() )
 	{
 		const GafferScene::ScenePlug::ScenePath &scenePath = context->get<GafferScene::ScenePlug::ScenePath>( GafferScene::ScenePlug::scenePathContextName );
-		h.append( &scenePath.front(), scenePath.size() );
+		// `data()` rather than `&front()`, because the root path is empty.
+		h.append( scenePath.data(), scenePath.size() );
 		ScenePlug::GlobalScope globalScope( context );
 		manifestPathDataPlug()->hash(h);
 	}

--- src/GafferScene/Instancer.cpp.orig	2026-09-25 06:42:21 UTC
+++ src/GafferScene/Instancer.cpp
@@ -793,7 +793,8 @@ class Instancer::EngineData : public Dat
 				// Note that we are rehashing the root path for every point, even though they are heavily
 				// reused.  This seems suboptimal, but is simpler, and the more complex version doesn't
 				// appear to make any performance difference in practice
-				totalHash.append( &(rootPath.path->readable())[0], rootPath.path->readable().size() );
+				// `data()` rather than `&[0]`, because the root path may be empty.
+				totalHash.append( rootPath.path->readable().data(), rootPath.path->readable().size() );
 				totalHash.append( rootPath.relative );
 				for( unsigned int j = 0; j < m_prototypeContextVariables.size(); j++ )
 				{

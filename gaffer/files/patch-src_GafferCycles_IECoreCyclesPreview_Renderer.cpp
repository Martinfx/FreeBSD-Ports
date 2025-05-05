--- src/GafferCycles/IECoreCyclesPreview/Renderer.cpp.orig	2025-03-04 18:05:25 UTC
+++ src/GafferCycles/IECoreCyclesPreview/Renderer.cpp
@@ -1538,7 +1538,7 @@ class InstanceCache : public IECore::RefCounted
 
 			for( Objects::iterator it = m_objects.begin(), eIt = m_objects.end(); it != eIt; ++it )
 			{
-				if( it->unique() )
+				if( it->use_count() == 1 )
 				{
 					// Only one reference - this is ours, so
 					// nothing outside of the cache is using the
@@ -1555,7 +1555,7 @@ class InstanceCache : public IECore::RefCounted
 
 			for( UniqueGeometry::iterator it = m_uniqueGeometry.begin(), eIt = m_uniqueGeometry.end(); it != eIt; ++it )
 			{
-				if( it->unique() )
+				if( it->use_count() == 1 )
 				{
 					// Only one reference - this is ours, so
 					// nothing outside of the cache is using the
@@ -1757,7 +1757,7 @@ class LightCache : public IECore::RefCounted
 
 			for( Lights::iterator it = m_lights.begin(), eIt = m_lights.end(); it != eIt; ++it )
 			{
-				if( it->unique() )
+				if( it->use_count() == 1 )
 				{
 					// Only one reference - this is ours, so
 					// nothing outside of the cache is using the

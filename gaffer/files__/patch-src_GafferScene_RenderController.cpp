--- src/GafferScene/RenderController.cpp.orig	2026-01-06 23:37:17 UTC
+++ src/GafferScene/RenderController.cpp
@@ -55,7 +55,7 @@
 #include "boost/multi_index/ordered_index.hpp"
 #include "boost/multi_index_container.hpp"
 
-#include "tbb/task.h"
+#include <oneapi/tbb/task_group.h>
 
 #include "fmt/format.h"
 
@@ -1131,151 +1131,140 @@ class RenderController::SceneGraph
 };
 
 // TBB task used to perform multithreaded updates on our SceneGraph.
-class RenderController::SceneGraphUpdateTask : public tbb::task
+class RenderController::SceneGraphUpdateTask
 {
 
-	public :
+public :
 
-		SceneGraphUpdateTask(
-			RenderController *controller,
-			SceneGraph *sceneGraph,
-			SceneGraph::Type sceneGraphType,
-			unsigned changedGlobalComponents,
-			const ThreadState &threadState,
-			const ScenePlug::ScenePath &scenePath,
-			const ProgressCallback &callback,
-			const PathMatcher *pathsToUpdate
-		)
-			:	m_controller( controller ),
-				m_sceneGraph( sceneGraph ),
-				m_sceneGraphType( sceneGraphType ),
-				m_changedGlobalComponents( changedGlobalComponents ),
-				m_threadState( threadState ),
-				m_scenePath( scenePath ),
-				m_callback( callback ),
-				m_pathsToUpdate( pathsToUpdate )
-		{
-		}
+    SceneGraphUpdateTask(
+        RenderController *controller,
+        SceneGraph *sceneGraph,
+        SceneGraph::Type sceneGraphType,
+        unsigned changedGlobalComponents,
+        const ThreadState &threadState,
+        const ScenePlug::ScenePath &scenePath,
+        const ProgressCallback &callback,
+        const PathMatcher *pathsToUpdate
+        )
+        :	m_controller( controller ),
+        m_sceneGraph( sceneGraph ),
+        m_sceneGraphType( sceneGraphType ),
+        m_changedGlobalComponents( changedGlobalComponents ),
+        m_threadState( threadState ),
+        m_scenePath( scenePath ),
+        m_callback( callback ),
+        m_pathsToUpdate( pathsToUpdate )
+    {
+    }
 
-		task *execute() override
-		{
+    void ExecuteTask()
+    {
+        const unsigned pathsToUpdateMatch = m_pathsToUpdate ? m_pathsToUpdate->match( m_scenePath ) : (unsigned)PathMatcher::EveryMatch;
+        const unsigned sceneGraphMatch = this->sceneGraphMatch();
+        if( !( sceneGraphMatch & ( IECore::PathMatcher::ExactMatch | IECore::PathMatcher::DescendantMatch ) ) )
+        {
+            m_sceneGraph->clear();
+        }
 
-			const unsigned pathsToUpdateMatch = m_pathsToUpdate ? m_pathsToUpdate->match( m_scenePath ) : (unsigned)PathMatcher::EveryMatch;
-			if( !pathsToUpdateMatch )
-			{
-				return nullptr;
-			}
+        ScenePlug::PathScope pathScope( m_threadState, &m_scenePath );
 
-			// Figure out if this location belongs in the type
-			// of scene graph we're constructing. If it doesn't
-			// belong, and neither do any of its descendants,
-			// we can just early out.
+        const bool changesMade = m_sceneGraph->update(
+            m_scenePath,
+            m_changedGlobalComponents,
+            sceneGraphMatch & IECore::PathMatcher::ExactMatch ? m_sceneGraphType : SceneGraph::NoType,
+            m_controller
+            );
 
-			const unsigned sceneGraphMatch = this->sceneGraphMatch();
-			if( !( sceneGraphMatch & ( IECore::PathMatcher::ExactMatch | IECore::PathMatcher::DescendantMatch ) ) )
-			{
-				m_sceneGraph->clear();
-				return nullptr;
-			}
+        if( changesMade && m_callback )
+        {
+            m_callback( BackgroundTask::Running );
+        }
 
-			// Set up a context to compute the scene at the right
-			// location.
+        const auto &children = m_sceneGraph->children();
+        if( m_sceneGraph->expanded() && !children.empty() )
+        {
+            oneapi::tbb::task_group tg;
+            ScenePlug::ScenePath childPath = m_scenePath;
+            childPath.push_back( IECore::InternedString() );
 
-			ScenePlug::PathScope pathScope( m_threadState, &m_scenePath );
+      	for( const auto &child : children )
+    	{	
+        		childPath.back() = child->name();
+        		// Capture only what's needed, avoiding unique_ptr members
+        		tg.run([controller = m_controller,
+                childPtr = child.get(),
+                sceneGraphType = m_sceneGraphType,
+                changedComponents = m_changedGlobalComponents,
+                threadState = m_threadState,
+                path = childPath,
+                callback = m_callback,
+                pathsToUpdate = m_pathsToUpdate]() {
+            	SceneGraphUpdateTask task{controller, childPtr, sceneGraphType,
+                                     changedComponents, threadState, path,
+                                     callback, pathsToUpdate};
+        		});
+    		}
+    		tg.wait();
+        }
+        else
+        {
+            for( auto &child : children )
+            {
+                child->clear();
+            }
+        }
 
-			// Update the scene graph at this location.
+        if( pathsToUpdateMatch & ( PathMatcher::AncestorMatch | PathMatcher::ExactMatch ) )
+        {
+            m_sceneGraph->allChildrenUpdated();
+        }
+    }
 
-			const bool changesMade = m_sceneGraph->update(
-				m_scenePath,
-				m_changedGlobalComponents,
-				sceneGraphMatch & IECore::PathMatcher::ExactMatch ? m_sceneGraphType : SceneGraph::NoType,
-				m_controller
-			);
+private :
 
-			if( changesMade && m_callback )
-			{
-				m_callback( BackgroundTask::Running );
-			}
+    const ScenePlug *scene()
+    {
+        return m_controller->m_scene.get();
+    }
 
-			// Spawn subtasks to apply updates to each child.
+    /// \todo Fast path for when sets were not dirtied.
+    unsigned sceneGraphMatch() const
+    {
+        switch( m_sceneGraphType )
+        {
+        case SceneGraph::CameraType :
+            return m_controller->m_renderSets.camerasSet().match( m_scenePath );
+        case SceneGraph::LightType :
+            return m_controller->m_renderSets.lightsSet().match( m_scenePath );
+        case SceneGraph::LightFilterType :
+            return m_controller->m_renderSets.lightFiltersSet().match( m_scenePath );
+        case SceneGraph::ObjectType :
+        {
+            unsigned m = m_controller->m_renderSets.lightsSet().match( m_scenePath ) |
+                         m_controller->m_renderSets.camerasSet().match( m_scenePath );
+            if( m & IECore::PathMatcher::ExactMatch )
+            {
+                return IECore::PathMatcher::AncestorMatch | IECore::PathMatcher::DescendantMatch;
+            }
+            else
+            {
+                return IECore::PathMatcher::EveryMatch;
+            }
+        }
+        default :
+            return IECore::PathMatcher::NoMatch;
+        }
+    }
 
-			const auto &children = m_sceneGraph->children();
-			if( m_sceneGraph->expanded() && children.size() )
-			{
-				set_ref_count( 1 + children.size() );
+    RenderController *m_controller;
+    SceneGraph *m_sceneGraph;
+    SceneGraph::Type m_sceneGraphType;
+    unsigned m_changedGlobalComponents;
+    const ThreadState &m_threadState;
+    ScenePlug::ScenePath m_scenePath;
+    const ProgressCallback &m_callback;
+    const PathMatcher *m_pathsToUpdate;
 
-				ScenePlug::ScenePath childPath = m_scenePath;
-				childPath.push_back( IECore::InternedString() ); // space for the child name
-				for( const auto &child : children )
-				{
-					childPath.back() = child->name();
-					SceneGraphUpdateTask *t = new( allocate_child() ) SceneGraphUpdateTask( m_controller, child.get(), m_sceneGraphType, m_changedGlobalComponents, m_threadState, childPath, m_callback, m_pathsToUpdate );
-					spawn( *t );
-				}
-
-				wait_for_all();
-			}
-			else
-			{
-				for( auto &child : children )
-				{
-					child->clear();
-				}
-			}
-
-			if( pathsToUpdateMatch & ( PathMatcher::AncestorMatch | PathMatcher::ExactMatch ) )
-			{
-				m_sceneGraph->allChildrenUpdated();
-			}
-
-			return nullptr;
-		}
-
-	private :
-
-		const ScenePlug *scene()
-		{
-			return m_controller->m_scene.get();
-		}
-
-		/// \todo Fast path for when sets were not dirtied.
-		unsigned sceneGraphMatch() const
-		{
-			switch( m_sceneGraphType )
-			{
-				case SceneGraph::CameraType :
-					return m_controller->m_renderSets.camerasSet().match( m_scenePath );
-				case SceneGraph::LightType :
-					return m_controller->m_renderSets.lightsSet().match( m_scenePath );
-				case SceneGraph::LightFilterType :
-					return m_controller->m_renderSets.lightFiltersSet().match( m_scenePath );
-				case SceneGraph::ObjectType :
-				{
-					unsigned m = m_controller->m_renderSets.lightsSet().match( m_scenePath ) |
-					             m_controller->m_renderSets.camerasSet().match( m_scenePath );
-					if( m & IECore::PathMatcher::ExactMatch )
-					{
-						return IECore::PathMatcher::AncestorMatch | IECore::PathMatcher::DescendantMatch;
-					}
-					else
-					{
-						return IECore::PathMatcher::EveryMatch;
-					}
-				}
-				default :
-					return IECore::PathMatcher::NoMatch;
-			}
-		}
-
-		RenderController *m_controller;
-		SceneGraph *m_sceneGraph;
-		SceneGraph::Type m_sceneGraphType;
-		unsigned m_changedGlobalComponents;
-		const ThreadState &m_threadState;
-		ScenePlug::ScenePath m_scenePath;
-		const ProgressCallback &m_callback;
-		const PathMatcher *m_pathsToUpdate;
-
 };
 
 //////////////////////////////////////////////////////////////////////////
@@ -1728,9 +1717,10 @@ void RenderController::updateInternal( const ProgressC
 				// the globals have changed, so we clear the scene graph and start again.
 				/// \todo Can we do better here, by using m_changedGlobalComponents in `SceneGraph::update()`?
 				sceneGraph->clear();
-			}
-
-			tbb::task_group_context taskGroupContext( tbb::task_group_context::isolated );
+			}	
+			
+			// TODO
+			/*tbb::task_group_context taskGroupContext( tbb::task_group_context::isolated );
 			SceneGraphUpdateTask *task = new( tbb::task::allocate_root( taskGroupContext ) ) SceneGraphUpdateTask(
 				this, sceneGraph, (SceneGraph::Type)i, m_changedGlobalComponents, ThreadState::current(), ScenePlug::ScenePath(), callback, pathsToUpdate
 			);
@@ -1739,7 +1729,7 @@ void RenderController::updateInternal( const ProgressC
 			if( i == SceneGraph::LightFilterType && m_lightLinks && m_lightLinks->lightFilterLinksDirty() )
 			{
 				m_lightLinks->outputLightFilterLinks( m_scene.get() );
-			}
+			}*/
 		}
 
 		if( m_changedGlobalComponents & CameraOptionsGlobalComponent )

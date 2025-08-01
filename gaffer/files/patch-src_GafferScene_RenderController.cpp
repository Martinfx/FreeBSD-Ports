--- src/GafferScene/RenderController.cpp.orig	2025-03-02 23:02:07 UTC
+++ src/GafferScene/RenderController.cpp
@@ -1187,152 +1187,135 @@ class RenderController::SceneGraph
 
 };
 
-// TBB task used to perform multithreaded updates on our SceneGraph.
-class RenderController::SceneGraphUpdateTask : public tbb::task
+// OneAPI task used to perform multithreaded updates on our SceneGraph.
+class RenderController::SceneGraphUpdateTask
 {
 
-	public :
+public:
 
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
+    )
+        : m_controller(controller),
+          m_sceneGraph(sceneGraph),
+          m_sceneGraphType(sceneGraphType),
+          m_changedGlobalComponents(changedGlobalComponents),
+          m_threadState(threadState),
+          m_scenePath(scenePath),
+          m_callback(callback),
+          m_pathsToUpdate(pathsToUpdate)
+    {
+    }
 
-		task *execute() override
-		{
+    void execute()
+    {
+        const unsigned pathsToUpdateMatch = m_pathsToUpdate ? m_pathsToUpdate->match(m_scenePath) : (unsigned)PathMatcher::EveryMatch;
+        if (!pathsToUpdateMatch)
+        {
+            return;
+        }
 
-			const unsigned pathsToUpdateMatch = m_pathsToUpdate ? m_pathsToUpdate->match( m_scenePath ) : (unsigned)PathMatcher::EveryMatch;
-			if( !pathsToUpdateMatch )
-			{
-				return nullptr;
-			}
+        const unsigned sceneGraphMatch = this->sceneGraphMatch();
+        if (!(sceneGraphMatch & (IECore::PathMatcher::ExactMatch | IECore::PathMatcher::DescendantMatch)))
+        {
+            m_sceneGraph->clear();
+            return;
+        }
 
-			// Figure out if this location belongs in the type
-			// of scene graph we're constructing. If it doesn't
-			// belong, and neither do any of its descendants,
-			// we can just early out.
+        ScenePlug::PathScope pathScope(m_threadState, &m_scenePath);
 
-			const unsigned sceneGraphMatch = this->sceneGraphMatch();
-			if( !( sceneGraphMatch & ( IECore::PathMatcher::ExactMatch | IECore::PathMatcher::DescendantMatch ) ) )
-			{
-				m_sceneGraph->clear();
-				return nullptr;
-			}
+        const bool changesMade = m_sceneGraph->update(
+            m_scenePath,
+            m_changedGlobalComponents,
+            sceneGraphMatch & IECore::PathMatcher::ExactMatch ? m_sceneGraphType : SceneGraph::NoType,
+            m_controller
+        );
 
-			// Set up a context to compute the scene at the right
-			// location.
+        if (changesMade && m_callback)
+        {
+            m_callback(BackgroundTask::Running);
+        }
 
-			ScenePlug::PathScope pathScope( m_threadState, &m_scenePath );
+        const auto &children = m_sceneGraph->children();
+        if (m_sceneGraph->expanded() && children.size())
+        {
+            tbb::parallel_for(tbb::blocked_range<size_t>(0, children.size()),
+                              [&](const tbb::blocked_range<size_t> &range)
+                              {
+                                  ScenePlug::ScenePath childPath = m_scenePath;
+                                  childPath.push_back(IECore::InternedString());
+                                  for (size_t i = range.begin(); i < range.end(); ++i)
+                                  {
+                                      childPath.back() = children[i]->name();
+                                      SceneGraphUpdateTask task(m_controller, children[i].get(), m_sceneGraphType, m_changedGlobalComponents, m_threadState, childPath, m_callback, m_pathsToUpdate);
+                                      task.execute();
+                                  }
+                              });
+        }
+        else
+        {
+            for (auto &child : children)
+            {
+                child->clear();
+            }
+        }
 
-			// Update the scene graph at this location.
+        if (pathsToUpdateMatch & (PathMatcher::AncestorMatch | PathMatcher::ExactMatch))
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
+private:
 
-			if( changesMade && m_callback )
-			{
-				m_callback( BackgroundTask::Running );
-			}
+    const ScenePlug *scene()
+    {
+        return m_controller->m_scene.get();
+    }
 
-			// Spawn subtasks to apply updates to each child.
+    unsigned sceneGraphMatch() const
+    {
+        switch (m_sceneGraphType)
+        {
+        case SceneGraph::CameraType:
+            return m_controller->m_renderSets.camerasSet().match(m_scenePath);
+        case SceneGraph::LightType:
+            return m_controller->m_renderSets.lightsSet().match(m_scenePath);
+        case SceneGraph::LightFilterType:
+            return m_controller->m_renderSets.lightFiltersSet().match(m_scenePath);
+        case SceneGraph::ObjectType:
+        {
+            unsigned m = m_controller->m_renderSets.lightsSet().match(m_scenePath) |
+                         m_controller->m_renderSets.camerasSet().match(m_scenePath);
+            if (m & IECore::PathMatcher::ExactMatch)
+            {
+                return IECore::PathMatcher::AncestorMatch | IECore::PathMatcher::DescendantMatch;
+            }
+            else
+            {
+                return IECore::PathMatcher::EveryMatch;
+            }
+        }
+        default:
+            return IECore::PathMatcher::NoMatch;
+        }
+    }
 
-			const auto &children = m_sceneGraph->children();
-			if( m_sceneGraph->expanded() && children.size() )
-			{
-				set_ref_count( 1 + children.size() );
-
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
+    RenderController *m_controller;
+    SceneGraph *m_sceneGraph;
+    SceneGraph::Type m_sceneGraphType;
+    unsigned m_changedGlobalComponents;
+    const ThreadState &m_threadState;
+    ScenePlug::ScenePath m_scenePath;
+    const ProgressCallback &m_callback;
+    const PathMatcher *m_pathsToUpdate;
 };
 
 //////////////////////////////////////////////////////////////////////////
@@ -1618,152 +1601,142 @@ void RenderController::updateInternal( const ProgressC
 
 void RenderController::updateInternal( const ProgressCallback &callback, const IECore::PathMatcher *pathsToUpdate, bool signalCompletion )
 {
-	try
-	{
-		// Update globals
-		if( m_dirtyGlobalComponents & GlobalsGlobalComponent )
-		{
-			RenderOptions renderOptions( m_scene.get() );
-			Private::RendererAlgo::outputOptions( renderOptions.globals.get(), m_renderOptions.globals.get(), m_renderer.get() );
-			Private::RendererAlgo::outputOutputs( m_scene.get(), renderOptions.globals.get(), m_renderOptions.globals.get(), m_renderer.get() );
-			if( *renderOptions.globals != *m_renderOptions.globals )
-			{
-				m_changedGlobalComponents |= GlobalsGlobalComponent;
-			}
-			if( cameraGlobalsChanged( renderOptions.globals.get(), m_renderOptions.globals.get(), m_scene.get() ) )
-			{
-				m_changedGlobalComponents |= CameraOptionsGlobalComponent;
-			}
-			if( *renderOptions.includedPurposes != *m_renderOptions.includedPurposes )
-			{
-				m_changedGlobalComponents |= IncludedPurposesGlobalComponent;
-			}
-			if( renderOptions.shutter != m_renderOptions.shutter || renderOptions.transformBlur != m_renderOptions.transformBlur )
-			{
-				m_changedGlobalComponents |= TransformBlurGlobalComponent;
-			}
-			if( renderOptions.shutter != m_renderOptions.shutter || renderOptions.deformationBlur != m_renderOptions.deformationBlur )
-			{
-				m_changedGlobalComponents |= DeformationBlurGlobalComponent;
-			}
-			if( renderOptions.shutter != m_renderOptions.shutter )
-			{
-				m_changedGlobalComponents |= CameraOptionsGlobalComponent;
-			}
-			m_renderOptions = renderOptions;
-		}
+    try
+    {
+        // Update globals
+        if( m_dirtyGlobalComponents & GlobalsGlobalComponent )
+        {
+            RenderOptions renderOptions( m_scene.get() );
+            Private::RendererAlgo::outputOptions( renderOptions.globals.get(), m_renderOptions.globals.get(), m_renderer.get() );
+            Private::RendererAlgo::outputOutputs( m_scene.get(), renderOptions.globals.get(), m_renderOptions.globals.get(), m_renderer.get() );
+            if( *renderOptions.globals != *m_renderOptions.globals )
+            {
+                m_changedGlobalComponents |= GlobalsGlobalComponent;
+            }
+            if( cameraGlobalsChanged( renderOptions.globals.get(), m_renderOptions.globals.get(), m_scene.get() ) )
+            {
+                m_changedGlobalComponents |= CameraOptionsGlobalComponent;
+            }
+            if( *renderOptions.includedPurposes != *m_renderOptions.includedPurposes )
+            {
+                m_changedGlobalComponents |= IncludedPurposesGlobalComponent;
+            }
+            if( renderOptions.shutter != m_renderOptions.shutter || renderOptions.transformBlur != m_renderOptions.transformBlur )
+            {
+                m_changedGlobalComponents |= TransformBlurGlobalComponent;
+            }
+            if( renderOptions.shutter != m_renderOptions.shutter || renderOptions.deformationBlur != m_renderOptions.deformationBlur )
+            {
+                m_changedGlobalComponents |= DeformationBlurGlobalComponent;
+            }
+            if( renderOptions.shutter != m_renderOptions.shutter )
+            {
+                m_changedGlobalComponents |= CameraOptionsGlobalComponent;
+            }
+            m_renderOptions = renderOptions;
+        }
 
-		if( ( m_dirtyGlobalComponents & CameraShutterGlobalComponent ) && !( m_dirtyGlobalComponents & GlobalsGlobalComponent ) )
-		{
-			// Shutter override from a camera may have changed, and won't have been covered by
-			// the block above (because the globals weren't dirty).
-			const V2f shutter = SceneAlgo::shutter( m_renderOptions.globals.get(), m_scene.get() );
-			if( shutter != m_renderOptions.shutter )
-			{
-				m_renderOptions.shutter = shutter;
-				m_changedGlobalComponents |= ( DeformationBlurGlobalComponent | TransformBlurGlobalComponent );
-			}
-		}
+        if( ( m_dirtyGlobalComponents & CameraShutterGlobalComponent ) && !( m_dirtyGlobalComponents & GlobalsGlobalComponent ) )
+        {
+            const V2f shutter = SceneAlgo::shutter( m_renderOptions.globals.get(), m_scene.get() );
+            if( shutter != m_renderOptions.shutter )
+            {
+                m_renderOptions.shutter = shutter;
+                m_changedGlobalComponents |= ( DeformationBlurGlobalComponent | TransformBlurGlobalComponent );
+            }
+        }
 
-		if( m_dirtyGlobalComponents & SetsGlobalComponent )
-		{
-			if( m_renderSets.update( m_scene.get() ) & Private::RendererAlgo::RenderSets::AttributesChanged )
-			{
-				m_changedGlobalComponents |= RenderSetsGlobalComponent;
-			}
-			// Light linking expressions might refer to any set, so we
-			// must assume that linking needs to be recalculated.
-			if( m_lightLinks )
-			{
-				m_lightLinks->setsDirtied();
-			}
-		}
+        if( m_dirtyGlobalComponents & SetsGlobalComponent )
+        {
+            if( m_renderSets.update( m_scene.get() ) & Private::RendererAlgo::RenderSets::AttributesChanged )
+            {
+                m_changedGlobalComponents |= RenderSetsGlobalComponent;
+            }
+            if( m_lightLinks )
+            {
+                m_lightLinks->setsDirtied();
+            }
+        }
 
-		m_dirtyGlobalComponents = NoGlobalComponent;
+        m_dirtyGlobalComponents = NoGlobalComponent;
 
-		// Update scene graphs
+        if( !m_defaultAttributes )
+        {
+            IECore::CompoundObjectPtr defaultAttributes = new CompoundObject();
+            m_defaultAttributes = m_renderer->attributes( defaultAttributes.get() );
+        }
 
-		if( !m_defaultAttributes )
-		{
-			IECore::CompoundObjectPtr defaultAttributes = new CompoundObject();
-			m_defaultAttributes = m_renderer->attributes( defaultAttributes.get() );
-		}
+        tbb::parallel_for(tbb::blocked_range<int>(SceneGraph::FirstType, SceneGraph::LastType + 1),
+                          [&](const tbb::blocked_range<int> &range)
+                          {
+                              for (int i = range.begin(); i < range.end(); ++i)
+                              {
+                                  SceneGraph *sceneGraph = m_sceneGraphs[i].get();
+                                  if( i == SceneGraph::CameraType && ( m_changedGlobalComponents & CameraOptionsGlobalComponent ) )
+                                  {
+                                      sceneGraph->clear();
+                                  }
 
-		for( int i = SceneGraph::FirstType; i <= SceneGraph::LastType; ++i )
-		{
-			SceneGraph *sceneGraph = m_sceneGraphs[i].get();
-			if( i == SceneGraph::CameraType && ( m_changedGlobalComponents & CameraOptionsGlobalComponent ) )
-			{
-				// Because the globals are applied to camera objects, we must update the object whenever
-				// the globals have changed, so we clear the scene graph and start again.
-				/// \todo Can we do better here, by using m_changedGlobalComponents in `SceneGraph::update()`?
-				sceneGraph->clear();
-			}
+                                  SceneGraphUpdateTask task(
+                                      this, sceneGraph, (SceneGraph::Type)i, m_changedGlobalComponents, ThreadState::current(), ScenePlug::ScenePath(), callback, pathsToUpdate
+                                  );
+                                  task.execute();
 
-			tbb::task_group_context taskGroupContext( tbb::task_group_context::isolated );
-			SceneGraphUpdateTask *task = new( tbb::task::allocate_root( taskGroupContext ) ) SceneGraphUpdateTask(
-				this, sceneGraph, (SceneGraph::Type)i, m_changedGlobalComponents, ThreadState::current(), ScenePlug::ScenePath(), callback, pathsToUpdate
-			);
-			tbb::task::spawn_root_and_wait( *task );
+                                  if( i == SceneGraph::LightFilterType && m_lightLinks && m_lightLinks->lightFilterLinksDirty() )
+                                  {
+                                      m_lightLinks->outputLightFilterLinks( m_scene.get() );
+                                  }
+                              }
+                          });
 
-			if( i == SceneGraph::LightFilterType && m_lightLinks && m_lightLinks->lightFilterLinksDirty() )
-			{
-				m_lightLinks->outputLightFilterLinks( m_scene.get() );
-			}
-		}
+        if( m_changedGlobalComponents & CameraOptionsGlobalComponent )
+        {
+            updateDefaultCamera();
+        }
 
-		if( m_changedGlobalComponents & CameraOptionsGlobalComponent )
-		{
-			updateDefaultCamera();
-		}
-
-		if( !pathsToUpdate )
-		{
-			// Only clear `m_changedGlobalComponents` when we
-			// know our entire scene has been updated successfully.
-			m_changedGlobalComponents = NoGlobalComponent;
-			m_updateRequired = false;
-			if( m_failedAttributeEdits )
-			{
-				IECore::msg(
-					IECore::Msg::Warning, "RenderController",
+        if( !pathsToUpdate )
+        {
+            m_changedGlobalComponents = NoGlobalComponent;
+            m_updateRequired = false;
+            if( m_failedAttributeEdits )
+            {
+                IECore::msg(
+                    IECore::Msg::Warning, "RenderController",
 					fmt::format(
-						"{} attribute edit{} required geometry to be regenerated",
-						m_failedAttributeEdits, m_failedAttributeEdits > 1 ? "s" : ""
-					)
-				);
-				m_failedAttributeEdits = 0;
-			}
-			if( m_lightLinks )
-			{
-				m_lightLinks->clean();
-			}
-		}
+    					"{} attribute edit{} required geometry to be regenerated",
+    					m_failedAttributeEdits.load(), m_failedAttributeEdits.load() > 1 ? "s" : "")
 
-		if( callback && signalCompletion )
-		{
-			callback( BackgroundTask::Completed );
-		}
-	}
-	catch( const IECore::Cancelled & )
-	{
-		if( callback )
-		{
-			callback( BackgroundTask::Cancelled );
-		}
-		throw;
-	}
-	catch( ... )
-	{
-		// No point updating again, since it'll just repeat
-		// the same error.
-		m_updateRequired = false;
-		if( callback )
-		{
-			callback( BackgroundTask::Errored );
-		}
-		throw;
-	}
+                );
+                m_failedAttributeEdits = 0;
+            }
+            if( m_lightLinks )
+            {
+                m_lightLinks->clean();
+            }
+        }
+
+        if( callback && signalCompletion )
+        {
+            callback( BackgroundTask::Completed );
+        }
+    }
+    catch( const IECore::Cancelled & )
+    {
+        if( callback )
+        {
+            callback( BackgroundTask::Cancelled );
+        }
+        throw;
+    }
+    catch( ... )
+    {
+        m_updateRequired = false;
+        if( callback )
+        {
+            callback( BackgroundTask::Errored );
+        }
+        throw;
+    }
 }
 
 void RenderController::updateDefaultCamera()

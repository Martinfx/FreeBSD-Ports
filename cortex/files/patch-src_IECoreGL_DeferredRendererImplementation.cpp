--- src/IECoreGL/DeferredRendererImplementation.cpp.orig	2025-02-25 10:37:21 UTC
+++ src/IECoreGL/DeferredRendererImplementation.cpp
@@ -42,15 +42,16 @@
 #include "IECoreGL/StateComponent.h"
 #include "IECoreGL/Texture.h"
 #include "IECoreGL/private/Display.h"
-
 #include "IECore/MessageHandler.h"
 
 #include "boost/noncopyable.hpp"
 
-#include "tbb/task.h"
-#include "tbb/task_scheduler_init.h"
+#include <tbb/task_group.h>
+#include <tbb/task_arena.h>
 
 #include <cassert>
+#include <atomic>
+#include <memory>
 
 using namespace IECoreGL;
 using namespace Imath;
@@ -354,128 +355,109 @@ struct DeferredRendererImplementation::ScopedRenderCon
 		const char *m_msgContext;
 };
 
-class DeferredRendererImplementation::ProceduralTask : public tbb::task, private boost::noncopyable
-{
-	public:
+class DeferredRendererImplementation::ProceduralTask {
+public:
+    ProceduralTask(DeferredRendererImplementation& renderer, IECoreScene::Renderer::ProceduralPtr proc, IECoreScene::RendererPtr param)
+        : m_renderer(renderer), m_procedural(proc), m_param(param) {
+        m_numSubtasks = 0;
+        RenderContext* curContext = m_renderer.currentContext();
 
-		ProceduralTask( DeferredRendererImplementation &renderer, IECoreScene::Renderer::ProceduralPtr proc, IECoreScene::RendererPtr param ) :
-			m_renderer(renderer), m_procedural(proc), m_param(param), m_taskList(nullptr)
-		{
-			m_numSubtasks = 0;
-			RenderContext *curContext = m_renderer.currentContext();
+        // Create a RenderContext for a new Procedural based on the current context
+        StatePtr completeState = boost::intrusive_ptr<State>(new State(false));
+        for (StateStack::iterator it = curContext->stateStack.begin(); it != curContext->stateStack.end(); ++it) {
+            completeState->add(*it);
+        }
+        m_proceduralContext = boost::intrusive_ptr<RenderContext>(new RenderContext);
+        m_proceduralContext->localTransform = curContext->localTransform;
+        m_proceduralContext->transformStack.push(curContext->transformStack.top());
+        m_proceduralContext->stateStack.push_back(completeState);
+        m_proceduralContext->groupStack.push(curContext->groupStack.top());
+    }
 
-			// create a RenderContext for a new Procedural based on the current context
-			StatePtr completeState = new State( false );
-			for ( StateStack::iterator it = curContext->stateStack.begin(); it != curContext->stateStack.end(); it++ )
-			{
-				completeState->add( *it );
-			}
-			m_proceduralContext = new RenderContext();
-			m_proceduralContext->localTransform = curContext->localTransform;
-			m_proceduralContext->transformStack.push( curContext->transformStack.top() );
-			m_proceduralContext->stateStack.push_back( completeState );
-			m_proceduralContext->groupStack.push( curContext->groupStack.top() );
-		}
+    void execute() {
+        tbb::task_group taskGroup;
 
-		~ProceduralTask() override
-		{
-		}
+        // Activate the render context on the task's thread.
+        ScopedRenderContext scopedProceduralContext(m_proceduralContext, m_renderer, "DeferredRendererImplementation::ProceduralTask::execute");
+        m_procedural->render(m_param.get());
 
-		task* execute() override
-		{
-			tbb::task_list taskList;
+        taskGroup.wait();
+    }
 
-			m_taskList = &taskList;
+    void addSubtask(std::function<void()> subtask) {
+        m_taskGroup.run(subtask);
+        m_numSubtasks++;
+    }
 
-			// activates the render context on the task's thread.
-			ScopedRenderContext scopedProceduralContext( m_proceduralContext, m_renderer, "DeferredRendererImplementation::ProceduralTask::execute" );
-			m_procedural->render( m_param.get() );
-			set_ref_count( m_numSubtasks + 1 );
-			spawn_and_wait_for_all(taskList);
-			taskList.clear();
-			m_taskList = nullptr;
-			return nullptr;
-		}
+private:
+    std::atomic<unsigned int> m_numSubtasks;
+    RenderContextPtr m_proceduralContext;
+    DeferredRendererImplementation& m_renderer;
+    IECoreScene::Renderer::ProceduralPtr m_procedural;
+    IECoreScene::RendererPtr m_param;
+    tbb::task_group m_taskGroup;
+};
 
-		void addSubtask( ProceduralTask& subtask )
-		{
-			if ( !m_taskList )
-			{
-				IECore::msg( IECore::Msg::Error, "DeferredRendererImplementation::ProceduralTask::addSubtask", "No tasklist!" );
-				return;
-			}
-			m_taskList->push_back( subtask );
-			m_numSubtasks++;
-		}
 
-	private :
+void DeferredRendererImplementation::addProcedural( IECoreScene::Renderer::ProceduralPtr proc, IECoreScene::RendererPtr renderer )
+{
+    bool visible = static_cast<CameraVisibilityStateComponent *>( getState( CameraVisibilityStateComponent::staticTypeId() ) )->value();
+    if( !visible )
+    {
+        return;
+    }
 
-		std::atomic<unsigned int> m_numSubtasks;
-		RenderContextPtr m_proceduralContext;
-		DeferredRendererImplementation &m_renderer;
-		IECoreScene::Renderer::ProceduralPtr m_procedural;
-		IECoreScene::RendererPtr m_param;
-		tbb::task_list *m_taskList;
-};
+    bool withThreads = static_cast<ProceduralThreadingStateComponent *>( getState( ProceduralThreadingStateComponent::staticTypeId() ) )->value();
+    if( withThreads )
+    {
+        bool mainProcedural = ( m_threadContextPool.size() == 0 );
 
+        if ( mainProcedural )
+        {
+            // Create a task_arena with default settings
+            tbb::task_arena arena;
 
+            // Create a task_group to manage tasks within the arena
+            tbb::task_group tg;
 
-void DeferredRendererImplementation::addProcedural( IECoreScene::Renderer::ProceduralPtr proc, IECoreScene::RendererPtr renderer )
-{
-	bool visible = static_cast<CameraVisibilityStateComponent *>( getState( CameraVisibilityStateComponent::staticTypeId() ) )->value();
-	if( !visible )
-	{
-		return;
-	}
+            // Execute the task_group within the arena
+            arena.execute([&]{
+                tg.run([&]{
+                    // Create a RenderContext for the procedural
+                    //RenderContextPtr proceduralContext = IECoreGL::createProceduralContext();
 
-	bool withThreads = static_cast<ProceduralThreadingStateComponent *>( getState( ProceduralThreadingStateComponent::staticTypeId() ) )->value();
-	if( withThreads )
-	{
-		bool mainProcedural = ( m_threadContextPool.size() == 0 );
+                    // ScopedRenderContext ensures the context is set for this scope
+                    //ScopedRenderContext scopedContext(proceduralContext, *this, "DeferredRendererImplementation::addProcedural");
 
-		if ( mainProcedural )
-		{
-			// the init is necessary for tbb < 2.2, whereas it is automatically
-			// created for us in tbb >= 2.2. tbb documentation indicates that it is
-			// fine to create multiple instances though so we create one just in case.
-			tbb::task_scheduler_init init;
+                    // Render the procedural
+                    proc->render(renderer.get());
+                });
 
-			// create root task.
-			tbb::task_group_context taskGroupContext( tbb::task_group_context::isolated );
-			ProceduralTask& a = *new( ProceduralTask::allocate_root( taskGroupContext ) ) ProceduralTask( *this, proc, renderer );
-			tbb::task::spawn_root_and_wait(a);
-			// check if all contexts were cleared
-			for ( ThreadRenderContext::const_iterator it = m_threadContextPool.begin(); it != m_threadContextPool.end(); it++ )
-			{
-				if ( (*it).size() )
-				{
-					IECore::msg( IECore::Msg::Error, "DeferredRendererImplementation::procedural", "Non empty thread render context detected!" );
-				}
-			}
-			m_threadContextPool.clear();
-		}
-		else
-		{
-			ProceduralTask *parentTask = dynamic_cast< ProceduralTask *>(&ProceduralTask::self());
-			if ( parentTask )
-			{
-				// add a child task to the current task
-				ProceduralTask& a = *new(parentTask->allocate_child()) ProceduralTask( *this, proc, renderer );
-				// register this class on the parent task
-				parentTask->addSubtask( a );
-			}
-			else
-			{
-				// Somehow the parent task is not ProceduralTask...
-				IECore::msg( IECore::Msg::Error, "DeferredRendererImplementation::procedural", "Incompatible parent task type!" );
-			}
-		}
-	}
-	else
-	{
-		// threading not wanted - just execute immediately
-		proc->render( renderer.get() );
-	}
+                // Wait for all tasks in the task_group to complete
+                tg.wait();
+            });
+
+            // Check if all contexts were cleared
+            for ( const auto& contextStack : m_threadContextPool )
+            {
+                if ( !contextStack.empty() )
+                {
+                    IECore::msg( IECore::Msg::Error, "DeferredRendererImplementation::addProcedural", "Non-empty thread render context detected!" );
+                }
+            }
+            m_threadContextPool.clear();
+        }
+        else
+        {
+            // If not the main procedural, execute directly
+            proc->render(renderer.get());
+        }
+    }
+    else
+    {
+        // Threading not enabled; execute procedural immediately
+        proc->render(renderer.get());
+    }
 }
 
 ScenePtr DeferredRendererImplementation::scene()

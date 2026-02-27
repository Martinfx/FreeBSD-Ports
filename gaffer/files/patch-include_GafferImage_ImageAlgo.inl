--- include/GafferImage/ImageAlgo.inl.orig	2025-03-02 22:03:41 UTC
+++ include/GafferImage/ImageAlgo.inl
@@ -43,8 +43,11 @@
 
 #include "boost/tuple/tuple.hpp"
 
-#include "tbb/pipeline.h"
-#include "tbb/task_scheduler_init.h"
+#include "oneapi/tbb/parallel_for.h"
+#include "oneapi/tbb/blocked_range.h"
+#include "oneapi/tbb/global_control.h"
+#include "oneapi/tbb/flow_graph.h"
+#include "oneapi/tbb/task_group.h"
 
 namespace GafferImage
 {
@@ -255,46 +258,37 @@ void parallelProcessTiles( const ImagePlug *imagePlug,
 template <class TileFunctor>
 void parallelProcessTiles( const ImagePlug *imagePlug, TileFunctor &&functor, const Imath::Box2i &window, TileOrder tileOrder )
 {
-	Imath::Box2i processWindow = window;
-	if( processWindow == Imath::Box2i() )
-	{
-		processWindow = imagePlug->dataWindowPlug()->getValue();
-	}
+    Imath::Box2i processWindow = window;
+    if( processWindow == Imath::Box2i() )
+    {
+        processWindow = imagePlug->dataWindowPlug()->getValue();
+    }
 
-	if( BufferAlgo::empty( processWindow ) )
-	{
-		return;
-	}
+    if( BufferAlgo::empty( processWindow ) )
+    {
+        return;
+    }
 
-	Detail::TileInputIterator tileIterator( processWindow, tileOrder );
-	const Gaffer::ThreadState &threadState = Gaffer::ThreadState::current();
+    Detail::TileInputIterator tileIterator( processWindow, tileOrder );
+    const Gaffer::ThreadState &threadState = Gaffer::ThreadState::current();
 
-	tbb::task_group_context taskGroupContext( tbb::task_group_context::isolated );
-	parallel_pipeline( tbb::task_scheduler_init::default_num_threads(),
+    std::vector<Imath::V2i> tileOrigins;
+    while (!tileIterator.done())
+    {
+        tileOrigins.push_back(*tileIterator);
+        ++tileIterator;
+    }
 
-		tbb::make_filter<void, Imath::V2i>(
-			tbb::filter::serial,
-			Detail::TileInputFilter<Detail::TileInputIterator>( tileIterator )
-		) &
-
-		tbb::make_filter<Imath::V2i, void>(
-
-			tbb::filter::parallel,
-
-			[ imagePlug, &functor, &threadState ] ( const Imath::V2i &tileOrigin ) {
-
-				ImagePlug::ChannelDataScope channelDataScope( threadState );
-				channelDataScope.setTileOrigin( &tileOrigin );
-				functor( imagePlug, tileOrigin );
-
-			}
-
-		),
-
-		// Prevents outer tasks silently cancelling our tasks
-		taskGroupContext
-
-	);
+    tbb::parallel_for(tbb::blocked_range<size_t>(0, tileOrigins.size()),
+                      [&](const tbb::blocked_range<size_t> &range) {
+                          for (size_t i = range.begin(); i < range.end(); ++i)
+                          {
+                              const Imath::V2i &tileOrigin = tileOrigins[i];
+                              ImagePlug::ChannelDataScope channelDataScope(threadState);
+                              channelDataScope.setTileOrigin(&tileOrigin);
+                              functor(imagePlug, tileOrigin);
+                          }
+                      });
 }
 
 template <class TileFunctor>
@@ -334,67 +328,42 @@ void parallelGatherTiles( const ImagePlug *imagePlug, 
 template <class TileFunctor, class GatherFunctor>
 void parallelGatherTiles( const ImagePlug *imagePlug, const TileFunctor &tileFunctor, GatherFunctor &&gatherFunctor, const Imath::Box2i &window, TileOrder tileOrder )
 {
-	Imath::Box2i processWindow = window;
-	if( processWindow == Imath::Box2i() )
-	{
-		processWindow = imagePlug->dataWindowPlug()->getValue();
-	}
+    Imath::Box2i processWindow = window;
+    if( processWindow == Imath::Box2i() )
+    {
+        processWindow = imagePlug->dataWindowPlug()->getValue();
+    }
 
-	if( BufferAlgo::empty( processWindow ) )
-	{
-		return;
-	}
+    if( BufferAlgo::empty( processWindow ) )
+    {
+        return;
+    }
 
-	using TileFunctorResult = std::invoke_result_t<TileFunctor, const ImagePlug *, const Imath::V2i &>;
-	using TileFilterResult = std::pair<Imath::V2i, TileFunctorResult>;
+    using TileFunctorResult = std::invoke_result_t<TileFunctor, const ImagePlug *, const Imath::V2i &>;
+    using TileFilterResult = std::pair<Imath::V2i, TileFunctorResult>;
 
-	Detail::TileInputIterator tileIterator( processWindow, tileOrder );
-	const Gaffer::ThreadState &threadState = Gaffer::ThreadState::current();
+    Detail::TileInputIterator tileIterator( processWindow, tileOrder );
+    const Gaffer::ThreadState &threadState = Gaffer::ThreadState::current();
 
-	tbb::task_group_context taskGroupContext( tbb::task_group_context::isolated );
-	parallel_pipeline( tbb::task_scheduler_init::default_num_threads(),
+    std::vector<TileFilterResult> tileResults;
+    while (!tileIterator.done())
+    {
+        tileResults.emplace_back(*tileIterator, tileFunctor(imagePlug, *tileIterator));
+        ++tileIterator;
+    }
 
-		tbb::make_filter<void, Imath::V2i>(
-			tbb::filter::serial,
-			Detail::TileInputFilter<Detail::TileInputIterator>( tileIterator )
-		) &
-
-		tbb::make_filter<Imath::V2i, TileFilterResult>(
-
-			tbb::filter::parallel,
-
-			[ imagePlug, &tileFunctor, &threadState ] ( const Imath::V2i &tileOrigin ) {
-
-				ImagePlug::ChannelDataScope channelDataScope( threadState );
-				channelDataScope.setTileOrigin( &tileOrigin );
-
-				return TileFilterResult(
-					tileOrigin, tileFunctor( imagePlug, tileOrigin )
-				);
-			}
-
-		) &
-
-		tbb::make_filter<TileFilterResult, void>(
-
-			tileOrder == Unordered ? tbb::filter::serial_out_of_order : tbb::filter::serial_in_order,
-
-			[ imagePlug, &gatherFunctor, &threadState ] ( const TileFilterResult &input ) {
-
-				ImagePlug::ChannelDataScope channelDataScope( threadState );
-				channelDataScope.setTileOrigin( &input.first );
-
-				gatherFunctor( imagePlug, input.first, input.second );
-
-			}
-
-		),
-
-		// Prevents outer tasks silently cancelling our tasks
-		taskGroupContext
-
-	);
+    tbb::parallel_for(tbb::blocked_range<size_t>(0, tileResults.size()),
+                      [&](const tbb::blocked_range<size_t> &range) {
+                          for (size_t i = range.begin(); i < range.end(); ++i)
+                          {
+                              const TileFilterResult &tileResult = tileResults[i];
+                              ImagePlug::ChannelDataScope channelDataScope(threadState);
+                              channelDataScope.setTileOrigin(&tileResult.first);
+                              gatherFunctor(imagePlug, tileResult.first, tileResult.second);
+                          }
+                      });
 }
+
 
 template <class TileFunctor, class GatherFunctor>
 void parallelGatherTiles( const ImagePlug *imagePlug, const std::vector<std::string> &channelNames, const TileFunctor &tileFunctor, GatherFunctor &&gatherFunctor, const Imath::Box2i &window, TileOrder tileOrder )

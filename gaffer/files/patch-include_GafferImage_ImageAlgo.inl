--- include/GafferImage/ImageAlgo.inl.orig	2025-03-02 22:03:41 UTC
+++ include/GafferImage/ImageAlgo.inl
@@ -43,8 +43,12 @@
 
 #include "boost/tuple/tuple.hpp"
 
-#include "tbb/pipeline.h"
-#include "tbb/task_scheduler_init.h"
+#include "oneapi/tbb/parallel_for.h"
+#include "oneapi/tbb/blocked_range.h"
+#include "oneapi/tbb/global_control.h"
+#include "oneapi/tbb/flow_graph.h"
+#include "oneapi/tbb/global_control.h"
+#include "oneapi/tbb/task_group.h"
 
 namespace GafferImage
 {
@@ -55,66 +59,34 @@ namespace Detail
 namespace Detail
 {
 
-class TileInputIterator : public boost::iterator_facade<TileInputIterator, const Imath::V2i, boost::forward_traversal_tag>
+class TileInputIterator
 {
+public:
+    TileInputIterator(const Imath::Box2i &window, const TileOrder tileOrder)
+        : m_range(ImagePlug::tileOrigin(window.min), ImagePlug::tileOrigin(window.max - Imath::V2i(1))),
+          m_tileOrder(tileOrder),
+          m_tileOrigin(m_range.min)
+    {
+    }
 
-	public :
+    bool done() const { return !m_range.intersects(m_tileOrigin); }
 
-		TileInputIterator(
-			const Imath::Box2i &window,
-			const TileOrder tileOrder
-		) :
-			m_range( ImagePlug::tileOrigin( window.min ), ImagePlug::tileOrigin( window.max - Imath::V2i( 1 ) ) ),
-			m_tileOrder( tileOrder )
-		{
-			switch( m_tileOrder )
-			{
-				case Unordered :
-				case TopToBottom :
-					m_tileOrigin = Imath::V2i( m_range.min.x, m_range.max.y );
-					break;
-				case BottomToTop :
-					m_tileOrigin = ImagePlug::tileOrigin( m_range.min );
-					break;
-			}
-		}
+    void operator++()
+    {
+        m_tileOrigin.x += ImagePlug::tileSize();
+        if (m_tileOrigin.x > m_range.max.x)
+        {
+            m_tileOrigin.x = m_range.min.x;
+            m_tileOrigin.y += (m_tileOrder == BottomToTop ? ImagePlug::tileSize() : -ImagePlug::tileSize());
+        }
+    }
 
-		bool done() const
-		{
-			return !m_range.intersects( m_tileOrigin );
-		}
+    const Imath::V2i &operator*() const { return m_tileOrigin; }
 
-	private :
-
-		friend class boost::iterator_core_access;
-
-		void increment()
-		{
-			m_tileOrigin.x += ImagePlug::tileSize();
-			if( m_tileOrigin.x > m_range.max.x )
-			{
-				m_tileOrigin.x = m_range.min.x;
-				switch( m_tileOrder )
-				{
-					case Unordered :
-					case TopToBottom :
-						m_tileOrigin.y -= ImagePlug::tileSize();
-						break;
-					case BottomToTop :
-						m_tileOrigin.y += ImagePlug::tileSize();
-				}
-			}
-		}
-
-		const Imath::V2i &dereference() const
-		{
-			return m_tileOrigin;
-		}
-
-		const Imath::Box2i m_range;
-		const ImageAlgo::TileOrder m_tileOrder;
-		Imath::V2i m_tileOrigin;
-
+private:
+    const Imath::Box2i m_range;
+    const TileOrder m_tileOrder;
+    Imath::V2i m_tileOrigin;
 };
 
 struct OriginAndName
@@ -253,48 +225,32 @@ template <class TileFunctor>
 }
 
 template <class TileFunctor>
-void parallelProcessTiles( const ImagePlug *imagePlug, TileFunctor &&functor, const Imath::Box2i &window, TileOrder tileOrder )
+void parallelProcessTiles(const ImagePlug *imagePlug, TileFunctor &&functor, const Imath::Box2i &window, TileOrder tileOrder)
 {
-	Imath::Box2i processWindow = window;
-	if( processWindow == Imath::Box2i() )
-	{
-		processWindow = imagePlug->dataWindowPlug()->getValue();
-	}
+    Imath::Box2i processWindow = window.isEmpty() ? imagePlug->dataWindowPlug()->getValue() : window;
+    if (BufferAlgo::empty(processWindow))
+    {
+        return;
+    }
 
-	if( BufferAlgo::empty( processWindow ) )
-	{
-		return;
-	}
+    Detail::TileInputIterator tileIterator(processWindow, tileOrder);
+    std::vector<Imath::V2i> tileOrigins;
 
-	Detail::TileInputIterator tileIterator( processWindow, tileOrder );
-	const Gaffer::ThreadState &threadState = Gaffer::ThreadState::current();
+    while (!tileIterator.done())
+    {
+        tileOrigins.push_back(*tileIterator);
+        ++tileIterator;
+    }
 
-	tbb::task_group_context taskGroupContext( tbb::task_group_context::isolated );
-	parallel_pipeline( tbb::task_scheduler_init::default_num_threads(),
-
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
+    tbb::parallel_for(
+        tbb::blocked_range<size_t>(0, tileOrigins.size()),
+        [&](const tbb::blocked_range<size_t> &range)
+        {
+            for (size_t i = range.begin(); i != range.end(); ++i)
+            {
+                functor(imagePlug, tileOrigins[i]);
+            }
+        });
 }
 
 template <class TileFunctor>
@@ -332,105 +288,36 @@ template <class TileFunctor, class GatherFunctor>
 }
 
 template <class TileFunctor, class GatherFunctor>
-void parallelGatherTiles( const ImagePlug *imagePlug, const TileFunctor &tileFunctor, GatherFunctor &&gatherFunctor, const Imath::Box2i &window, TileOrder tileOrder )
+void parallelGatherTiles(const ImagePlug *imagePlug, const TileFunctor &tileFunctor, GatherFunctor &&gatherFunctor, const Imath::Box2i &window, TileOrder tileOrder)
 {
-	Imath::Box2i processWindow = window;
-	if( processWindow == Imath::Box2i() )
-	{
-		processWindow = imagePlug->dataWindowPlug()->getValue();
-	}
+    Imath::Box2i processWindow = window.isEmpty() ? imagePlug->dataWindowPlug()->getValue() : window;
+    if (BufferAlgo::empty(processWindow))
+    {
+        return;
+    }
 
-	if( BufferAlgo::empty( processWindow ) )
-	{
-		return;
-	}
+    using TileFunctorResult = std::invoke_result_t<TileFunctor, const ImagePlug *, const Imath::V2i &>;
+    using TileFilterResult = std::pair<Imath::V2i, TileFunctorResult>;
 
-	using TileFunctorResult = std::invoke_result_t<TileFunctor, const ImagePlug *, const Imath::V2i &>;
-	using TileFilterResult = std::pair<Imath::V2i, TileFunctorResult>;
+    Detail::TileInputIterator tileIterator(processWindow, tileOrder);
+    std::vector<TileFilterResult> tileResults;
 
-	Detail::TileInputIterator tileIterator( processWindow, tileOrder );
-	const Gaffer::ThreadState &threadState = Gaffer::ThreadState::current();
+    while (!tileIterator.done())
+    {
+        Imath::V2i tileOrigin = *tileIterator;
+        ++tileIterator;
+        tileResults.emplace_back(tileOrigin, tileFunctor(imagePlug, tileOrigin));
+    }
 
-	tbb::task_group_context taskGroupContext( tbb::task_group_context::isolated );
-	parallel_pipeline( tbb::task_scheduler_init::default_num_threads(),
-
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
-}
-
-template <class TileFunctor, class GatherFunctor>
-void parallelGatherTiles( const ImagePlug *imagePlug, const std::vector<std::string> &channelNames, const TileFunctor &tileFunctor, GatherFunctor &&gatherFunctor, const Imath::Box2i &window, TileOrder tileOrder )
-{
-	using TileFunctorResult = std::invoke_result_t<TileFunctor, const ImagePlug *, const std::string &, const Imath::V2i &>;
-	using WholeTileResult = std::vector<TileFunctorResult>;
-
-	if( channelNames.size() == 0 )
-	{
-		return;
-	}
-
-	auto f = [&channelNames, &tileFunctor] ( const ImagePlug *imagePlug, const Imath::V2i &tileOrigin )
-	{
-		WholeTileResult result;
-		result.resize( channelNames.size() );
-
-		ImagePlug::ChannelDataScope channelDataScope( Gaffer::Context::current() );
-		for( unsigned int i = 0; i < channelNames.size(); i++ )
-		{
-			channelDataScope.setChannelName( &channelNames[i] );
-			result[i] = tileFunctor( imagePlug, channelNames[i], tileOrigin );
-		}
-
-		return result;
-	};
-
-	auto g = [&channelNames, &gatherFunctor] ( const ImagePlug *imagePlug, const Imath::V2i &tileOrigin, const WholeTileResult &tileData )
-	{
-		for( unsigned int i = 0; i < tileData.size(); i++ )
-		{
-			gatherFunctor( imagePlug, channelNames[i], tileOrigin, tileData[i] );
-		}
-	};
-
-	parallelGatherTiles( imagePlug, f, g, window, tileOrder );
+    tbb::parallel_for(
+        tbb::blocked_range<size_t>(0, tileResults.size()),
+        [&](const tbb::blocked_range<size_t> &range)
+        {
+            for (size_t i = range.begin(); i != range.end(); ++i)
+            {
+                gatherFunctor(imagePlug, tileResults[i].first, tileResults[i].second);
+            }
+        });
 }
 
 } // namespace ImageAlgo

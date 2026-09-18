--- src/IECoreImage/DisplayDriverServer.cpp.orig	2026-09-10 21:49:58 UTC
+++ src/IECoreImage/DisplayDriverServer.cpp
@@ -106,7 +106,7 @@
 {
 	public:
 
-		Session( boost::asio::io_service& io_service, MergeMap& mergeMap );
+		Session( boost::asio::io_context& io_service, MergeMap& mergeMap );
 		~Session() override;
 
 		boost::asio::ip::tcp::socket& socket();
@@ -135,7 +135,7 @@
 	public :
 
 		boost::asio::ip::tcp::endpoint m_endpoint;
-		boost::asio::io_service m_service;
+		boost::asio::io_context m_service;
 		boost::asio::ip::tcp::acceptor m_acceptor;
 		std::thread m_thread;
 		MergeMap m_mergeMap;
@@ -320,7 +320,7 @@
  * DisplayDriverServer::Session functions
  */
 
-DisplayDriverServer::Session::Session( boost::asio::io_service& io_service, MergeMap& mergeMap ) :
+DisplayDriverServer::Session::Session( boost::asio::io_context& io_service, MergeMap& mergeMap ) :
 	m_socket( io_service ), m_displayDriver(nullptr), m_buffer( new CharVectorData( ) ), m_mergeMap( mergeMap )
 {
 }
@@ -549,8 +549,8 @@
 		/// We used to send the data via MemoryIndexedIO which would take care of this
 		/// for us, but the overhead of this significantly affected interactive render
 		/// speeds.
-		const Imath::Box2i box = *reinterpret_cast<const Imath::Box2i *>( &m_buffer->readable()[0] );
-		const float *data = reinterpret_cast<const float *>( &m_buffer->readable()[0] + sizeof( box ) );
+		const Imath::Box2i box = *reinterpret_cast<const Imath::Box2i *>( m_buffer->readable().data() );
+		const float *data = reinterpret_cast<const float *>( m_buffer->readable().data() + sizeof( box ) );
 		const size_t dataSize = ( m_buffer->readable().size() - sizeof( box ) ) / sizeof( float );
 
 		// call imageData passing the data

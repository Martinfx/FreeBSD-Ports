--- src/IECoreImage/DisplayDriverServer.cpp.orig	2026-09-24 18:05:26 UTC
+++ src/IECoreImage/DisplayDriverServer.cpp
@@ -106,7 +106,7 @@ class DisplayDriverServer::Session : pub
 {
 	public:
 
-		Session( boost::asio::io_service& io_service, MergeMap& mergeMap );
+		Session( boost::asio::io_context& io_service, MergeMap& mergeMap );
 		~Session() override;
 
 		boost::asio::ip::tcp::socket& socket();
@@ -135,7 +135,7 @@ class DisplayDriverServer::PrivateData :
 	public :
 
 		boost::asio::ip::tcp::endpoint m_endpoint;
-		boost::asio::io_service m_service;
+		boost::asio::io_context m_service;
 		boost::asio::ip::tcp::acceptor m_acceptor;
 		std::thread m_thread;
 		MergeMap m_mergeMap;
@@ -320,7 +320,7 @@ void DisplayDriverServer::handleAccept(
  * DisplayDriverServer::Session functions
  */
 
-DisplayDriverServer::Session::Session( boost::asio::io_service& io_service, MergeMap& mergeMap ) :
+DisplayDriverServer::Session::Session( boost::asio::io_context& io_service, MergeMap& mergeMap ) :
 	m_socket( io_service ), m_displayDriver(nullptr), m_buffer( new CharVectorData( ) ), m_mergeMap( mergeMap )
 {
 }

--- src/IECoreImage/ClientDisplayDriver.cpp.orig	2025-02-25 10:37:21 UTC
+++ src/IECoreImage/ClientDisplayDriver.cpp
@@ -73,7 +73,7 @@ class ClientDisplayDriver::PrivateData : public RefCou
 			m_socket.close();
 		}
 
-		boost::asio::io_service m_service;
+		boost::asio::io_context m_service;
 		std::string m_host;
 		std::string m_port;
 		bool m_scanLineOrderOnly;
@@ -97,18 +97,18 @@ ClientDisplayDriver::ClientDisplayDriver( const Imath:
 	m_data->m_port = displayPortData->readable();
 
 	tcp::resolver resolver(m_data->m_service);
-	tcp::resolver::query query(m_data->m_host, m_data->m_port);
+	//tcp::resolver::query query(m_data->m_host, m_data->m_port);
 
 	boost::system::error_code error;
-	tcp::resolver::iterator iterator = resolver.resolve( query, error );
+	//tcp::resolver::iterator iterator = resolver.resolve( query, error );
+	auto endpoints = resolver.resolve(m_data->m_host, m_data->m_port, error);
 	if( !error )
 	{
 		error = boost::asio::error::host_not_found;
-		while( error && iterator != tcp::resolver::iterator() )
-		{
-			m_data->m_socket.close();
-			m_data->m_socket.connect( *iterator++, error );
-		}
+	//	while( error && iterator != tcp::resolver::iterator() )
+	//	{
+			boost::asio::connect(m_data->m_socket, endpoints, error);
+	//	}
 	}
 	if( error )
 	{

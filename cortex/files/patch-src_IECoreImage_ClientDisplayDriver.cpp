--- src/IECoreImage/ClientDisplayDriver.cpp.orig	2026-09-24 18:05:26 UTC
+++ src/IECoreImage/ClientDisplayDriver.cpp
@@ -72,7 +72,7 @@ class ClientDisplayDriver::PrivateData :
 			m_socket.close();
 		}
 
-		boost::asio::io_service m_service;
+		boost::asio::io_context m_service;
 		std::string m_host;
 		std::string m_port;
 		bool m_scanLineOrderOnly;
@@ -96,17 +96,16 @@ ClientDisplayDriver::ClientDisplayDriver
 	m_data->m_port = displayPortData->readable();
 
 	tcp::resolver resolver(m_data->m_service);
-	tcp::resolver::query query(m_data->m_host, m_data->m_port);
 
 	boost::system::error_code error;
-	tcp::resolver::iterator iterator = resolver.resolve( query, error );
+	tcp::resolver::results_type endpoints = resolver.resolve( m_data->m_host, m_data->m_port, error );
 	if( !error )
 	{
 		error = boost::asio::error::host_not_found;
-		while( error && iterator != tcp::resolver::iterator() )
+		for( auto it = endpoints.begin(); error && it != endpoints.end(); ++it )
 		{
 			m_data->m_socket.close();
-			m_data->m_socket.connect( *iterator++, error );
+			m_data->m_socket.connect( *it, error );
 		}
 	}
 	if( error )

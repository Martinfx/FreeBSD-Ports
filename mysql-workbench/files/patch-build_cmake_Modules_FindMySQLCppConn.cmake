--- build/cmake/Modules/FindMySQLCppConn.cmake.orig	2024-05-18 10:25:02 UTC
+++ build/cmake/Modules/FindMySQLCppConn.cmake
@@ -27,7 +27,7 @@ if (MySQLCppConn_INCLUDE_DIRS AND MySQLCppConn_LIBRARI
   set(MySQLCppConn_FIND_QUIETLY TRUE)
 endif ()
 
-find_path(MySQLCppConn_INCLUDE_DIR NAMES mysql_connection.h PATHS /usr/include /usr/local/include)
+find_path(MySQLCppConn_INCLUDE_DIR NAMES mysql_connection.h PATHS /usr/include /usr/include/jdbc /usr/local/include /usr/local/include/jdbc)
 
 SET(MySQLCppConn_NAMES mysqlcppconn)
 

--- include/maxscale/protocol/mariadb/mysql.hh.orig	2022-10-18 19:45:58 UTC
+++ include/maxscale/protocol/mariadb/mysql.hh
@@ -13,9 +13,12 @@
 #pragma once
 
 #include <maxscale/ccdefs.hh>
-
 #include <maxscale/buffer.hh>
 #include <maxscale/protocol/mariadb/common_constants.hh>
+
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#endif
 
 #define MYSQL_HEADER_LEN         4
 #define MYSQL_CHECKSUM_LEN       4

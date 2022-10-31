--- src/backend/utils/misc/guc.c.orig	2022-10-24 12:22:28 UTC
+++ src/backend/utils/misc/guc.c
@@ -10101,7 +10101,7 @@ check_client_connection_check_interval(int *newval, vo
 	/* Linux and OSX only, for now.  See pq_check_connection(). */
 	if (*newval != 0)
 	{
-		GUC_check_errdetail("client_connection_check_interval must be set to 0 on platforms that lack POLLRDHUP and not OSX.";
+		GUC_check_errdetail("client_connection_check_interval must be set to 0 on platforms that lack POLLRDHUP and not OSX.");
 		return false;
 	}
 #endif

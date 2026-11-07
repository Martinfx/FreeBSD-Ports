--- core/DesktopEditor/doctrenderer/hash.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/doctrenderer/hash.cpp
@@ -39,12 +39,12 @@
 #include "../common/Base64.h"
 #endif
 
-#include "openssl/sha.h"
-#include "openssl/md2.h"
-#include "openssl/md4.h"
-#include "openssl/md5.h"
-#include "openssl/whrlpool.h"
-#include "openssl/ripemd.h"
+#include <openssl/sha.h>
+#include <openssl/md2.h>
+#include <openssl/md4.h>
+#include <openssl/md5.h>
+#include <openssl/whrlpool.h>
+#include <openssl/ripemd.h>
 
 #include <cstring>
 #include <memory>
@@ -72,6 +72,7 @@
 
 	switch (alg)
 	{
+#if 0
 	case haMD2:
 	{
 		nBufLen = 16;
@@ -79,6 +80,7 @@
 		MD2(data, d, pBufData);
 		break;
 	}
+#endif
 	case haMD4:
 	{
 		nBufLen = 16;
@@ -281,11 +283,13 @@
 
 	switch (alg)
 	{
+#if 0
 	case CHash::haMD2:
 	{
 		MD2(input, alg_size + 4, tmp);
 		break;
 	}
+#endif
 	case CHash::haMD4:
 	{
 		MD4(input, alg_size + 4, tmp);
@@ -354,6 +358,7 @@
 	unsigned char* pBuffer1 = NULL;
 	switch (alg)
 	{
+#if 0
 	case haMD2:
 	{
 		alg_size = 16;
@@ -361,6 +366,7 @@
 		MD2(inputData, inputDataLen, pBuffer1);
 		break;
 	}
+#endif
 	case haMD4:
 	{
 		alg_size = 16;

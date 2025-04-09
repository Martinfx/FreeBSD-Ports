--- src/core/file_format/pkg.cpp.orig	2025-03-27 20:40:40 UTC
+++ src/core/file_format/pkg.cpp
@@ -2,6 +2,7 @@
 // SPDX-License-Identifier: GPL-2.0-or-later
 
 #include <zlib.h>
+#include <iostream>
 #include "common/io_file.h"
 #include "common/logging/formatter.h"
 #include "core/file_format/pkg.h"
@@ -188,8 +189,20 @@ bool PKG::Extract(const std::filesystem::path& filepat
             for (int i = 0; i < 7; i++) {
                 file.Read(key1[i]);
             }
+	    try {
+            	PKG::crypto.RSA2048Decrypt(dk3_, key1.at(3), true); // decrypt DK3
+            }
+            catch(const std::out_of_range& ex)
+	    {
+	    	std::cout << ex.what() << std::endl;
+            }
+            catch (const std::exception& e) {
+		std::cout << "exception type of: " << e.what() << std::endl;
+            }
+	    catch(...) {
+		std::cout << "unknow exception!" << std::endl;
+	    }
 
-            PKG::crypto.RSA2048Decrypt(dk3_, key1[3], true); // decrypt DK3
         } else if (entry.id == 0x20) {                       // IMAGE_KEY, seek; IV_KEY
             file.Seek(entry.offset);
             file.Read(imgkeydata);

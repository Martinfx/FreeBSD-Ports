--- core/Apple/IWork.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/Apple/IWork.cpp
@@ -41,7 +41,8 @@
 #include <libodfgen/OdtGenerator.hxx>
 #include <libodfgen/OdsGenerator.hxx>
 #include <libodfgen/OdpGenerator.hxx>
-#include <libodfgen/test/StringDocumentHandler.hxx>
+//#include <libodfgen/test/StringDocumentHandler.hxx>
+#include "StringDocumentHandler.hxx"
 
 #include <memory>
 #include <fstream>

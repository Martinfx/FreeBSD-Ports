--- src/Gaffer/FileSystemPath.cpp.orig	2025-10-29 16:02:16 UTC
+++ src/Gaffer/FileSystemPath.cpp
@@ -42,6 +42,7 @@
 #include "Gaffer/HiddenFilePathFilter.h"
 #include "Gaffer/MatchPatternPathFilter.h"
 #include "Gaffer/PathFilter.h"
+#include "Gaffer/Private/SlotBase.h"
 
 #include "IECore/DateTimeData.h"
 #include "IECore/FileSequenceFunctions.h"

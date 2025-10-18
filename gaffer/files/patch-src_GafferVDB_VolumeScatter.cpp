--- src/GafferVDB/VolumeScatter.cpp.orig	2025-03-07 08:50:55 UTC
+++ src/GafferVDB/VolumeScatter.cpp
@@ -50,7 +50,7 @@
 #include "openvdb/openvdb.h"
 #include "openvdb/tools/PointScatter.h"
 
-#include "pcg/pcg_random.hpp"
+#include "pcg_random.hpp"
 
 using namespace std;
 using namespace Imath;

--- src/GafferVDB/VolumeScatter.cpp.orig	2026-09-24 19:41:12 UTC
+++ src/GafferVDB/VolumeScatter.cpp
@@ -50,7 +50,8 @@
 #include "openvdb/openvdb.h"
 #include "openvdb/tools/PointScatter.h"
 
-#include "pcg/pcg_random.hpp"
+// FreeBSD's devel/pcg-cpp installs its headers directly in `include`.
+#include "pcg_random.hpp"
 
 using namespace std;
 using namespace Imath;

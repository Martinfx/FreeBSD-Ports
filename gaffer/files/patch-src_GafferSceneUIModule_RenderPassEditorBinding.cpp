--- src/GafferSceneUIModule/RenderPassEditorBinding.cpp.orig	2026-09-24 19:41:12 UTC
+++ src/GafferSceneUIModule/RenderPassEditorBinding.cpp
@@ -58,6 +58,7 @@
 
 #include "boost/algorithm/string/predicate.hpp"
 #include "boost/bind/bind.hpp"
+#include "boost/mpl/vector.hpp"
 
 using namespace std;
 using namespace boost::placeholders;

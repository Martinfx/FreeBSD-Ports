--- include/GafferSceneTest/ContextSanitiser.h.orig	2026-05-27 19:02:41 UTC
+++ include/GafferSceneTest/ContextSanitiser.h
@@ -44,6 +44,8 @@
 #include "boost/functional/hash.hpp"
 
 #include "tbb/concurrent_unordered_set.h"
+#include <functional>
+#include <utility>
 
 namespace GafferSceneTest
 {
@@ -63,7 +65,7 @@ class GAFFERSCENETEST_API ContextSanitiser : public Ga
 		void processStarted( const Gaffer::Process *process ) override;
 		void processFinished( const Gaffer::Process *process ) override;
 
-	private :
+/*	private :
 
 		/// First is the upstream plug where the problem was detected. Second
 		/// is the plug from the parent process responsible for calling upstream.
@@ -86,7 +88,7 @@ class GAFFERSCENETEST_API ContextSanitiser : public Ga
 
 		using WarningSet = tbb::concurrent_unordered_set<Warning, WarningHash>;
 		WarningSet m_warningsEmitted;
-
+*/
 };
 
 IE_CORE_DECLAREPTR( ContextSanitiser )

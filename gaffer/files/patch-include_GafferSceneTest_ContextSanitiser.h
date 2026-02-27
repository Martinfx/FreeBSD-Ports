--- include/GafferSceneTest/ContextSanitiser.h.orig	2025-03-03 10:05:07 UTC
+++ include/GafferSceneTest/ContextSanitiser.h
@@ -42,6 +42,8 @@
 #include "Gaffer/Plug.h"
 
 #include "tbb/concurrent_unordered_set.h"
+#include <functional>
+#include <utility>
 
 namespace GafferSceneTest
 {
@@ -61,7 +63,7 @@ class GAFFERSCENETEST_API ContextSanitiser : public Ga
 		void processStarted( const Gaffer::Process *process ) override;
 		void processFinished( const Gaffer::Process *process ) override;
 
-	private :
+/*	private :
 
 		/// First is the upstream plug where the problem was detected. Second
 		/// is the plug from the parent process responsible for calling upstream.
@@ -72,7 +74,7 @@ class GAFFERSCENETEST_API ContextSanitiser : public Ga
 
 		using WarningSet = tbb::concurrent_unordered_set<Warning>;
 		WarningSet m_warningsEmitted;
-
+*/
 };
 
 IE_CORE_DECLAREPTR( ContextSanitiser )

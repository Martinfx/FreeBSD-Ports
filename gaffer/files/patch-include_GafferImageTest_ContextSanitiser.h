--- include/GafferImageTest/ContextSanitiser.h.orig	2025-03-03 12:59:13 UTC
+++ include/GafferImageTest/ContextSanitiser.h
@@ -60,7 +60,7 @@ class GAFFERIMAGETEST_API ContextSanitiser : public Ga
 
 		void processStarted( const Gaffer::Process *process ) override;
 		void processFinished( const Gaffer::Process *process ) override;
-
+/*
 	private :
 
 		/// First is the upstream plug where the problem was detected. Second
@@ -72,7 +72,7 @@ class GAFFERIMAGETEST_API ContextSanitiser : public Ga
 
 		using WarningSet = tbb::concurrent_unordered_set<Warning>;
 		WarningSet m_warningsEmitted;
-
+*/
 };
 
 IE_CORE_DECLAREPTR( ContextSanitiser )

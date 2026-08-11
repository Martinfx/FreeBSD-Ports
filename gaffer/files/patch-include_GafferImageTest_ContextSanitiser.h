--- include/GafferImageTest/ContextSanitiser.h.orig	2026-05-27 19:02:41 UTC
+++ include/GafferImageTest/ContextSanitiser.h
@@ -62,7 +62,7 @@ class GAFFERIMAGETEST_API ContextSanitiser : public Ga
 
 		void processStarted( const Gaffer::Process *process ) override;
 		void processFinished( const Gaffer::Process *process ) override;
-
+/*
 	private :
 
 		/// First is the upstream plug where the problem was detected. Second
@@ -86,7 +86,7 @@ class GAFFERIMAGETEST_API ContextSanitiser : public Ga
 
 		using WarningSet = tbb::concurrent_unordered_set<Warning, WarningHash>;
 		WarningSet m_warningsEmitted;
-
+*/
 };
 
 IE_CORE_DECLAREPTR( ContextSanitiser )

--- browser/components/urlbar/UrlbarProviderInterventions.jsm.orig	2021-09-26 16:39:51 UTC
+++ browser/components/urlbar/UrlbarProviderInterventions.jsm
@@ -451,7 +451,7 @@ class ProviderInterventions extends UrlbarProvider {
         ]),
       });
       for (let [id, phrases] of Object.entries(DOCUMENTS)) {
-        queryScorer.addDocument({ id, phrases });
+//        queryScorer.addDocument({ id, phrases });
       }
       return queryScorer;
     });

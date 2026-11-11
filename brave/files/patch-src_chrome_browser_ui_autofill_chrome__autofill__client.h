--- src/chrome/browser/ui/autofill/chrome_autofill_client.h.orig	2026-11-02 23:22:33 UTC
+++ src/chrome/browser/ui/autofill/chrome_autofill_client.h
@@ -135,7 +135,7 @@ class ChromeAutofillClient : public Cont
   ~ChromeAutofillClient() override;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Triggers the AtMemory promo bubble.
   void ShowAutofillAtMemoryPromo();
 #endif

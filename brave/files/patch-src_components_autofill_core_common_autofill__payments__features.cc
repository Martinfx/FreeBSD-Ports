--- src/components/autofill/core/common/autofill_payments_features.cc.orig	2026-11-02 23:22:33 UTC
+++ src/components/autofill/core/common/autofill_payments_features.cc
@@ -32,7 +32,7 @@ BASE_FEATURE(kAutofillDisableBnplCountry
 // page using server-side AI.
 BASE_FEATURE(kAutofillEnableAiBasedAmountExtraction,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -80,7 +80,7 @@ BASE_OVERRIDDEN_FEATURE(kAutofillEnableB
 // (BNPL) issuers that are externally linked.
 BASE_FEATURE(kAutofillEnableBuyNowPayLaterForExternallyLinked,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -91,7 +91,7 @@ BASE_FEATURE(kAutofillEnableBuyNowPayLat
 // offered.
 BASE_FEATURE(kAutofillEnableBuyNowPayLaterForKlarna,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -101,7 +101,7 @@ BASE_FEATURE(kAutofillEnableBuyNowPayLat
 // When enabled, buy now pay later (BNPL) data will be synced to Chrome clients.
 BASE_FEATURE(kAutofillEnableBuyNowPayLaterSyncing,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -112,7 +112,7 @@ BASE_FEATURE(kAutofillEnableBuyNowPayLat
 // include the issuer names for better brand recognition.
 BASE_FEATURE(kAutofillEnableBuyNowPayLaterUpdatedSuggestionSecondLineString,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -132,7 +132,7 @@ BASE_FEATURE(kAutofillEnableCardBenefits
 // UI.
 BASE_FEATURE(kAutofillEnableCardBenefitsForBmo,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -177,7 +177,7 @@ BASE_FEATURE(kAutofillEnableFlatRateCard
 // Payments Autofill UI.
 BASE_FEATURE(kAutofillEnableFlatRateCardBenefitsFromCurinos,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -228,7 +228,7 @@ BASE_FEATURE(kAutofillEnablePayNowPayLat
 // prompted to turn it back on in instances where they can benefit from it.
 BASE_FEATURE(kAutofillEnableResurrectingPaymentsUsers,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -260,7 +260,7 @@ BASE_FEATURE(kAutofillEnableTravelCatego
 // the card, and FIDO is not.
 BASE_FEATURE(kAutofillEnableVcn3dsAuthentication,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -328,7 +328,7 @@ BASE_FEATURE(kAutofillParseLegalMessageL
 // eligibility.
 BASE_FEATURE(kAutofillPreferBuyNowPayLaterBlocklists,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -382,7 +382,7 @@ const base::FeatureParam<int> kAutofillU
     "autofill_upstream_enforce_strike_delay_days", 1};
 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
 #else

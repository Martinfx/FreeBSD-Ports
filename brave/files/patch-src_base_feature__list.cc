--- src/base/feature_list.cc.orig	2026-06-01 00:00:00 UTC
+++ src/base/feature_list.cc
@@ -658,6 +658,9 @@
 }
 
 bool FeatureList::IsFeatureOverridden(std::string_view feature_name) const {
+#if defined(BRAVE_REDIRECT_CC_BUILD)
+  return GetOverrideEntryByFeatureName(feature_name);
+#else
   bool result = [&]() -> bool {
   return GetOverrideEntryByFeatureName(feature_name);
   }();
@@ -665,6 +668,7 @@
     return result;
   }
   return internal::IsFeatureOverridden(feature_name);
+#endif
 }
 
 bool FeatureList::IsFeatureOverriddenFromCommandLine(
@@ -770,8 +774,13 @@
     EarlyFeatureAccessTracker::GetInstance()->AccessedFeature(
         feature, g_feature_list_instance &&
                      g_feature_list_instance->IsEarlyAccessInstance());
+#if defined(BRAVE_REDIRECT_CC_BUILD)
+    return feature.default_state == FEATURE_ENABLED_BY_DEFAULT ||
+           feature.default_state == FEATURE_DISABLED_FOR_COUNTRIES;
+#else
     return GetCompileTimeFeatureState(feature) == FEATURE_ENABLED_BY_DEFAULT ||
            GetCompileTimeFeatureState(feature) == FEATURE_DISABLED_FOR_COUNTRIES;
+#endif
   }
   return g_feature_list_instance->IsFeatureEnabled(feature);
 }
@@ -783,6 +792,7 @@
 
 // static
 std::optional<bool> FeatureList::GetStateIfOverridden(const Feature& feature) {
+#if !defined(BRAVE_REDIRECT_CC_BUILD)
   std::optional<bool> result = [&]() -> std::optional<bool> {
   if (!g_feature_list_instance ||
       !g_feature_list_instance->AllowFeatureAccess(feature)) {
@@ -798,6 +808,17 @@
     return result;
   }
   return internal::GetStateIfOverridden(feature);
+#else
+  if (!g_feature_list_instance ||
+      !g_feature_list_instance->AllowFeatureAccess(feature)) {
+    EarlyFeatureAccessTracker::GetInstance()->AccessedFeature(
+        feature, g_feature_list_instance &&
+                     g_feature_list_instance->IsEarlyAccessInstance());
+    // If there is no feature list, there can be no overrides.
+    return std::nullopt;
+  }
+  return g_feature_list_instance->IsFeatureEnabledIfOverridden(feature);
+#endif
 }
 
 // static

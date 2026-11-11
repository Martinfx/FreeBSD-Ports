--- src/third_party/blink/renderer/platform/fonts/font_custom_platform_data.cc.orig	2026-11-02 23:22:33 UTC
+++ src/third_party/blink/renderer/platform/fonts/font_custom_platform_data.cc
@@ -356,7 +356,8 @@ FontCustomPlatformData* FontCustomPlatfo
     SharedBuffer* buffer,
     String& ots_parse_message) {
   DCHECK(buffer);
-  base::expected<DecodedWebFont, String> decode_result = DecodeWebFont(buffer);
+  base::expected<DecodedWebFont, String> decode_result =
+      DecodedWebFont::Create(buffer);
   if (!decode_result.has_value()) {
     ots_parse_message = std::move(decode_result).error();
     return nullptr;

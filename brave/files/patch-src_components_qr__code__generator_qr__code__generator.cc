--- src/components/qr_code_generator/qr_code_generator.cc.orig	2026-11-02 23:22:33 UTC
+++ src/components/qr_code_generator/qr_code_generator.cc
@@ -10,10 +10,17 @@
 
 #include "base/check.h"
 #include "base/check_op.h"
+#include "base/containers/span_rust.h"
 #include "base/numerics/safe_conversions.h"
+#include "components/qr_code_generator/cpp_api_from_rust_buildflags.h"
+
+#if BUILDFLAG(ENABLE_CPP_API_FROM_RUST)
 #include "third_party/crubit/support/rs_std/iterator_adapter.h"
 #include "third_party/crubit/support/rs_std/slice_ref.h"
 #include "third_party/rust/qr_code/v2/qr_code.h"
+#else
+#include "components/qr_code_generator/qr_code_generator_ffi_glue.rs.h"
+#endif
 
 namespace qr_code_generator {
 
@@ -22,6 +29,7 @@ GeneratedCode::~GeneratedCode() = defaul
 GeneratedCode::GeneratedCode(GeneratedCode&&) = default;
 GeneratedCode& GeneratedCode::operator=(GeneratedCode&&) = default;
 
+#if BUILDFLAG(ENABLE_CPP_API_FROM_RUST)
 Error RustErrorToCppError(const ::qr_code::types::QrError& rust_error) {
   if (rust_error == ::qr_code::types::QrError::MakeDataTooLong()) {
     return Error::kInputTooLong;
@@ -63,5 +71,32 @@ base::expected<GeneratedCode, Error> Gen
   CHECK_EQ(code.data.size(), static_cast<size_t>(code.qr_size * code.qr_size));
   return code;
 }
+#else
+base::expected<GeneratedCode, Error> GenerateCode(
+    base::span<const uint8_t> in,
+    std::optional<int> min_version) {
+  rust::Slice<const uint8_t> rs_in = base::SpanToRustSlice(in);
+
+  // `min_version` might come from a fuzzer and therefore we use a lenient
+  // `saturated_cast` instead of a `checked_cast`.
+  int16_t rs_min_version =
+      base::saturated_cast<int16_t>(min_version.value_or(0));
+
+  std::vector<uint8_t> result_pixels;
+  size_t result_width = 0;
+  Error result_error = Error::kUnknownError;
+  bool result_is_success = generate_qr_code_using_rust(
+      rs_in, rs_min_version, result_pixels, result_width, result_error);
+
+  if (!result_is_success) {
+    return base::unexpected(result_error);
+  }
+  GeneratedCode code;
+  code.data = std::move(result_pixels);
+  code.qr_size = base::checked_cast<int>(result_width);
+  CHECK_EQ(code.data.size(), static_cast<size_t>(code.qr_size * code.qr_size));
+  return code;
+}
+#endif
 
 }  // namespace qr_code_generator

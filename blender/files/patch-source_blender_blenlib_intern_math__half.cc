--- source/blender/blenlib/intern/math_half.cc.orig	2026-09-26 12:00:00 UTC
+++ source/blender/blenlib/intern/math_half.cc
@@ -242,7 +242,7 @@ void blender::math::float_to_half_array(
   for (; i + 7 < length; i += 8) {
     __m256 src8 = _mm256_loadu_ps(src);
     __m128i h8 = _mm256_cvtps_ph(src8, _MM_FROUND_TO_NEAREST_INT);
-    _mm_storeu_epi32(dst, h8);
+    _mm_storeu_si128((__m128i *)dst, h8);
     src += 8;
     dst += 8;
   }
@@ -271,6 +271,32 @@ void blender::math::float_to_half_array(
   }
 }
 
+#if !defined(__SSE4_1__) && (defined(__x86_64__) || defined(_M_X64))
+static inline __m128i srai_epi8_sse2(__m128i x, int imm)
+{
+    // Sign-extend bytes to 16-bit
+    __m128i sign = _mm_cmpgt_epi8(_mm_setzero_si128(), x); // 0xFF where x < 0
+    __m128i lo = _mm_unpacklo_epi8(x, sign);
+    __m128i hi = _mm_unpackhi_epi8(x, sign);
+
+    // Arithmetic shift right on 16-bit lanes
+    lo = _mm_srai_epi16(lo, imm);
+    hi = _mm_srai_epi16(hi, imm);
+
+    // Pack back to 8-bit (signed saturation)
+    return _mm_packs_epi16(lo, hi);
+}
+
+static inline __m128i blendv_epi8_sse2(__m128i a, __m128i b, __m128i mask)
+{
+    mask = srai_epi8_sse2(mask, 7);
+    return _mm_or_si128(
+        _mm_and_si128(mask, b),
+        _mm_andnot_si128(mask, a)
+    );
+}
+#endif
+
 void blender::math::float_to_half_make_finite_array(const float *src, uint16_t *dst, size_t length)
 {
   size_t i = 0;
@@ -320,8 +346,13 @@ void blender::math::float_to_half_make_f
       __m128i inf_res = _mm_or_si128(signbits, _mm_set1_epi16(0x7bffu)); /* +/- 65504 */
       __m128i nan_res = signbits;                                        /* +/- 0 */
       /* Select final result. */
+#if defined(__SSE4_1__)
       h4 = _mm_blendv_epi8(h4, inf_res, is_inf);
       h4 = _mm_blendv_epi8(h4, nan_res, is_nan);
+#else
+      h4 = blendv_epi8_sse2(h4, inf_res, is_inf);
+      h4 = blendv_epi8_sse2(h4, nan_res, is_nan);
+#endif
       h4 = _mm_and_si128(h4, _mm_set1_epi32(0xffff));
       h4 = _mm_or_si128(h4, hi_part);
     }
@@ -370,7 +401,7 @@ void blender::math::half_to_float_array(
   size_t i = 0;
 #if defined(USE_HARDWARE_FP16_F16C) /* 8-wide loop using AVX2 F16C */
   for (; i + 7 < length; i += 8) {
-    __m128i src8 = _mm_loadu_epi32(src);
+    __m128i src8 = _mm_loadu_si128((const __m128i *)src);
     __m256 f8 = _mm256_cvtph_ps(src8);
     _mm256_storeu_ps(dst, f8);
     src += 8;

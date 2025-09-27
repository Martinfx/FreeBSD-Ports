--- src/video_core/buffer_cache/buffer.cpp.orig	2025-09-22 18:46:43 UTC
+++ src/video_core/buffer_cache/buffer.cpp
@@ -71,10 +71,9 @@ void UniqueBuffer::Create(const vk::BufferCreateInfo& 
 void UniqueBuffer::Create(const vk::BufferCreateInfo& buffer_ci, MemoryUsage usage,
                           VmaAllocationInfo* out_alloc_info) {
     const bool with_bda = bool(buffer_ci.usage & vk::BufferUsageFlagBits::eShaderDeviceAddress);
-    const VmaAllocationCreateFlags bda_flag =
-        with_bda ? VMA_ALLOCATION_CREATE_DEDICATED_MEMORY_BIT : 0;
+    const VmaAllocationCreateFlags bda_flag = VMA_ALLOCATION_CREATE_DEDICATED_MEMORY_BIT;
     const VmaAllocationCreateInfo alloc_ci = {
-        .flags = VMA_ALLOCATION_CREATE_WITHIN_BUDGET_BIT | bda_flag | MemoryUsageVmaFlags(usage),
+        .flags =  bda_flag | VMA_ALLOCATION_CREATE_WITHIN_BUDGET_BIT | MemoryUsageVmaFlags(usage),
         .usage = MemoryUsageVma(usage),
         .requiredFlags = 0,
         .preferredFlags = MemoryUsagePreferredVmaFlags(usage),

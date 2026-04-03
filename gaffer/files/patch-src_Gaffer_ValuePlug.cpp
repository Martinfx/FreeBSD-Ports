--- src/Gaffer/ValuePlug.cpp.orig	2025-02-19 21:25:16 UTC
+++ src/Gaffer/ValuePlug.cpp
@@ -53,6 +53,7 @@
 
 #include <atomic>
 #include <unordered_set>
+#include <functional>
 
 using namespace Gaffer;
 
@@ -108,22 +109,22 @@ struct HashCacheKey
 // the plug the hash was for and the context it was hashed in.
 struct HashCacheKey
 {
-	HashCacheKey() {};
-	HashCacheKey( const ValuePlug *plug, const Context *context, uint64_t dirtyCount )
-		:	plug( plug ), contextHash( context->hash() ), dirtyCount( dirtyCount )
-	{
-	}
+    HashCacheKey() = default;
+    HashCacheKey(const ValuePlug* plug, const Context* context, uint64_t dirtyCount)
+        : plug(plug), contextHash(context->hash()), dirtyCount(dirtyCount)
+    {
+    }
 
-	bool operator == ( const HashCacheKey &other ) const
-	{
-		return other.plug == plug && other.contextHash == contextHash && dirtyCount == other.dirtyCount;
-	}
-
-	/// \todo Could we merge all three fields into a single
-	/// MurmurHash, or would hash collisions be too likely?
-	const ValuePlug *plug;
-	IECore::MurmurHash contextHash;
-	uint64_t dirtyCount;
+    bool operator==(const HashCacheKey& other) const
+    {
+        return plug == other.plug &&
+               contextHash == other.contextHash &&
+               dirtyCount == other.dirtyCount;
+    }
+	
+    const ValuePlug* plug;
+    IECore::MurmurHash contextHash;
+    uint64_t dirtyCount;
 };
 
 // `hash_value( HashCacheKey )` is a requirement of the LRUCache,
@@ -466,6 +467,20 @@ class ValuePlug::HashProcess : public Process
 		static std::atomic_size_t g_cacheSizeLimit;
 
 };
+
+namespace std {
+    template<>
+    struct hash<HashCacheKey> {
+        size_t operator()(const HashCacheKey& key) const noexcept {
+            // Combine hashes of member variables
+            size_t h1 = hash<const ValuePlug*>()(key.plug);
+            size_t h2 = hash<IECore::MurmurHash>()(key.contextHash);
+            size_t h3 = hash<uint64_t>()(key.dirtyCount);
+            return h1 ^ (h2 << 1) ^ (h3 << 2); // Example hash combination
+        }
+    };
+}
+
 
 const IECore::InternedString ValuePlug::HashProcess::staticType( ValuePlug::hashProcessType() );
 tbb::enumerable_thread_specific<ValuePlug::HashProcess::ThreadData, tbb::cache_aligned_allocator<ValuePlug::HashProcess::ThreadData>, tbb::ets_key_per_instance > ValuePlug::HashProcess::g_threadData;

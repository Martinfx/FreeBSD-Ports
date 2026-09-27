--- pxr/usd/sdf/testenv/testSdfPathThreading.cpp.orig	2026-04-24 18:55:54 UTC
+++ pxr/usd/sdf/testenv/testSdfPathThreading.cpp
@@ -16,6 +16,7 @@
 #include <ctime>
 #include <cstdlib>
 #include <mutex>
+#include <random>
 #include <thread>
 
 
@@ -29,6 +30,18 @@ static unsigned int randomSeed;
 static size_t numThreads;
 static size_t msecsToRun = 2000;
 
+// rand() is not thread-safe.  FreeBSD's rand() does not lock, and concurrent
+// calls corrupt its state so that it returns long runs of even numbers, which
+// make _MakeRandomPath() recurse until the stack overflows.  Use a generator
+// per thread instead.
+static int
+_Rand()
+{
+    static std::atomic<unsigned int> nextSeed(0);
+    thread_local std::mt19937 generator(randomSeed + nextSeed++);
+    return static_cast<int>(generator() >> 1);
+}
+
 TF_MAKE_STATIC_DATA(vector<TfToken>, nameTokens)
 {
     nameTokens->push_back(TfToken("A"));
@@ -46,7 +59,7 @@ TF_MAKE_STATIC_DATA(vector<TfToken>, nam
 static TfToken
 _GetRandomNameToken()
 {
-    return (*nameTokens)[rand() % nameTokens->size()];
+    return (*nameTokens)[_Rand() % nameTokens->size()];
 }
 
 static SdfPath
@@ -54,7 +67,7 @@ _MakeRandomPrimPath()
 {
     static const size_t maxDepth = 2;
     SdfPath ret = SdfPath::AbsoluteRootPath();
-    for (size_t i = 0, depth = rand() % maxDepth; i <= depth; ++i)
+    for (size_t i = 0, depth = _Rand() % maxDepth; i <= depth; ++i)
         ret = ret.AppendChild(_GetRandomNameToken());
     return ret;
 }
@@ -63,7 +76,7 @@ static SdfPath
 _MakeRandomPrimOrPropertyPath()
 {
     SdfPath ret = _MakeRandomPrimPath();
-    return rand() & 1 ? ret : ret.AppendProperty(_GetRandomNameToken());
+    return _Rand() & 1 ? ret : ret.AppendProperty(_GetRandomNameToken());
 }
 
 static SdfPath
@@ -76,21 +89,21 @@ _MakeRandomPath(SdfPath const &path = Sd
         ret = _MakeRandomPrimPath();
 
     // Extend a PrimPath.
-    if (ret.IsPrimPath() && (rand() & 1)) {
+    if (ret.IsPrimPath() && (_Rand() & 1)) {
         ret = ret.AppendVariantSelection(_GetRandomNameToken().GetString(),
                                          _GetRandomNameToken().GetString());
     }
 
     // Extend a PrimPath or a PrimVariantSelectionPath.
     if ((ret.IsPrimPath() || ret.IsPrimVariantSelectionPath())) {
-        return (rand() & 1) ? ret :
+        return (_Rand() & 1) ? ret :
             _MakeRandomPath(ret.AppendProperty(_GetRandomNameToken()));
     }
 
     // Extend a PrimPropertyPath
     if (ret.IsPrimPropertyPath()) {
         // options: target path, mapper path, expression path, or leave alone.
-        switch (rand() & 3) {
+        switch (_Rand() & 3) {
         case 0:
             return _MakeRandomPath(
                 ret.AppendTarget(_MakeRandomPrimOrPropertyPath()));
@@ -106,20 +119,20 @@ _MakeRandomPath(SdfPath const &path = Sd
 
     // Extend a TargetPath
     if (ret.IsTargetPath()) {
-        return (rand() & 1) ? ret :
+        return (_Rand() & 1) ? ret :
             _MakeRandomPath(
             ret.AppendRelationalAttribute(_GetRandomNameToken()));
     }
 
     // Extend a MapperPath
     if (ret.IsMapperPath()) {
-        return (rand() & 1) ? ret :
+        return (_Rand() & 1) ? ret :
             _MakeRandomPath(ret.AppendMapperArg(_GetRandomNameToken()));
     }
 
     // Extend a RelationalAttributePath
     if (ret.IsRelationalAttributePath()) {
-        return (rand() & 1) ? ret :
+        return (_Rand() & 1) ? ret :
             _MakeRandomPath(ret.AppendTarget(_MakeRandomPrimOrPropertyPath()));
     }
 
@@ -139,14 +152,14 @@ static TfStaticData<std::mutex> pathCach
 static void _PutPath(SdfPath const &path)
 {
     std::lock_guard<std::mutex> lock(*pathCacheMutex);
-    size_t index = rand() % pathCache->size();
+    size_t index = _Rand() % pathCache->size();
     (*pathCache)[index] = path;
 }
 
 static SdfPath _GetPath()
 {
     std::lock_guard<std::mutex> lock(*pathCacheMutex);
-    size_t index = rand() % pathCache->size();
+    size_t index = _Rand() % pathCache->size();
     return (*pathCache)[index];
 }
 
@@ -158,7 +171,7 @@ static TfStopwatch _DoPathOperations()
 
     while (static_cast<size_t>(sw.GetMilliseconds()) < msecsToRun) {
         sw.Start();
-        SdfPath p = (rand() & 1) ? _GetPath() : SdfPath::AbsoluteRootPath();
+        SdfPath p = (_Rand() & 1) ? _GetPath() : SdfPath::AbsoluteRootPath();
         // If the path is not very extensible, trim it back to the prim path.
         if (p.IsExpressionPath() || p.IsMapperArgPath() || p.IsMapperPath())
             p = p.GetPrimPath();

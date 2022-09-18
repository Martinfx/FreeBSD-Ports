--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/Iterator.cc.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/Iterator.cc
@@ -61,7 +61,7 @@ const char * KeyGroupIteratorImpl::nextValue(uint32_t 
   case SAME_KEY: {
     if (next()) {
       if (_key.length() == _currentGroupKey.length()) {
-        if (fmemeq(_key.data(), _currentGroupKey.c_str(), _key.length())) {
+        if (memcmp(_key.data(), _currentGroupKey.c_str(), _key.length()) == 0) {
           len = _value.length();
           return _value.data();
         }

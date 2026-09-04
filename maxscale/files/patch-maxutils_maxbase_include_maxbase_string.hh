--- maxutils/maxbase/include/maxbase/string.hh.orig	2022-09-12 06:23:56 UTC
+++ maxutils/maxbase/include/maxbase/string.hh
@@ -123,7 +123,7 @@ inline void ltrim(std::string& s)
     s.erase(s.begin(),
             std::find_if(s.begin(),
                          s.end(),
-                         std::not1(std::ptr_fun<int, int>(std::isspace))));
+                         [](unsigned char c){ return !std::isspace(c);}));
 }
 
 /**
@@ -135,7 +135,8 @@ inline void rtrim(std::string& s)
 {
     s.erase(std::find_if(s.rbegin(),
                          s.rend(),
-                         std::not1(std::ptr_fun<int, int>(std::isspace))).base(),
+                         [](unsigned char c){ return !std::isspace(c);}).base(),
+                         //std::not1(std::ptr_fun<int, int>(std::isspace))).base(),
             s.end());
 }
 

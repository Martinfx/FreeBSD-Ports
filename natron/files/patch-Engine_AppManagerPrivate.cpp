--- Engine/AppManagerPrivate.cpp.orig	2020-10-30 05:13:34 UTC
+++ Engine/AppManagerPrivate.cpp
@@ -117,7 +117,11 @@ AppManagerPrivate::AppManagerPrivate()
     , nThreadsMutex()
     , runningThreadsCount()
     , lastProjectLoadedCreatedDuringRC2Or3(false)
+#if PY_MAJOR_VERSION >= 3
+    , commandLineArgsWide()
+#else
     , commandLineArgsUtf8()
+#endif
     , nArgs(0)
     , mainModule(0)
     , mainThreadState(0)
@@ -145,16 +149,16 @@ AppManagerPrivate::AppManagerPrivate()
 
 AppManagerPrivate::~AppManagerPrivate()
 {
-    
 
-    for (std::size_t i = 0; i < commandLineArgsUtf8Original.size(); ++i) {
-        free(commandLineArgsUtf8Original[i]);
-    }
 #if PY_MAJOR_VERSION >= 3
     // Python 3
     for (std::size_t i = 0; i < commandLineArgsWideOriginal.size(); ++i) {
         free(commandLineArgsWideOriginal[i]);
     }
+#else
+    for (std::size_t i = 0; i < commandLineArgsUtf8Original.size(); ++i) {
+        free(commandLineArgsUtf8Original[i]);
+    }
 #endif
 }
 
@@ -1011,22 +1015,23 @@ AppManagerPrivate::copyUtf8ArgsToMembers(const std::ve
 #if PY_MAJOR_VERSION >= 3
     // Python 3
     commandLineArgsWideOriginal.resize(utf8Args.size());
-#endif
+    nArgs = (int)utf8Args.size();
+    for (std::size_t i = 0; i < utf8Args.size(); ++i) {
+        commandLineArgsWideOriginal[i] = AppManager::char2wchar(utf8Args[i].c_str());
+    }
+
+    commandLineArgsWide = commandLineArgsWideOriginal;
+
+#else
     commandLineArgsUtf8Original.resize(utf8Args.size());
     nArgs = (int)utf8Args.size();
     for (std::size_t i = 0; i < utf8Args.size(); ++i) {
         commandLineArgsUtf8Original[i] = strdup(utf8Args[i].c_str());
 
-        // Python 3 needs wchar_t arguments
-#if PY_MAJOR_VERSION >= 3
-        // Python 3
-        commandLineArgsWideOriginal[i] = char2wchar(utf8Args[i].c_str());
-#endif
     }
+
     commandLineArgsUtf8 = commandLineArgsUtf8Original;
-#if PY_MAJOR_VERSION >= 3
-    // Python 3
-    commandLineArgsWide = commandLineArgsWideOriginal;
+
 #endif
 }
 

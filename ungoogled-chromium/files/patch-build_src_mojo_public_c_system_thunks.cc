--- build/src/mojo/public/c/system/thunks.cc.orig	2021-01-12 11:48:45 UTC
+++ build/src/mojo/public/c/system/thunks.cc
@@ -1,3 +1,4 @@
+
 // Copyright 2013 The Chromium Authors. All rights reserved.
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
@@ -20,7 +21,7 @@
 #include "mojo/public/c/system/core.h"
 #include "mojo/public/c/system/macros.h"
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "base/environment.h"
 #include "base/files/file_path.h"
 #include "base/optional.h"
@@ -68,7 +69,7 @@ class CoreLibraryInitializer {
   ~CoreLibraryInitializer() = default;
 
   MojoResult LoadLibrary(base::FilePath library_path) {
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
     if (library_ && library_->is_valid())
       return MOJO_RESULT_OK;
 
@@ -82,7 +83,7 @@ class CoreLibraryInitializer {
 
     if (library_path.empty()) {
       // Default to looking for the library in the current working directory.
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
       const base::FilePath::CharType kDefaultLibraryPathValue[] =
           FILE_PATH_LITERAL("./libmojo_core.so");
 #elif defined(OS_WIN)
@@ -132,7 +133,7 @@ class CoreLibraryInitializer {
   }
 
  private:
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   base::Optional<base::ScopedNativeLibrary> library_;
 #endif
 };

--- src/shadercompiler/SpvShaderCompiler.cpp.orig	2024-11-26 12:18:34 UTC
+++ src/shadercompiler/SpvShaderCompiler.cpp
@@ -9,9 +9,14 @@
     #include "glslang/Include/ResourceLimits.h"
 #elif __linux__
     #include <glslang/Public/ShaderLang.h>
-	#include <glslang/SPIRV/GlslangToSpv.h>
+    #include <glslang/SPIRV/GlslangToSpv.h>
     #include "DirStackFileIncluder.h"
-	#include <glslang/Include/ResourceLimits.h>
+    #include <glslang/Include/ResourceLimits.h>
+#elif __FreeBSD__
+    #include <glslang/Public/ShaderLang.h>
+    #include <glslang/SPIRV/GlslangToSpv.h>
+    #include "DirStackFileIncluder.h"
+    #include <glslang/Include/ResourceLimits.h>
 #endif
 
 struct SpvCompiler::Impl
@@ -134,7 +139,7 @@ struct SpvCompiler::Impl
 
 		/* .limits = */
 		/* .nonInductiveForLoops = */ 1,
-        {
+
             /* .whileLoops = */ 1,
             /* .doWhileLoops = */ 1,
             /* .generalUniformIndexing = */ 1,
@@ -143,7 +148,7 @@ struct SpvCompiler::Impl
             /* .generalSamplerIndexing = */ 1,
             /* .generalVariableIndexing = */ 1,
             /* .generalConstantMatrixVectorIndexing = */ 1
-        }
+
 	};
 };
 

--- src/GafferImageUI/OpenColorIOAlgo.cpp.orig	2025-03-03 12:36:18 UTC
+++ src/GafferImageUI/OpenColorIOAlgo.cpp
@@ -347,7 +347,8 @@ IECoreGL::Shader::SetupPtr displayTransformToFramebuff
 			unsigned height = 0;
 			OCIO_NAMESPACE::GpuShaderDesc::TextureType channel = OCIO_NAMESPACE::GpuShaderDesc::TEXTURE_RGB_CHANNEL;
 			OCIO_NAMESPACE::Interpolation interpolation = OCIO_NAMESPACE::INTERP_LINEAR;
-			shaderDesc->getTexture(idx, textureName, samplerName, width, height, channel, interpolation);
+			OCIO_NAMESPACE::GpuShaderDesc::TextureDimensions dimensions;
+			shaderDesc->getTexture(idx, textureName, samplerName, width, height, channel, dimensions, interpolation);
 			if (
 				!textureName || !*textureName || !samplerName || !*samplerName || width == 0
 			)

--- src/GafferCycles/IECoreCyclesPreview/IECoreCycles.cpp.orig	2025-03-04 16:50:13 UTC
+++ src/GafferCycles/IECoreCyclesPreview/IECoreCycles.cpp
@@ -496,7 +496,7 @@ bool init()
 	auto kernelFile = std::filesystem::path( cyclesRootValue ) / "source" / "kernel" / "types.h";
 	if( !std::filesystem::is_regular_file( kernelFile ) )
 	{
-		IECore::msg( IECore::Msg::Error, "IECoreCycles::init", fmt::format( "File \"{}\" not found", kernelFile ) );
+		IECore::msg( IECore::Msg::Error, "IECoreCycles::init", fmt::format( "File \"{}\" not found", kernelFile.string() ) );
 		return false;
 	}
 

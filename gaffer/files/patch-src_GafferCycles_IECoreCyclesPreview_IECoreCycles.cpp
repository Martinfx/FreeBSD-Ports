--- src/GafferCycles/IECoreCyclesPreview/IECoreCycles.cpp.orig	2025-10-10 20:24:55 UTC
+++ src/GafferCycles/IECoreCyclesPreview/IECoreCycles.cpp
@@ -474,7 +474,7 @@ bool init()
 	auto kernelFile = std::filesystem::path( cyclesRootValue ) / "source" / "kernel" / "types.h";
 	if( !std::filesystem::is_regular_file( kernelFile ) )
 	{
-		IECore::msg( IECore::Msg::Error, "IECoreCycles::init", fmt::format( "File \"{}\" not found", kernelFile ) );
+		IECore::msg( IECore::Msg::Error, "IECoreCycles::init", fmt::format( "File \"{}\" not found", kernelFile.string() ) );
 		return false;
 	}
 

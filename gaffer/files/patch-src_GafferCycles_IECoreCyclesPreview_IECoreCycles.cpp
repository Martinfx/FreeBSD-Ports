--- src/GafferCycles/IECoreCyclesPreview/IECoreCycles.cpp.orig	2026-05-27 19:02:41 UTC
+++ src/GafferCycles/IECoreCyclesPreview/IECoreCycles.cpp
@@ -469,7 +469,7 @@ bool init()
 	auto kernelFile = std::filesystem::path( cyclesRootValue ) / "source" / "kernel" / "types.h";
 	if( !std::filesystem::is_regular_file( kernelFile ) )
 	{
-		IECore::msg( IECore::Msg::Error, "IECoreCycles::init", fmt::format( "File \"{}\" not found", kernelFile ) );
+		IECore::msg( IECore::Msg::Error, "IECoreCycles::init", fmt::format( "File \"{}\" not found", kernelFile.string() ) );
 		return false;
 	}
 

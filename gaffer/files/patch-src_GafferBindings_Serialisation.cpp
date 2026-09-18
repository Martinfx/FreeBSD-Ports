--- src/GafferBindings/Serialisation.cpp.orig	2025-03-02 13:47:20 UTC
+++ src/GafferBindings/Serialisation.cpp
@@ -184,10 +184,10 @@ std::string Serialisation::result() const
 		const std::string formatString( "Gaffer.Metadata.registerValue( {}, \"{}\", {}, persistent=False )\n" );
 
 		result += "\n";
-		result += fmt::format( formatString, m_parentName, "serialiser:milestoneVersion", GAFFER_MILESTONE_VERSION );
-		result += fmt::format( formatString, m_parentName, "serialiser:majorVersion", GAFFER_MAJOR_VERSION );
-		result += fmt::format( formatString, m_parentName, "serialiser:minorVersion", GAFFER_MINOR_VERSION );
-		result += fmt::format( formatString, m_parentName, "serialiser:patchVersion", GAFFER_PATCH_VERSION );
+		result += fmt::format(fmt::runtime(formatString), m_parentName, "serialiser:milestoneVersion", GAFFER_MILESTONE_VERSION );
+		result += fmt::format(fmt::runtime(formatString), m_parentName, "serialiser:majorVersion", GAFFER_MAJOR_VERSION );
+		result += fmt::format(fmt::runtime(formatString), m_parentName, "serialiser:minorVersion", GAFFER_MINOR_VERSION );
+		result += fmt::format(fmt::runtime(formatString), m_parentName, "serialiser:patchVersion", GAFFER_PATCH_VERSION );
 	}
 
 	if( m_protectParentNamespace )

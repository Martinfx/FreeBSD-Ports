PORTNAME=	powershell
DISTVERSION=	7.4.2
CATEGORIES=	shells

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Microsoft's shell with support for .NET objects
WWW=		https://microsoft.com/PowerShell

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	aarch64 amd64

BUILD_DEPENDS=	dotnet:lang/dotnet
LIB_DEPENDS=	libinotify.so:devel/libinotify \
		libunwind.so:devel/libunwind

USES=			cmake ssl
USE_GITHUB=		yes
GH_ACCOUNT=		PowerShell
GH_PROJECT=		PowerShell PowerShell-Native:native
GH_TAGNAME=		v${DISTVERSION} v${PSNATIVEVERS}:native
CMAKE_SOURCE_PATH=	${WRKSRC}/src/libpsl-native

OPTIONS_DEFINE=		MODULES
OPTIONS_DEFAULT=	GSSAPI_BASE MODULES
OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT
OPTIONS_SUB=		yes
MODULES_DESC=		Bundle essential PowerShell modules
GSSAPI_BASE_USES=	gssapi
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_MIT_USES=	gssapi:mit
MODULES_RUN_DEPENDS=	terminfo-db>0:misc/terminfo-db
MODULES_VARS=		NUGET_GROUPS+=PWSH

DOTNET_ARCH=	${ARCH:S/amd64/x64/:S/aarch64/arm64/}
PSNATIVEVERS=	7.4.0
NUGET_GROUPS=	NUGET
NUPKG_NUGET=	DotNetAnalyzers.DocumentationAnalyzers:1.0.0-beta.59 \
		DotNetAnalyzers.DocumentationAnalyzers.Unstable:1.0.0.59 \
		JetBrains.Annotations:2021.2.0 \
		Json.More.Net:1.9.3 \
		JsonPointer.Net:3.0.3 \
		JsonSchema.Net:5.2.7 \
		Markdig.Signed:0.33.0 \
		Microsoft.ApplicationInsights:2.21.0 \
		Microsoft.Bcl.AsyncInterfaces:8.0.0 \
		Microsoft.CodeAnalysis.Analyzers:3.3.4 \
		Microsoft.CodeAnalysis.Common:4.9.2 \
		Microsoft.CodeAnalysis.CSharp:4.9.2 \
		Microsoft.Extensions.ObjectPool:8.0.4 \
		Microsoft.Management.Infrastructure:3.0.0 \
		Microsoft.Management.Infrastructure.Runtime.Unix:3.0.0 \
		Microsoft.Management.Infrastructure.Runtime.Win:3.0.0 \
		Microsoft.NETCore.Platforms:1.1.2 \
		Microsoft.PowerShell.MarkdownRender:7.2.1 \
		Microsoft.PowerShell.Native:7.4.0 \
		Microsoft.Security.Extensions:1.2.0 \
		Microsoft.Win32.Registry:4.7.0 \
		Microsoft.Win32.Registry.AccessControl:8.0.0 \
		Microsoft.Win32.SystemEvents:8.0.0 \
		Microsoft.Windows.Compatibility:8.0.4 \
		NETStandard.Library:2.0.3 \
		Newtonsoft.Json:13.0.3 \
		runtime.linux-arm.runtime.native.System.IO.Ports:8.0.0 \
		runtime.linux-arm64.runtime.native.System.IO.Ports:8.0.0 \
		runtime.linux-x64.runtime.native.System.IO.Ports:8.0.0 \
		runtime.native.System.Data.SqlClient.sni:4.7.0 \
		runtime.native.System.IO.Ports:8.0.0 \
		runtime.osx-arm64.runtime.native.System.IO.Ports:8.0.0 \
		runtime.osx-x64.runtime.native.System.IO.Ports:8.0.0 \
		runtime.win-arm64.runtime.native.System.Data.SqlClient.sni:4.4.0 \
		runtime.win-x64.runtime.native.System.Data.SqlClient.sni:4.4.0 \
		runtime.win-x86.runtime.native.System.Data.SqlClient.sni:4.4.0 \
		StyleCop.Analyzers:1.2.0-beta.556 \
		StyleCop.Analyzers.Unstable:1.2.0.556 \
		System.Buffers:4.5.1 \
		System.CodeDom:8.0.0 \
		System.Collections.Immutable:8.0.0 \
		System.ComponentModel.Composition:8.0.0 \
		System.ComponentModel.Composition.Registration:8.0.0 \
		System.Configuration.ConfigurationManager:8.0.0 \
		System.Data.Odbc:8.0.0 \
		System.Data.OleDb:8.0.0 \
		System.Data.SqlClient:4.8.6 \
		System.Diagnostics.DiagnosticSource:8.0.1 \
		System.Diagnostics.EventLog:8.0.0 \
		System.Diagnostics.PerformanceCounter:8.0.0 \
		System.DirectoryServices:8.0.0 \
		System.DirectoryServices.AccountManagement:8.0.0 \
		System.DirectoryServices.Protocols:8.0.0 \
		System.Drawing.Common:8.0.4 \
		System.Formats.Asn1:6.0.0 \
		System.IO.Packaging:8.0.0 \
		System.IO.Ports:8.0.0 \
		System.Management:8.0.0 \
		System.Memory:4.5.5 \
		System.Net.Http.WinHttpHandler:8.0.0 \
		System.Numerics.Vectors:4.4.0 \
		System.Numerics.Vectors:4.5.0 \
		System.Private.ServiceModel:4.10.3 \
		System.Reflection.Context:8.0.0 \
		System.Reflection.DispatchProxy:4.7.1 \
		System.Reflection.Metadata:8.0.0 \
		System.Runtime.Caching:8.0.0 \
		System.Runtime.CompilerServices.Unsafe:6.0.0 \
		System.Security.AccessControl:6.0.1 \
		System.Security.Cryptography.Pkcs:6.0.1 \
		System.Security.Cryptography.ProtectedData:8.0.0 \
		System.Security.Cryptography.Xml:6.0.1 \
		System.Security.Permissions:8.0.0 \
		System.Security.Principal.Windows:4.7.0 \
		System.ServiceModel.Duplex:4.10.3 \
		System.ServiceModel.Http:4.10.3 \
		System.ServiceModel.NetTcp:4.10.3 \
		System.ServiceModel.Primitives:4.10.3 \
		System.ServiceModel.Security:4.10.3 \
		System.ServiceModel.Syndication:8.0.0 \
		System.ServiceProcess.ServiceController:8.0.0 \
		System.Speech:8.0.0 \
		System.Text.Encoding.CodePages:7.0.0 \
		System.Text.Encoding.CodePages:8.0.0 \
		System.Text.Encodings.Web:6.0.0 \
		System.Text.Encodings.Web:8.0.0 \
		System.Text.Json:6.0.9 \
		System.Threading.AccessControl:4.7.0 \
		System.Threading.Tasks.Extensions:4.5.4 \
		System.Web.Services.Description:4.10.3 \
		System.Windows.Extensions:8.0.0
NUPKG_PWSH=	Microsoft.PowerShell.PSResourceGet:1.0.3 \
		PSReadLine:2.3.4 \
		PowerShellGet:3.0.23-beta23

PWSH_MOD_EXTRACT_ARGS=	-x "\[Content_Types\].xml" \
			-x "_*/*" \
			-x "package/*" \
			-x "*.txt" \
			-x "*.nuspec"

post-extract:
	${RM} -r ${WRKSRC}/src/libpsl-native
	${MV} ${WRKSRC_native}/src/libpsl-native ${WRKSRC}/src/libpsl-native
#	${MKDIR} ${WRKSRC}/src/Microsoft.PowerShell.SDK/obj
#	${CP} ${FILESDIR}/Microsoft.PowerShell.SDK.csproj.TypeCatalog.targets \
#		${WRKSRC}/src/Microsoft.PowerShell.SDK/obj

post-patch:
	${REINPLACE_CMD} -e 's|%%DISTDIR%%|${DISTDIR}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/nuget.config
	${REINPLACE_CMD} 's|%%DISTVERSION%%|${DISTVERSION}|' \
		${WRKSRC}/PowerShell.Common.props
	${REINPLACE_CMD} 's|%%DOTNET_ARCH%%|${DOTNET_ARCH}|g' \
		${WRKSRC}/src/ResGen/ResGen.csproj \
		${WRKSRC}/src/TypeCatalogGen/TypeCatalogGen.csproj \
		${WRKSRC}/src/powershell-unix/powershell-unix.csproj

post-build:
	cd ${WRKSRC}/src/ResGen && \
		dotnet restore --packages ${WRKDIR}/packages && \
		dotnet build --no-restore && \
		dotnet run --no-restore
	cd ${WRKSRC}/src/powershell-unix && \
		dotnet restore --packages ${WRKDIR}/packages
	cd ${WRKSRC}/src && dotnet msbuild \
		Microsoft.PowerShell.SDK/Microsoft.PowerShell.SDK.csproj \
		#/t:_GetDependencies /p:DesignTimeBuild=true \
		/p:DesignTimeBuild=true \
		/p:_DependencyFile=${WRKSRC}/src/TypeCatalogGen/powershell.inc \
		/nologo
	cd ${WRKSRC}/src/TypeCatalogGen && \
		dotnet restore --packages ${WRKDIR}/packages && \
		dotnet build --no-restore && \
		dotnet run --no-restore \
		../System.Management.Automation/CoreCLR/CorePsTypeCatalog.cs \
		powershell.inc
	cd ${WRKSRC}/src/powershell-unix && \
		dotnet publish --packages ${WRKDIR}/packages -c Release \
		-r freebsd-${DOTNET_ARCH} -o bin/publish \
		--sc -p:PublishReadyToRun=true
	${INSTALL_LIB} ${WRKSRC}/src/powershell-unix/libpsl-native.so \
		${WRKSRC}/src/powershell-unix/bin/publish

do-install:
	${CP} -r ${WRKSRC}/src/powershell-unix/bin/publish \
		${STAGEDIR}${PREFIX}/lib/powershell
	${LN} -s ../lib/powershell/pwsh ${STAGEDIR}${PREFIX}/bin

post-install-MODULES-on:
.for m in ${NUPKG_PWSH}
	${UNZIP_NATIVE_CMD} ${PWSH_MOD_EXTRACT_ARGS} \
		-d ${STAGEDIR}${PREFIX}/lib/powershell/Modules/${m:C/:.*//} \
		${DISTDIR}/nuget/${m:C/:.*//:tl}.${m:C/.*://:tl}.nupkg
.endfor

.include "nuget.mk"
.include <bsd.port.mk>

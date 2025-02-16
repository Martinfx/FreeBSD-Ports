PORTNAME=	powershell
DISTVERSION=	7.5.0-rc.1
CATEGORIES=	shells

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Microsoft's shell with support for .NET objects
WWW=		https://microsoft.com/PowerShell

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	aarch64 amd64

BUILD_DEPENDS=	dotnet>0:lang/dotnet
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
NUPKG_NUGET=	Humanizer.Core:2.14.1 \
		DotNetAnalyzers.DocumentationAnalyzers:1.0.0-beta.59 \
		DotNetAnalyzers.DocumentationAnalyzers.Unstable:1.0.0.59 \
		Microsoft.CodeAnalysis.CSharp:4.11.0 \
		JetBrains.Annotations:2021.2.0 \
		Json.More.Net:2.0.2 \
		JsonPointer.Net:5.0.2 \
		JsonSchema.Net:7.2.3 \
		Markdig.Signed:0.38.0 \
		Microsoft.ApplicationInsights:2.22.0 \
		Microsoft.Bcl.AsyncInterfaces:8.0.0 \
		Microsoft.CodeAnalysis.Analyzers:3.11.0 \
		Microsoft.CodeAnalysis.Common:4.11.0 \
		Microsoft.CodeAnalysis.CSharp:4.9.2 \
		Microsoft.Extensions.ObjectPool:8.0.11 \
		Microsoft.Management.Infrastructure:3.0.0 \
		Microsoft.Management.Infrastructure.Runtime.Unix:3.0.0 \
		Microsoft.Management.Infrastructure.Runtime.Win:3.0.0 \
		Microsoft.NETCore.Platforms:7.0.4 \
		Microsoft.PowerShell.MarkdownRender:7.2.1 \
		Microsoft.PowerShell.Native:7.4.0 \
		Microsoft.Security.Extensions:1.3.0 \
		Microsoft.Win32.Registry:5.0.0 \
		Microsoft.Win32.Registry.AccessControl:9.0.0 \
		Microsoft.Win32.SystemEvents:9.0.0 \
		Microsoft.Windows.Compatibility:9.0.0 \
		NETStandard.Library:2.0.3 \
		Newtonsoft.Json:13.0.3 \
		runtime.linux-arm.runtime.native.System.IO.Ports:9.0.0 \
		runtime.linux-arm64.runtime.native.System.IO.Ports:9.0.0 \
		runtime.linux-x64.runtime.native.System.IO.Ports:9.0.0 \
		runtime.linux-bionic-arm64.runtime.native.System.IO.Ports:9.0.0 \
		runtime.linux-bionic-x64.runtime.native.System.IO.Ports:9.0.0 \
		runtime.linux-musl-arm.runtime.native.System.IO.Ports:9.0.0 \
		runtime.linux-musl-arm64.runtime.native.System.IO.Ports:9.0.0 \
		runtime.linux-musl-x64.runtime.native.System.IO.Ports:9.0.0 \
		runtime.maccatalyst-arm64.runtime.native.System.IO.Ports:9.0.0 \
		runtime.maccatalyst-x64.runtime.native.System.IO.Ports:9.0.0 \
		runtime.native.System.Data.SqlClient.sni:4.7.0 \
		runtime.native.System.IO.Ports:9.0.0 \
		runtime.osx-arm64.runtime.native.System.IO.Ports:9.0.0 \
		runtime.osx-x64.runtime.native.System.IO.Ports:9.0.0 \
		runtime.win-arm64.runtime.native.System.Data.SqlClient.sni:4.4.0 \
		runtime.win-x64.runtime.native.System.Data.SqlClient.sni:4.4.0 \
		runtime.win-x86.runtime.native.System.Data.SqlClient.sni:4.4.0 \
		runtime.android-arm.runtime.native.System.IO.Ports:9.0.0 \
		runtime.android-arm64.runtime.native.System.IO.Ports:9.0.0 \
		runtime.android-x64.runtime.native.System.IO.Ports:9.0.0 \
		runtime.android-x86.runtime.native.System.IO.Ports:9.0.0 \
		StyleCop.Analyzers:1.2.0-beta.556 \
		StyleCop.Analyzers.Unstable:1.2.0.556 \
		System.Buffers:4.5.1 \
		System.CodeDom:9.0.0 \
		System.Collections.Immutable:8.0.0 \
		System.ComponentModel.Composition:9.0.0 \
		System.ComponentModel.Composition.Registration:9.0.0 \
		System.Configuration.ConfigurationManager:9.0.0 \
		System.Data.Odbc:9.0.0 \
		System.Data.OleDb:9.0.0 \
		System.Data.SqlClient:4.8.6 \
		System.Diagnostics.DiagnosticSource:9.0.0 \
		System.Diagnostics.EventLog:9.0.0 \
		System.Diagnostics.PerformanceCounter:9.0.0 \
		System.DirectoryServices:9.0.0 \
		System.DirectoryServices.AccountManagement:9.0.0 \
		System.DirectoryServices.Protocols:9.0.0 \
		System.Drawing.Common:9.0.0 \
		System.Formats.Asn1:8.0.0 \
		System.IO.Packaging:9.0.0 \
		System.IO.Ports:9.0.0 \
		System.Management:9.0.0 \
		System.Memory:4.5.5 \
		System.Net.Http.WinHttpHandler:9.0.0 \
		System.Numerics.Vectors:4.4.0 \
		System.Numerics.Vectors:4.5.0 \
		System.Private.ServiceModel:4.10.3 \
		System.Reflection.Context:9.0.0 \
		System.Reflection.DispatchProxy:4.7.1 \
		System.Reflection.Metadata:8.0.1 \
		System.Runtime.Caching:9.0.0 \
		System.Runtime.CompilerServices.Unsafe:6.0.0 \
		System.Security.AccessControl:6.0.1 \
		System.Security.Cryptography.Pkcs:9.0.0 \
		System.Security.Cryptography.ProtectedData:9.0.0 \
		System.Security.Cryptography.Xml:9.0.0 \
		System.Security.Permissions:9.0.0 \
		System.Security.Principal.Windows:5.0.0 \
		System.ServiceModel.Duplex:4.10.3 \
		System.ServiceModel.Http:4.10.3 \
		System.ServiceModel.NetTcp:4.10.3 \
		System.ServiceModel.Primitives:4.10.3 \
		System.ServiceModel.Security:4.10.3 \
		System.ServiceModel.Syndication:9.0.0 \
		System.ServiceProcess.ServiceController:9.0.0 \
		System.Speech:9.0.0 \
		System.Text.Encoding.CodePages:9.0.0 \
		System.Text.Encoding.CodePages:8.0.0 \
		System.Text.Encodings.Web:9.0.0 \
		System.Text.Encodings.Web:8.0.0 \
		System.Text.Json:6.0.9 \
		System.Threading.AccessControl:9.0.0 \
		System.Threading.Tasks.Extensions:4.5.4 \
		System.Web.Services.Description:8.0.0 \
		System.Windows.Extensions:9.0.0
NUPKG_PWSH=	Microsoft.PowerShell.PSResourceGet:1.0.3 \
		PSReadLine:2.3.4 \
		PowerShellGet:3.0.23-beta23

PWSH_MOD_EXTRACT_ARGS=	-x "\[Content_Types\].xml" \
			-x "_*/*" \
			-x "package/*" \
			-x "*.txt" \
			-x "*.nuspec"

DOTNET_ENV=	DOTNET_CLI_HOME=/tmp

post-extract:
	${RM} -r ${WRKSRC}/src/libpsl-native
	${MV} ${WRKSRC_native}/src/libpsl-native ${WRKSRC}/src/libpsl-native
	${MKDIR} ${WRKSRC}/src/Microsoft.PowerShell.SDK/obj
	${CP} ${FILESDIR}/Microsoft.PowerShell.SDK.csproj.TypeCatalog.targets \
		${WRKSRC}/src/Microsoft.PowerShell.SDK/obj

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
	cd ${WRKSRC}/src/ResGen && ${SETENV} ${DOTNET_ENV} \
		dotnet restore --packages ${WRKDIR}/packages && \
		${SETENV} ${DOTNET_ENV} dotnet build --no-restore && \
		${SETENV} ${DOTNET_ENV} dotnet run --no-restore
	cd ${WRKSRC}/src/powershell-unix && \
		${SETENV} ${DOTNET_ENV} dotnet restore --packages ${WRKDIR}/packages
	cd ${WRKSRC}/src && ${SETENV} ${DOTNET_ENV} dotnet msbuild \
		Microsoft.PowerShell.SDK/Microsoft.PowerShell.SDK.csproj \
		/t:_GetDependencies \
		/p:DesignTimeBuild=true \
		/p:_DependencyFile=${WRKSRC}/src/TypeCatalogGen/powershell.inc \
		/nologo
	cd ${WRKSRC}/src/TypeCatalogGen && \
		${SETENV} ${DOTNET_ENV} dotnet restore --packages ${WRKDIR}/packages && \
		${SETENV} ${DOTNET_ENV} dotnet build --no-restore && \
		${SETENV} ${DOTNET_ENV} dotnet run --no-restore \
		../System.Management.Automation/CoreCLR/CorePsTypeCatalog.cs \
		powershell.inc
	cd ${WRKSRC}/src/powershell-unix && \
		${SETENV} ${DOTNET_ENV} dotnet publish --packages ${WRKDIR}/packages -c Release \
		-r freebsd.14-${DOTNET_ARCH} -o bin/publish \
		--sc -p:PublishReadyToRun=false
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
--- third_party/microprofile/microprofile.h.orig
+++ third_party/microprofile/microprofile.h
@@ -242,7 +242,7 @@ typedef uint32_t MicroProfileThreadIdType;
 #define MP_GETCURRENTPROCESSID() GetCurrentProcessId()
 typedef uint32_t MicroProfileProcessIdType;
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #include <unistd.h>
 #include <time.h>
 inline int64_t MicroProfileTicksPerSecondCpu()
@@ -1049,7 +1049,7 @@ inline void MicroProfileThreadJoin(MicroProfileThread* pThread)
 #define MP_INVALID_SOCKET(f) (f == INVALID_SOCKET)
 #endif
 
-#if defined(__APPLE__) || defined(__linux__)
+#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__)
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
@@ -3537,7 +3537,7 @@ void MicroProfileWebServerHello(int nPort)
 	uint32_t nInterfaces = 0;
 
 	// getifaddrs hangs on some versions of Android so disable IP address scanning
-#if (defined(__APPLE__) || defined(__linux__)) && !defined(__ANDROID__)
+#if (defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__)
 	struct ifaddrs* ifal;
 	if(getifaddrs(&ifal) == 0 && ifal)
 	{

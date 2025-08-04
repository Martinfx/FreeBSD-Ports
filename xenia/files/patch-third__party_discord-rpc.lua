--- third_party/discord-rpc.lua.orig	2025-03-09 08:00:42 UTC
+++ third_party/discord-rpc.lua
@@ -21,7 +21,7 @@ project("discord-rpc")
     "discord-rpc/src/serialization.cpp",
     "discord-rpc/src/serialization.h"
   })
-  filter("platforms:Linux")
+  filter("platforms:Linux or platforms:FreeBSD")
     files({
       "discord-rpc/src/connection_unix.cpp",
       "discord-rpc/src/discord_register_linux.cpp"

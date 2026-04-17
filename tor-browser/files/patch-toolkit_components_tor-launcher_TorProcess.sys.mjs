--- toolkit/components/tor-launcher/TorProcess.sys.mjs.orig	2026-03-31 18:04:56 UTC
+++ toolkit/components/tor-launcher/TorProcess.sys.mjs
@@ -253,6 +253,7 @@ export class TorProcess {
     }
 
     this.#args = [];
+    this.#args.push("--ignore-missing-torrc");
     this.#args.push("-f", torrcFile.path);
     this.#args.push("DataDirectory", this.#dataDir.path);
     this.#args.push("ClientOnionAuthDir", onionAuthDir.path);
@@ -275,7 +276,7 @@ export class TorProcess {
       false
     );
     if (torAppDataDir) {
-      const geoipFile = torAppDataDir.clone();
+      const geoipFile = lazy.TorLauncherUtil.getTorFile("geoip", false);
       geoipFile.append("geoip");
       if (geoipFile.exists()) {
         this.#args.push("GeoIPFile", geoipFile.path);
@@ -284,7 +285,7 @@ export class TorProcess {
           "GeoIP file not found, the circuit display will not show locations."
         );
       }
-      const geoip6File = torAppDataDir.clone();
+      const geoip6File = lazy.TorLauncherUtil.getTorFile("geoip6", false);
       geoip6File.append("geoip6");
       if (geoip6File.exists()) {
         this.#args.push("GeoIPv6File", geoip6File.path);

--- include/configs/mt8516.h.orig
+++ include/configs/mt8516.h
@@ -18,10 +18,15 @@
 #include <config_distro_bootcmd.h>
 
 #define BOOT_TARGET_DEVICES(func) \
-	func(MMC, mmc, 0)
+	func(MMC, mmc, 0) \
+	func(DHCP, dhcp, na)
 
 #define CFG_EXTRA_ENV_SETTINGS \
 	"scriptaddr=0x40000000\0" \
+	"pxefile_addr_r=0x41000000\0" \
+	"fdt_addr_r=0x42000000\0" \
+	"kernel_addr_r=0x44000000\0" \
+	"ramdisk_addr_r=0x50000000\0" \
 	BOOTENV
 
 #endif

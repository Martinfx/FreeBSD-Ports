--- plugins/org.jkiss.dbeaver.launcher/src/org/jkiss/dbeaver/launcher/Constants.java.orig	2025-07-31 08:32:56 UTC
+++ plugins/org.jkiss.dbeaver.launcher/src/org/jkiss/dbeaver/launcher/Constants.java
@@ -30,6 +30,7 @@ public class Constants {
     public static final String INTERNAL_OS_OS400 = "OS/400"; //$NON-NLS-1$
     public static final String INTERNAL_OS_OS390 = "OS/390"; //$NON-NLS-1$
     public static final String INTERNAL_OS_ZOS = "z/OS"; //$NON-NLS-1$
+    public static final String INTERNAL_OS_FREEBSD = "FreeBSD"; //$NON-NLS-1$
 
     public static final String ARCH_X86 = "x86";//$NON-NLS-1$
     public static final String ARCH_X86_64 = "x86_64";//$NON-NLS-1$
@@ -47,6 +48,12 @@ public class Constants {
     public static final String OS_LINUX = "linux";//$NON-NLS-1$
 
     /**
+     * Constant string (value "freebsd") indicating the platform is running on a
+     * FreeBSD-based operating system.
+     */
+    public static final String OS_FREEBSD = "freebsd";//$NON-NLS-1$
+
+    /**
      * Constant string (value "aix") indicating the platform is running on an
      * AIX-based operating system.
      */
@@ -69,7 +76,6 @@ public class Constants {
      * QNX-based operating system.
      */
     public static final String OS_QNX = "qnx";//$NON-NLS-1$
-
     /**
      * Constant string (value "macosx") indicating the platform is running on a
      * Mac OS X operating system.

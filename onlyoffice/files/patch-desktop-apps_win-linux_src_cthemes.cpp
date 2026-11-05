--- desktop-apps/win-linux/src/cthemes.cpp.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/cthemes.cpp
@@ -35,10 +35,14 @@
 
 
 #include "cthemes.h"
-#ifdef Q_OS_LINUX
+#if (defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)) || defined(Q_OS_FREEBSD)
+// GLib has struct members called "signals", a Qt keyword macro
+# pragma push_macro("signals")
+# undef signals
 # include <gtk/gtk.h>
 # include <gio/gio.h>
 # include <glib.h>
+# pragma pop_macro("signals")
 # include "cascapplicationmanagerwrapper.h"
 #endif
 #include "defines.h"
@@ -219,7 +223,7 @@
     return Utils::getAppCommonPath() + "/uithemes";
 }
 
-#ifdef __linux__
+#if (defined(__linux__) || defined(__FreeBSD__)) || defined(__FreeBSD__)
 static const char *XDG_DSK_DBUS_SENDER = "org.freedesktop.portal.Desktop",
                   *XDG_STN_DBUS_ITF    = "org.freedesktop.portal.Settings",
                   *XDG_DSK_DBUS_PATH   = "/org/freedesktop/portal/desktop";
@@ -465,7 +469,7 @@
             current->m_priv->is_system = true;
         }
 
-#ifdef __linux__
+#if (defined(__linux__) || defined(__FreeBSD__)) || defined(__FreeBSD__)
         applyGtkTheme(current->isDark());
 #endif
     }
@@ -477,7 +481,7 @@
             current = nullptr;
         }
 
-#ifdef __linux__
+#if (defined(__linux__) || defined(__FreeBSD__)) || defined(__FreeBSD__)
         if (dbus_conn) {
             if (settings_signal != 0)
                 g_dbus_connection_signal_unsubscribe(dbus_conn, settings_signal);
@@ -608,7 +612,7 @@
     CTheme * current = nullptr;
     CTheme * dark = nullptr;
     CTheme * light = nullptr;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     GDBusConnection *dbus_conn = nullptr;
     guint settings_signal = 0;
 #endif
@@ -832,7 +836,7 @@
         // if ( _reg_user.contains(REGISTRY_THEME_KEY_7_2) )
         //     _reg_user.remove(REGISTRY_THEME_KEY_7_2);
 
-#ifdef __linux__
+#if (defined(__linux__) || defined(__FreeBSD__)) || defined(__FreeBSD__)
         applyGtkTheme(m_priv->current->isDark());
 #endif
     }

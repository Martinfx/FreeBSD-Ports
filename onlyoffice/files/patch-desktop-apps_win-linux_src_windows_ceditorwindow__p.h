--- desktop-apps/win-linux/src/windows/ceditorwindow_p.h.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/windows/ceditorwindow_p.h
@@ -74,7 +74,7 @@
     case AscEditorType::etDraw: c = theme.value(CTheme::ColorRole::ecrTabDrawActive); break;
     }
     QString g_css(Utils::readStylesheets(":/styles/editor.qss"));
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     g_css.append(Utils::readStylesheets(":styles/editor_unix.qss"));
 #endif
     return g_css.arg(QString::fromStdWString(c), GetColorQValueByRole(ecrTextNormal), GetColorQValueByRole(ecrTextPretty));
@@ -537,7 +537,7 @@
             window->m_css = prepare_editor_css(editor_type, GetCurrentTheme());
             QString css(AscAppManager::getWindowStylesheets(window->m_dpiRatio));
             css.append(window->m_css);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
             css.append(Utils::readStylesheets(":styles/styles_unix.qss"));
 #endif
             window->m_pMainPanel->setStyleSheet(css);

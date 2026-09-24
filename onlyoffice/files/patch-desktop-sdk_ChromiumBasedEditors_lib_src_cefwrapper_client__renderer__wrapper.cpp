--- desktop-sdk/ChromiumBasedEditors/lib/src/cefwrapper/client_renderer_wrapper.cpp.orig	2026-09-24 21:58:50 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/cefwrapper/client_renderer_wrapper.cpp
@@ -849,7 +849,7 @@ namespace asc_client_renderer
 
 		inline void CallInEditorFrame(CefRefPtr<CefBrowser>& browser, const std::string& sCode)
 		{
-			CefRefPtr<CefFrame> frame = browser->GetFrame("frameEditor");
+			CefRefPtr<CefFrame> frame = NSCefCompat::GetFrame(browser, "frameEditor");
 			if (!frame)
 				frame = browser->GetMainFrame();
 
@@ -1194,7 +1194,7 @@ else \n\
 					{
 						CefRefPtr<CefBrowser> browser = CefV8Context::GetCurrentContext()->GetBrowser();
 						CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("load_js");
-						int64 frameId = CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier();
+						int64 frameId = NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame());
 						message->GetArgumentList()->SetString(0, GetFullUrl2(strUrl, CefV8Context::GetCurrentContext()->GetFrame()->GetURL().ToWString()));
 						message->GetArgumentList()->SetString(1, strPath);
 						NSArgumentList::SetInt64(message->GetArgumentList(), 2, frameId);
@@ -1294,7 +1294,7 @@ else \n\
 			}
 			else if (name == "SpellCheck")
 			{
-				int64 frameId = CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier();
+				int64 frameId = NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame());
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("spell_check_task");
 				message->GetArgumentList()->SetInt(0, (int)m_nEditorId);
 				message->GetArgumentList()->SetString(1, arguments[0]->GetStringValue());
@@ -2510,7 +2510,7 @@ window.AscDesktopEditor.LocalFileTemplat
 
 				// send to editor
 				CefRefPtr<CefBrowser> browser = CefV8Context::GetCurrentContext()->GetBrowser();
-				CefRefPtr<CefFrame> _frame = browser->GetFrame("frameEditor");
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, "frameEditor");
 				if (!_frame)
 					_frame = browser->GetMainFrame();
 
@@ -2536,7 +2536,7 @@ window.AscDesktopEditor.LocalFileTemplat
 
 				// send to editor
 				CefRefPtr<CefBrowser> browser = CefV8Context::GetCurrentContext()->GetBrowser();
-				CefRefPtr<CefFrame> _frame = browser->GetFrame("frameEditor");
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, "frameEditor");
 				if (!_frame)
 					_frame = browser->GetMainFrame();
 
@@ -2610,7 +2610,7 @@ window.AscDesktopEditor.LocalFileTemplat
 			{
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("on_open_filename_dialog");
 				message->GetArgumentList()->SetString(0, arguments[0]->GetStringValue());
-				message->GetArgumentList()->SetString(1, std::to_string(CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier()));
+				message->GetArgumentList()->SetString(1, std::to_string(NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame())));
 				if (arguments.size() > 1)
 					message->GetArgumentList()->SetBool(2, arguments[1]->GetBoolValue());
 				SEND_MESSAGE_TO_BROWSER_PROCESS(message);
@@ -2706,7 +2706,7 @@ window.AscDesktopEditor.LocalFileTemplat
 			{
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("send_system_message");
 
-				int64 frameID = CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier();
+				int64 frameID = NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame());
 
 				message->GetArgumentList()->SetString(0, arguments[0]->GetStringValue());
 				message->GetArgumentList()->SetString(1, std::to_string(frameID));
@@ -2719,7 +2719,7 @@ window.AscDesktopEditor.LocalFileTemplat
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("file_get_hash");
 				message->GetArgumentList()->SetString(0, arguments[0]->GetStringValue());
 				message->GetArgumentList()->SetString(1, (arguments.size() > 1) ? arguments[1]->GetStringValue() : "sha-256");
-				message->GetArgumentList()->SetString(2, std::to_string(CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier()));
+				message->GetArgumentList()->SetString(2, std::to_string(NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame())));
 				SEND_MESSAGE_TO_BROWSER_PROCESS(message);
 				return true;
 			}
@@ -2786,7 +2786,7 @@ window.AscDesktopEditor.LocalFileTemplat
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("preload_crypto_image");
 				message->GetArgumentList()->SetString(0, arguments[0]->GetStringValue());
 				message->GetArgumentList()->SetString(1, arguments[1]->GetStringValue());
-				NSArgumentList::SetInt64(message->GetArgumentList(), 2, CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier());
+				NSArgumentList::SetInt64(message->GetArgumentList(), 2, NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame()));
 				SEND_MESSAGE_TO_BROWSER_PROCESS(message);
 				return true;
 			}
@@ -2851,7 +2851,7 @@ window.AscDesktopEditor.LocalFileTemplat
 				int nIndex = 0;
 
 				message->GetArgumentList()->SetInt(nIndex++, nParams);
-				NSArgumentList::SetInt64(message->GetArgumentList(), nIndex++, CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier());
+				NSArgumentList::SetInt64(message->GetArgumentList(), nIndex++, NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame()));
 
 				for (int i = 0; i < nCount; ++i)
 				{
@@ -2893,7 +2893,7 @@ window.AscDesktopEditor.LocalFileTemplat
 				message->GetArgumentList()->SetString(0, arguments[0]->GetStringValue());
 				message->GetArgumentList()->SetInt(1, arguments[1]->GetIntValue());
 				message->GetArgumentList()->SetBool(2, (arguments.size() > 2) ? arguments[2]->GetBoolValue() : false);
-				NSArgumentList::SetInt64(message->GetArgumentList(), 3, CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier());
+				NSArgumentList::SetInt64(message->GetArgumentList(), 3, NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame()));
 				SEND_MESSAGE_TO_BROWSER_PROCESS(message);
 				return true;
 			}
@@ -2951,7 +2951,7 @@ window.AscDesktopEditor.LocalFileTemplat
 			else if (name == "_GetAdvancedEncryptedData")
 			{
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("get_advanced_encrypted_data");
-				NSArgumentList::SetInt64(message->GetArgumentList(), 0, CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier());
+				NSArgumentList::SetInt64(message->GetArgumentList(), 0, NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame()));
 				message->GetArgumentList()->SetString(1, arguments[0]->GetStringValue());
 				SEND_MESSAGE_TO_BROWSER_PROCESS(message);
 				return true;
@@ -2959,7 +2959,7 @@ window.AscDesktopEditor.LocalFileTemplat
 			else if (name == "_SetAdvancedEncryptedData")
 			{
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("set_advanced_encrypted_data");
-				NSArgumentList::SetInt64(message->GetArgumentList(), 0, CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier());
+				NSArgumentList::SetInt64(message->GetArgumentList(), 0, NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame()));
 				message->GetArgumentList()->SetString(1, arguments[0]->GetStringValue());
 				message->GetArgumentList()->SetString(2, arguments[1]->GetStringValue());
 				SEND_MESSAGE_TO_BROWSER_PROCESS(message);
@@ -3275,7 +3275,7 @@ window.AscDesktopEditor.LocalFileTemplat
 			}
 			else if (name == "SendByMail")
 			{
-				CefRefPtr<CefFrame> _frame = CefV8Context::GetCurrentContext()->GetBrowser()->GetFrame("frameEditor");
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(CefV8Context::GetCurrentContext()->GetBrowser(), "frameEditor");
 				if (!_frame)
 					return true;
 
@@ -3362,7 +3362,7 @@ if (window.onSystemMessage2) window.onSy
 
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("cloud_crypto_upload");
 				message->GetArgumentList()->SetBool(0, bIsNeedRemoveAfterUse);
-				NSArgumentList::SetInt64(message->GetArgumentList(), 1, CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier());
+				NSArgumentList::SetInt64(message->GetArgumentList(), 1, NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame()));
 				message->GetArgumentList()->SetInt(2, nCount);
 				for (int i = 0; i < nCount; ++i)
 					message->GetArgumentList()->SetString(3 + i, arguments[0]->GetValue(i)->GetStringValue());
@@ -3418,7 +3418,7 @@ if (window.onSystemMessage2) window.onSy
 			{
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("on_save_filename_dialog");
 				message->GetArgumentList()->SetString(0, arguments[0]->GetStringValue());
-				message->GetArgumentList()->SetString(1, std::to_string(CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier()));
+				message->GetArgumentList()->SetString(1, std::to_string(NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame())));
 				SEND_MESSAGE_TO_BROWSER_PROCESS(message);
 				return true;
 			}
@@ -3636,7 +3636,7 @@ if (window.onSystemMessage2) window.onSy
 			}
 			else if (name == "GetFrameId")
 			{
-				int64 frameID = CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier();
+				int64 frameID = NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame());
 				uint64 uframeID = (uint64)frameID;
 				std::string sId = std::to_string(uframeID);
 				retval = CefV8Value::CreateString(sId);
@@ -3647,7 +3647,7 @@ if (window.onSystemMessage2) window.onSy
 				std::string sId = arguments[0]->GetStringValue().ToString();
 				std::string sCode = arguments[1]->GetStringValue().ToString();
 				int64 frameId = (int64)(std::stoull(sId));
-				CefRefPtr<CefFrame> frame = CefV8Context::GetCurrentContext()->GetBrowser()->GetFrame(frameId);
+				CefRefPtr<CefFrame> frame = NSCefCompat::GetFrame(CefV8Context::GetCurrentContext()->GetBrowser(), frameId);
 				if (frame)
 					frame->ExecuteJavaScript(sCode, frame->GetURL(), 0);
 				return true;
@@ -4052,7 +4052,7 @@ window.AscDesktopEditor.CallInFrame(\""
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("convert_file");
 				message->GetArgumentList()->SetString(0, arguments[0]->GetStringValue());
 				message->GetArgumentList()->SetInt(1, arguments[1]->GetIntValue());
-				NSArgumentList::SetInt64(message->GetArgumentList(), 2, CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier());
+				NSArgumentList::SetInt64(message->GetArgumentList(), 2, NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame()));
 
 				SEND_MESSAGE_TO_BROWSER_PROCESS(message);
 				return true;
@@ -4115,7 +4115,7 @@ window.AscDesktopEditor.CallInFrame(\""
 
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("send_simple_request");
 
-				NSArgumentList::SetInt64(message->GetArgumentList(), 0, CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier());
+				NSArgumentList::SetInt64(message->GetArgumentList(), 0, NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame()));
 				message->GetArgumentList()->SetInt(1, nCounter);
 				message->GetArgumentList()->SetString(2, sUrl);
 				message->GetArgumentList()->SetString(3, sMethod);
@@ -5384,11 +5384,11 @@ return this.split(str).join(newStr);\
 				std::string sCode = "window[\"asc_current_keyboard_layout\"] = " + sLayout + ";";
 
 				std::vector<int64> ids;
-				browser->GetFrameIdentifiers(ids);
+				NSCefCompat::GetFrameIdentifiers(browser, ids);
 
 				for (std::vector<int64>::iterator i = ids.begin(); i != ids.end(); i++)
 				{
-					CefRefPtr<CefFrame> _frame = browser->GetFrame(*i);
+					CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, *i);
 					_frame->ExecuteJavaScript(sCode, _frame->GetURL(), 0);
 				}
 
@@ -5432,7 +5432,7 @@ return this.split(str).join(newStr);\
 			else if (sMessageName == "spell_check_response")
 			{
 				int64 nFrameId = NSArgumentList::GetInt64(message->GetArgumentList(), 1);
-				CefRefPtr<CefFrame> _frame = browser->GetFrame(nFrameId);
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, nFrameId);
 				if (_frame)
 				{
 					std::string sCode = "window[\"asc_nativeOnSpellCheck\"](" + message->GetArgumentList()->GetString(0).ToString() + ");";
@@ -5514,7 +5514,7 @@ else if (window.editor) window.editor.as
 			else if (sMessageName == "on_load_js")
 			{
 				int64 frameId = NSArgumentList::GetInt64(message->GetArgumentList(), 2);
-				CefRefPtr<CefFrame> _frame = browser->GetFrame(frameId);
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, frameId);
 				if (_frame)
 				{
 					std::wstring sFilePath = message->GetArgumentList()->GetString(0).ToWString();
@@ -5797,7 +5797,7 @@ else if (window.editor) window.editor.as
 				CefRefPtr<CefFrame> _frame = browser->GetMainFrame();
 				if (!sFrameName.empty())
 				{
-					_frame = browser->GetFrame(sFrameName);
+					_frame = NSCefCompat::GetFrame(browser, sFrameName);
 				}
 
 				if (!_frame)
@@ -5939,7 +5939,7 @@ else if (window.editor) window.editor.as
 				else
 				{
 					int64 nId = (int64)std::stoll(sId);
-					_frame = browser->GetFrame(nId);
+					_frame = NSCefCompat::GetFrame(browser, nId);
 				}
 				bool bIsMulti = message->GetArgumentList()->GetBool(1);
 
@@ -5990,7 +5990,7 @@ else if (window.editor) window.editor.as
 				else
 				{
 					int64 nId = (int64)std::stoll(sId);
-					_frame = browser->GetFrame(nId);
+					_frame = NSCefCompat::GetFrame(browser, nId);
 				}
 
 				if (_frame)
@@ -6078,7 +6078,7 @@ _editor && _editor.local_sendEvent && _e
 			else if (sMessageName == "file_get_hash_callback")
 			{
 				int64 frameID = (int64)std::stoll(message->GetArgumentList()->GetString(1).ToString());
-				CefRefPtr<CefFrame> _frame = browser->GetFrame(frameID);
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, frameID);
 
 				if (_frame)
 				{
@@ -6101,12 +6101,12 @@ _editor && _editor.local_sendEvent && _e
 				{
 					// main view
 					std::vector<int64> identifiers;
-					browser->GetFrameIdentifiers(identifiers);
+					NSCefCompat::GetFrameIdentifiers(browser, identifiers);
 
 					for (std::vector<int64>::iterator i = identifiers.begin(); i != identifiers.end(); i++)
 					{
 						int64 k = *i;
-						CefRefPtr<CefFrame> frame = browser->GetFrame(k);
+						CefRefPtr<CefFrame> frame = NSCefCompat::GetFrame(browser, k);
 
 						if (frame && (frame->GetName().ToString().find("system_asc") == 0))
 						{
@@ -6135,7 +6135,7 @@ delete window.AscDesktopEditor.isSendSys
 				else
 				{
 					int64 frameID = (int64)std::stoll(message->GetArgumentList()->GetString(1).ToString());
-					CefRefPtr<CefFrame> _frame = browser->GetFrame(frameID);
+					CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, frameID);
 
 					if (_frame)
 					{
@@ -6155,12 +6155,12 @@ catch (err) {}\n\
 					if (true)
 					{
 						std::vector<int64> identifiers;
-						browser->GetFrameIdentifiers(identifiers);
+						NSCefCompat::GetFrameIdentifiers(browser, identifiers);
 
 						for (std::vector<int64>::iterator i = identifiers.begin(); i != identifiers.end(); i++)
 						{
 							int64 k = *i;
-							CefRefPtr<CefFrame> _frameOP = browser->GetFrame(k);
+							CefRefPtr<CefFrame> _frameOP = NSCefCompat::GetFrame(browser, k);
 
 							if (_frameOP && (k != frameID) && (_frameOP->GetName().ToString().find("iframe_asc.{") == 0))
 							{
@@ -6277,7 +6277,7 @@ window.AscDesktopEditor.openFileCryptCal
 					int64 nFrameId = NSArgumentList::GetInt64(message->GetArgumentList(), 1);
 					if (0 != nFrameId)
 					{
-						CefRefPtr<CefFrame> _frameID = browser->GetFrame(nFrameId);
+						CefRefPtr<CefFrame> _frameID = NSCefCompat::GetFrame(browser, nFrameId);
 						if (_frameID)
 							_frame = _frameID;
 					}
@@ -6344,7 +6344,7 @@ delete window[\"crypto_images_map\"][_ur
 				int nIndex = 0;
 				int64 nFrameId = NSArgumentList::GetInt64(message->GetArgumentList(), nIndex++);
 
-				CefRefPtr<CefFrame> _frame = browser->GetFrame(nFrameId);
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, nFrameId);
 				if (!_frame)
 					_frame = GetEditorFrame(browser);
 
@@ -6374,7 +6374,7 @@ delete window[\"crypto_images_map\"][_ur
 				int nError = message->GetArgumentList()->GetInt(0);
 				int64 nFrameId = NSArgumentList::GetInt64(message->GetArgumentList(), 1);
 
-				CefRefPtr<CefFrame> _frame = browser->GetFrame(nFrameId);
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, nFrameId);
 				if (_frame)
 					_frame->ExecuteJavaScript(
 						"(function() { if (!window.on_set_crypto_mode) return; window.on_set_crypto_mode(" + std::to_string(nError) + "); delete window.on_set_crypto_mode; })();", _frame->GetURL(),
@@ -6386,7 +6386,7 @@ delete window[\"crypto_images_map\"][_ur
 				std::string sRet = message->GetArgumentList()->GetString(1);
 				NSStringUtils::string_replaceA(sRet, "\\", "\\\\");
 
-				CefRefPtr<CefFrame> _frame = browser->GetFrame(nFrameId);
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, nFrameId);
 				if (_frame)
 					_frame->ExecuteJavaScript(
 						"(function() { if (!window.on_get_advanced_encrypted_data) return; window.on_get_advanced_encrypted_data(\"" + sRet +
@@ -6399,7 +6399,7 @@ delete window[\"crypto_images_map\"][_ur
 				std::string sRet = message->GetArgumentList()->GetString(1);
 				NSStringUtils::string_replaceA(sRet, "\\", "\\\\");
 
-				CefRefPtr<CefFrame> _frame = browser->GetFrame(nFrameId);
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, nFrameId);
 				if (_frame)
 					_frame->ExecuteJavaScript(
 						"(function() { if (!window.on_set_advanced_encrypted_data) return; window.on_set_advanced_encrypted_data(\"" + sRet +
@@ -6447,11 +6447,11 @@ delete window[\"crypto_images_map\"][_ur
 				((wchar_t*)sCode.c_str())[sCode.length() - 1] = ']';
 
 				std::vector<int64> arFramesIds;
-				browser->GetFrameIdentifiers(arFramesIds);
+				NSCefCompat::GetFrameIdentifiers(browser, arFramesIds);
 
 				for (std::vector<int64>::iterator i = arFramesIds.begin(); i != arFramesIds.end(); i++)
 				{
-					CefRefPtr<CefFrame> _frame = browser->GetFrame(*i);
+					CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, *i);
 					if (_frame)
 						_frame->ExecuteJavaScript(L"window.AscDesktopEditor.SetDropFiles(" + sCode + L");", _frame->GetURL(), 0);
 				}
@@ -6461,11 +6461,11 @@ delete window[\"crypto_images_map\"][_ur
 			else if (sMessageName == "clear_drop_files")
 			{
 				std::vector<int64> arFramesIds;
-				browser->GetFrameIdentifiers(arFramesIds);
+				NSCefCompat::GetFrameIdentifiers(browser, arFramesIds);
 
 				for (std::vector<int64>::iterator i = arFramesIds.begin(); i != arFramesIds.end(); i++)
 				{
-					CefRefPtr<CefFrame> _frame = browser->GetFrame(*i);
+					CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, *i);
 					if (_frame)
 						_frame->ExecuteJavaScript(L"window.AscDesktopEditor.ClearDropFiles();", _frame->GetURL(), 0);
 				}
@@ -6479,7 +6479,7 @@ delete window[\"crypto_images_map\"][_ur
 				NSStringUtils::string_replaceA(sFolder, "\\", "\\\\");
 				NSStringUtils::string_replaceA(sFolder, "\"", "\\\"");
 
-				CefRefPtr<CefFrame> _frame = browser->GetFrame(nFrameId);
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, nFrameId);
 				if (!_frame)
 					return true;
 
@@ -6501,7 +6501,7 @@ delete window[\"crypto_images_map\"][_ur
 	private:
 		CefRefPtr<CefFrame> GetEditorFrame(CefRefPtr<CefBrowser> browser)
 		{
-			CefRefPtr<CefFrame> _frame = browser->GetFrame("frameEditor");
+			CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, "frameEditor");
 			if (_frame)
 				return _frame;
 			return browser->GetMainFrame();

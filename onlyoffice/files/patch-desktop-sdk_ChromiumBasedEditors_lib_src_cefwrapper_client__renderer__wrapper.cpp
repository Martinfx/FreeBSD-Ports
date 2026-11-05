--- desktop-sdk/ChromiumBasedEditors/lib/src/cefwrapper/client_renderer_wrapper.cpp.orig	2026-11-05 00:00:00 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/cefwrapper/client_renderer_wrapper.cpp
@@ -802,8 +802,15 @@
 						for (DWORD i = 0; i < dwFileLen; ++i)
 							retval->SetValue(i, CefV8Value::CreateInt(pData[i]));
 #else
+#ifdef CEF_VERSION_ABOVE_128
+						// With the V8 sandbox (on in newer CEF) an ArrayBuffer cannot use
+						// memory from outside, CreateArrayBuffer fails: copy the data
+						retval = CefV8Value::CreateArrayBufferWithCopy((void*)pData, (size_t)dwFileLen);
+						RELEASEARRAYOBJECTS(pData);
+#else
 						retval = CefV8Value::CreateArrayBuffer((void*)pData, (size_t)dwFileLen, new CAscCefV8ArrayBufferReleaseCallback());
 #endif
+#endif
 					}
 					else
 						retval = CefV8Value::CreateUndefined();
@@ -1125,7 +1132,7 @@
 
 		inline void CallInEditorFrame(CefRefPtr<CefBrowser>& browser, const std::string& sCode)
 		{
-			CefRefPtr<CefFrame> frame = browser->GetFrame("frameEditor");
+			CefRefPtr<CefFrame> frame = NSCefCompat::GetFrame(browser, "frameEditor");
 			if (!frame)
 				frame = browser->GetMainFrame();
 
@@ -1555,7 +1562,7 @@
 					{
 						CefRefPtr<CefBrowser> browser = CefV8Context::GetCurrentContext()->GetBrowser();
 						CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("load_js");
-						int64 frameId = CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier();
+						int64 frameId = NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame());
 						message->GetArgumentList()->SetString(0, GetFullUrl2(strUrl, CefV8Context::GetCurrentContext()->GetFrame()->GetURL().ToWString()));
 						message->GetArgumentList()->SetString(1, strPath);
 						NSArgumentList::SetInt64(message->GetArgumentList(), 2, frameId);
@@ -1661,7 +1668,7 @@
 				if (0 == arguments.size())
 					return true;
 
-				int64 frameId = CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier();
+				int64 frameId = NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame());
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("spell_check_task");
 				message->GetArgumentList()->SetInt(0, (int)m_nEditorId);
 				message->GetArgumentList()->SetString(1, arguments[0]->GetStringValue());
@@ -2348,10 +2355,10 @@
 
 				std::wstring sRequestPath = arguments[0]->GetStringValue();
 
-				boost::filesystem::wpath current_path = m_sLocalFileSrc;
-				boost::filesystem::wpath request_path = sRequestPath;
+				boost::filesystem::path current_path = m_sLocalFileSrc;
+				boost::filesystem::path request_path = sRequestPath;
 
-				boost::filesystem::wpath relativePath = boost::filesystem::relative(request_path, current_path.parent_path());
+				boost::filesystem::path relativePath = boost::filesystem::relative(request_path, current_path.parent_path());
 				std::wstring sRelativePath = relativePath.wstring();
 
 				if (sRelativePath.empty())
@@ -2704,6 +2711,12 @@
 			}
 			else if (name == "InitJSContext")
 			{
+#ifdef CEF_VERSION_ABOVE_128
+				// window.AscDesktopEditor is set up once, the script below
+				// defines properties (CryptoMode) that cannot be redefined
+				if (object && object->IsObject() && object->HasValue("CryptoMode"))
+					return true;
+#endif
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("on_init_js_context");
 				SEND_MESSAGE_TO_BROWSER_PROCESS(message);
 
@@ -3162,7 +3175,7 @@
 
 				// send to editor
 				CefRefPtr<CefBrowser> browser = CefV8Context::GetCurrentContext()->GetBrowser();
-				CefRefPtr<CefFrame> _frame = browser->GetFrame("frameEditor");
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, "frameEditor");
 				if (!_frame)
 					_frame = browser->GetMainFrame();
 
@@ -3191,7 +3204,7 @@
 
 				// send to editor
 				CefRefPtr<CefBrowser> browser = CefV8Context::GetCurrentContext()->GetBrowser();
-				CefRefPtr<CefFrame> _frame = browser->GetFrame("frameEditor");
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, "frameEditor");
 				if (!_frame)
 					_frame = browser->GetMainFrame();
 
@@ -3277,7 +3290,7 @@
 
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("on_open_filename_dialog");
 				message->GetArgumentList()->SetString(0, arguments[0]->GetStringValue());
-				message->GetArgumentList()->SetString(1, std::to_string(CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier()));
+				message->GetArgumentList()->SetString(1, std::to_string(NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame())));
 				if (arguments.size() > 1)
 					message->GetArgumentList()->SetBool(2, arguments[1]->GetBoolValue());
 				SEND_MESSAGE_TO_BROWSER_PROCESS(message);
@@ -3391,7 +3404,7 @@
 
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("send_system_message");
 
-				int64 frameID = CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier();
+				int64 frameID = NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame());
 
 				message->GetArgumentList()->SetString(0, arguments[0]->GetStringValue());
 				message->GetArgumentList()->SetString(1, std::to_string(frameID));
@@ -3407,7 +3420,7 @@
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("file_get_hash");
 				message->GetArgumentList()->SetString(0, arguments[0]->GetStringValue());
 				message->GetArgumentList()->SetString(1, (arguments.size() > 1) ? arguments[1]->GetStringValue() : "sha-256");
-				message->GetArgumentList()->SetString(2, std::to_string(CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier()));
+				message->GetArgumentList()->SetString(2, std::to_string(NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame())));
 				SEND_MESSAGE_TO_BROWSER_PROCESS(message);
 				return true;
 			}
@@ -3536,7 +3549,7 @@
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("preload_crypto_image");
 				message->GetArgumentList()->SetString(0, arguments[0]->GetStringValue());
 				message->GetArgumentList()->SetString(1, arguments[1]->GetStringValue());
-				NSArgumentList::SetInt64(message->GetArgumentList(), 2, CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier());
+				NSArgumentList::SetInt64(message->GetArgumentList(), 2, NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame()));
 				SEND_MESSAGE_TO_BROWSER_PROCESS(message);
 				return true;
 			}
@@ -3607,7 +3620,7 @@
 				int nIndex = 0;
 
 				message->GetArgumentList()->SetInt(nIndex++, nParams);
-				NSArgumentList::SetInt64(message->GetArgumentList(), nIndex++, CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier());
+				NSArgumentList::SetInt64(message->GetArgumentList(), nIndex++, NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame()));
 
 				for (int i = 0; i < nCount; ++i)
 				{
@@ -3659,7 +3672,7 @@
 				message->GetArgumentList()->SetString(0, arguments[0]->GetStringValue());
 				message->GetArgumentList()->SetInt(1, arguments[1]->GetIntValue());
 				message->GetArgumentList()->SetBool(2, (arguments.size() > 2) ? arguments[2]->GetBoolValue() : false);
-				NSArgumentList::SetInt64(message->GetArgumentList(), 3, CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier());
+				NSArgumentList::SetInt64(message->GetArgumentList(), 3, NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame()));
 				SEND_MESSAGE_TO_BROWSER_PROCESS(message);
 				return true;
 			}
@@ -3723,7 +3736,7 @@
 					return true;
 
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("get_advanced_encrypted_data");
-				NSArgumentList::SetInt64(message->GetArgumentList(), 0, CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier());
+				NSArgumentList::SetInt64(message->GetArgumentList(), 0, NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame()));
 				message->GetArgumentList()->SetString(1, arguments[0]->GetStringValue());
 				SEND_MESSAGE_TO_BROWSER_PROCESS(message);
 				return true;
@@ -3734,7 +3747,7 @@
 					return true;
 
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("set_advanced_encrypted_data");
-				NSArgumentList::SetInt64(message->GetArgumentList(), 0, CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier());
+				NSArgumentList::SetInt64(message->GetArgumentList(), 0, NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame()));
 				message->GetArgumentList()->SetString(1, arguments[0]->GetStringValue());
 				message->GetArgumentList()->SetString(2, arguments[1]->GetStringValue());
 				SEND_MESSAGE_TO_BROWSER_PROCESS(message);
@@ -4072,7 +4085,7 @@
 			}
 			else if (name == "SendByMail")
 			{
-				CefRefPtr<CefFrame> _frame = CefV8Context::GetCurrentContext()->GetBrowser()->GetFrame("frameEditor");
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(CefV8Context::GetCurrentContext()->GetBrowser(), "frameEditor");
 				if (!_frame)
 					return true;
 
@@ -4162,7 +4175,7 @@
 
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("cloud_crypto_upload");
 				message->GetArgumentList()->SetBool(0, bIsNeedRemoveAfterUse);
-				NSArgumentList::SetInt64(message->GetArgumentList(), 1, CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier());
+				NSArgumentList::SetInt64(message->GetArgumentList(), 1, NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame()));
 				message->GetArgumentList()->SetInt(2, nCount);
 				for (int i = 0; i < nCount; ++i)
 					message->GetArgumentList()->SetString(3 + i, arguments[0]->GetValue(i)->GetStringValue());
@@ -4227,7 +4240,7 @@
 
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("on_save_filename_dialog");
 				message->GetArgumentList()->SetString(0, arguments[0]->GetStringValue());
-				message->GetArgumentList()->SetString(1, std::to_string(CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier()));
+				message->GetArgumentList()->SetString(1, std::to_string(NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame())));
 
 				if (arguments.size() > 1 && arguments[1]->IsString())
 					message->GetArgumentList()->SetString(2, arguments[1]->GetStringValue());
@@ -4483,7 +4496,7 @@
 			}
 			else if (name == "GetFrameId")
 			{
-				int64 frameID = CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier();
+				int64 frameID = NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame());
 				uint64 uframeID = (uint64)frameID;
 				std::string sId = std::to_string(uframeID);
 				retval = CefV8Value::CreateString(sId);
@@ -4497,7 +4510,7 @@
 				std::string sId = arguments[0]->GetStringValue().ToString();
 				std::string sCode = arguments[1]->GetStringValue().ToString();
 				int64 frameId = (int64)(strtoull(sId.c_str(), NULL, 10));
-				CefRefPtr<CefFrame> frame = CefV8Context::GetCurrentContext()->GetBrowser()->GetFrame(frameId);
+				CefRefPtr<CefFrame> frame = NSCefCompat::GetFrame(CefV8Context::GetCurrentContext()->GetBrowser(), frameId);
 				if (frame)
 					frame->ExecuteJavaScript(sCode, frame->GetURL(), 0);
 				return true;
@@ -4887,7 +4900,16 @@
 					NSFile::CFileBinary::ReadAllBytes(sFilePath, &pData, dwFileLen);
 
 					if (0 != dwFileLen)
+					{
+#ifdef CEF_VERSION_ABOVE_128
+						// With the V8 sandbox (on in newer CEF) an ArrayBuffer cannot use
+						// memory from outside, CreateArrayBuffer fails: copy the data
+						retval = CefV8Value::CreateArrayBufferWithCopy((void*)pData, (size_t)dwFileLen);
+						RELEASEARRAYOBJECTS(pData);
+#else
 						retval = CefV8Value::CreateArrayBuffer((void*)pData, (size_t)dwFileLen, new CAscCefV8ArrayBufferReleaseCallback());
+#endif
+					}
 					else
 						retval = CefV8Value::CreateUndefined();
 				}
@@ -4926,7 +4948,7 @@
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("convert_file");
 				message->GetArgumentList()->SetString(0, arguments[0]->GetStringValue());
 				message->GetArgumentList()->SetInt(1, arguments[1]->GetIntValue());
-				NSArgumentList::SetInt64(message->GetArgumentList(), 2, CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier());
+				NSArgumentList::SetInt64(message->GetArgumentList(), 2, NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame()));
 
 				SEND_MESSAGE_TO_BROWSER_PROCESS(message);
 				return true;
@@ -4995,7 +5017,7 @@
 
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("send_simple_request");
 
-				NSArgumentList::SetInt64(message->GetArgumentList(), 0, CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier());
+				NSArgumentList::SetInt64(message->GetArgumentList(), 0, NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame()));
 				message->GetArgumentList()->SetInt(1, nCounter);
 				message->GetArgumentList()->SetString(2, sUrl);
 				message->GetArgumentList()->SetString(3, sMethod);
@@ -5171,10 +5193,10 @@
 					if (!NSFileDownloader::IsNeedDownload(sRequestPath) &&
 						!NSFile::CFileBinary::Exists(sRequestPath))
 					{
-						boost::filesystem::wpath current_path = m_sLocalFileSrc;
-						boost::filesystem::wpath request_path = sRequestPath;
+						boost::filesystem::path current_path = m_sLocalFileSrc;
+						boost::filesystem::path request_path = sRequestPath;
 
-						boost::filesystem::wpath absolute_path = boost::filesystem::absolute(request_path, current_path.parent_path());
+						boost::filesystem::path absolute_path = boost::filesystem::absolute(request_path, current_path.parent_path());
 						sRequestPath = absolute_path.wstring();
 
 						if (!NSFile::CFileBinary::Exists(sRequestPath))
@@ -5359,7 +5381,7 @@
 
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("convert_file_external");
 				message->GetArgumentList()->SetString(0, sFileUrl);
-				NSArgumentList::SetInt64(message->GetArgumentList(), 1, CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier());
+				NSArgumentList::SetInt64(message->GetArgumentList(), 1, NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame()));
 				message->GetArgumentList()->SetInt(2, arguments[1]->GetIntValue());
 				message->GetArgumentList()->SetInt(3, arguments[2]->GetIntValue());
 
@@ -5590,7 +5612,7 @@
 
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("convert_file_external_and_open");
 				message->GetArgumentList()->SetString(0, sTmpFile);
-				NSArgumentList::SetInt64(message->GetArgumentList(), 1, CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier());
+				NSArgumentList::SetInt64(message->GetArgumentList(), 1, NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame()));
 				message->GetArgumentList()->SetString(2, arguments[2]->GetStringValue());
 				message->GetArgumentList()->SetInt(3, arguments[3]->GetIntValue());
 				message->GetArgumentList()->SetInt(4, nConvertCounter);
@@ -5658,7 +5680,7 @@
 				CefRefPtr<CefFrame> callerFrame = CefV8Context::GetCurrentContext()->GetFrame();
 				CefRefPtr<CefFrame> mainFrame = browser->GetMainFrame();
 
-				int64 callerFrameId = callerFrame->GetIdentifier();
+				int64 callerFrameId = NSCefCompat::GetFrameId(callerFrame);
 
 				std::string sCode = "\
 (function() {\
@@ -5688,7 +5710,7 @@
 
 				CefRefPtr<CefBrowser> browser =
 					CefV8Context::GetCurrentContext()->GetBrowser();
-				CefRefPtr<CefFrame> targetFrame = browser->GetFrame(targetFrameId);
+				CefRefPtr<CefFrame> targetFrame = NSCefCompat::GetFrame(browser, targetFrameId);
 
 				if (targetFrame)
 				{
@@ -5734,7 +5756,7 @@
 					sDomain = sDomain.substr(0, pos);
 
 				CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create("get_portal_auth_token");
-				NSArgumentList::SetInt64(message->GetArgumentList(), 0, CefV8Context::GetCurrentContext()->GetFrame()->GetIdentifier());
+				NSArgumentList::SetInt64(message->GetArgumentList(), 0, NSCefCompat::GetFrameId(CefV8Context::GetCurrentContext()->GetFrame()));
 				message->GetArgumentList()->SetString(1, sCallbackId);
 				message->GetArgumentList()->SetString(2, sDomain);
 				SEND_MESSAGE_TO_BROWSER_PROCESS(message);
@@ -5745,11 +5767,11 @@
 				CefRefPtr<CefBrowser> browser = CefV8Context::GetCurrentContext()->GetBrowser();
 
 				std::vector<int64> ids;
-				browser->GetFrameIdentifiers(ids);
+				NSCefCompat::GetFrameIdentifiers(browser, ids);
 
 				for (std::vector<int64>::iterator i = ids.begin(); i != ids.end(); i++)
 				{
-					CefRefPtr<CefFrame> _frame = browser->GetFrame(*i);
+					CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, *i);
 					_frame->ExecuteJavaScript("window.onUpdateClouds && window.onUpdateClouds();", _frame->GetURL(), 0);
 				}
 
@@ -6382,6 +6404,14 @@
 			// load native plugins once (renderer role); registers their JS methods
 			CRendererPluginHost::Instance().Init();
 
+#ifdef CEF_VERSION_ABOVE_128
+			// CEF calls this for the contexts of all the worlds of a frame, the
+			// isolated ones too, but the scripts below are always run in its
+			// main world, which is set up for its own context
+			if (frame && !context->IsSame(frame->GetV8Context()))
+				return;
+#endif
+
 			// add AscEditorNative
 			CefRefPtr<CefV8Value> object = context->GetGlobal();
 
@@ -6835,11 +6865,11 @@
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
 
@@ -6883,7 +6913,7 @@
 			else if (sMessageName == "spell_check_response")
 			{
 				int64 nFrameId = NSArgumentList::GetInt64(message->GetArgumentList(), 1);
-				CefRefPtr<CefFrame> _frame = browser->GetFrame(nFrameId);
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, nFrameId);
 				if (_frame)
 				{
 					std::string sCode = "window[\"asc_nativeOnSpellCheck\"](" + message->GetArgumentList()->GetString(0).ToString() + ");";
@@ -6918,7 +6948,7 @@
 					return true;
 
 				// deliver only to the requesting frame; a token must not land anywhere else
-				CefRefPtr<CefFrame> _frame = browser->GetFrame(nFrameId);
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, nFrameId);
 				if (!_frame)
 					return true;
 
@@ -7007,7 +7037,7 @@
 			else if (sMessageName == "on_load_js")
 			{
 				int64 frameId = NSArgumentList::GetInt64(message->GetArgumentList(), 2);
-				CefRefPtr<CefFrame> _frame = browser->GetFrame(frameId);
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, frameId);
 				if (_frame)
 				{
 					std::wstring sFilePath = message->GetArgumentList()->GetString(0).ToWString();
@@ -7295,7 +7325,7 @@
 				CefRefPtr<CefFrame> _frame = browser->GetMainFrame();
 				if (!sFrameName.empty())
 				{
-					_frame = browser->GetFrame(sFrameName);
+					_frame = NSCefCompat::GetFrame(browser, sFrameName);
 				}
 
 				if (!_frame)
@@ -7437,7 +7467,7 @@
 				else
 				{
 					int64 nId = (int64)std::stoll(sId);
-					_frame = browser->GetFrame(nId);
+					_frame = NSCefCompat::GetFrame(browser, nId);
 				}
 				bool bIsMulti = message->GetArgumentList()->GetBool(1);
 
@@ -7488,7 +7518,7 @@
 				else
 				{
 					int64 nId = (int64)std::stoll(sId);
-					_frame = browser->GetFrame(nId);
+					_frame = NSCefCompat::GetFrame(browser, nId);
 				}
 
 				if (_frame)
@@ -7576,7 +7606,7 @@
 			else if (sMessageName == "file_get_hash_callback")
 			{
 				int64 frameID = (int64)std::stoll(message->GetArgumentList()->GetString(1).ToString());
-				CefRefPtr<CefFrame> _frame = browser->GetFrame(frameID);
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, frameID);
 
 				if (_frame)
 				{
@@ -7599,12 +7629,12 @@
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
@@ -7633,7 +7663,7 @@
 				else
 				{
 					int64 frameID = (int64)std::stoll(message->GetArgumentList()->GetString(1).ToString());
-					CefRefPtr<CefFrame> _frame = browser->GetFrame(frameID);
+					CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, frameID);
 
 					if (_frame)
 					{
@@ -7653,12 +7683,12 @@
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
@@ -7775,7 +7805,7 @@
 					int64 nFrameId = NSArgumentList::GetInt64(message->GetArgumentList(), 1);
 					if (0 != nFrameId)
 					{
-						CefRefPtr<CefFrame> _frameID = browser->GetFrame(nFrameId);
+						CefRefPtr<CefFrame> _frameID = NSCefCompat::GetFrame(browser, nFrameId);
 						if (_frameID)
 							_frame = _frameID;
 					}
@@ -7842,7 +7872,7 @@
 				int nIndex = 0;
 				int64 nFrameId = NSArgumentList::GetInt64(message->GetArgumentList(), nIndex++);
 
-				CefRefPtr<CefFrame> _frame = browser->GetFrame(nFrameId);
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, nFrameId);
 				if (!_frame)
 					_frame = GetEditorFrame(browser);
 
@@ -7872,7 +7902,7 @@
 				int nError = message->GetArgumentList()->GetInt(0);
 				int64 nFrameId = NSArgumentList::GetInt64(message->GetArgumentList(), 1);
 
-				CefRefPtr<CefFrame> _frame = browser->GetFrame(nFrameId);
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, nFrameId);
 				if (_frame)
 					_frame->ExecuteJavaScript(
 						"(function() { if (!window.on_set_crypto_mode) return; window.on_set_crypto_mode(" + std::to_string(nError) + "); delete window.on_set_crypto_mode; })();", _frame->GetURL(),
@@ -7884,7 +7914,7 @@
 				std::string sRet = message->GetArgumentList()->GetString(1);
 				NSStringUtils::string_replaceA(sRet, "\\", "\\\\");
 
-				CefRefPtr<CefFrame> _frame = browser->GetFrame(nFrameId);
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, nFrameId);
 				if (_frame)
 					_frame->ExecuteJavaScript(
 						"(function() { if (!window.on_get_advanced_encrypted_data) return; window.on_get_advanced_encrypted_data(\"" + sRet +
@@ -7897,7 +7927,7 @@
 				std::string sRet = message->GetArgumentList()->GetString(1);
 				NSStringUtils::string_replaceA(sRet, "\\", "\\\\");
 
-				CefRefPtr<CefFrame> _frame = browser->GetFrame(nFrameId);
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, nFrameId);
 				if (_frame)
 					_frame->ExecuteJavaScript(
 						"(function() { if (!window.on_set_advanced_encrypted_data) return; window.on_set_advanced_encrypted_data(\"" + sRet +
@@ -7945,11 +7975,11 @@
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
@@ -7959,11 +7989,11 @@
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
@@ -7977,7 +8007,7 @@
 				NSStringUtils::string_replaceA(sFolder, "\\", "\\\\");
 				NSStringUtils::string_replaceA(sFolder, "\"", "\\\"");
 
-				CefRefPtr<CefFrame> _frame = browser->GetFrame(nFrameId);
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, nFrameId);
 				if (!_frame)
 					return true;
 
@@ -7994,7 +8024,7 @@
 				int nReturnCode = message->GetArgumentList()->GetInt(2);
 				int nConvertId = message->GetArgumentList()->GetInt(3);
 
-				CefRefPtr<CefFrame> _frame = browser->GetFrame(nFrameId);
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, nFrameId);
 				if (!_frame)
 					return true;
 
@@ -8023,7 +8053,7 @@
 	private:
 		CefRefPtr<CefFrame> GetEditorFrame(CefRefPtr<CefBrowser> browser)
 		{
-			CefRefPtr<CefFrame> _frame = browser->GetFrame("frameEditor");
+			CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, "frameEditor");
 			if (_frame)
 				return _frame;
 			return browser->GetMainFrame();

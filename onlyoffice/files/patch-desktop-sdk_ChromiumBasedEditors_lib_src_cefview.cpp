--- desktop-sdk/ChromiumBasedEditors/lib/src/cefview.cpp.orig	2026-11-05 00:00:00 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/cefview.cpp
@@ -167,6 +167,13 @@
 		virtual bool IsInProgress() { return false; }
 		virtual bool IsComplete() { return false; }
 		virtual bool IsCanceled() { return true; }
+#ifdef CEF_VERSION_ABOVE_128
+		virtual bool IsInterrupted() { return false; }
+		virtual cef_download_interrupt_reason_t GetInterruptReason() { return CEF_DOWNLOAD_INTERRUPT_REASON_NONE; }
+#if CEF_VERSION_MAJOR >= 144
+		virtual bool IsPaused() { return false; }
+#endif
+#endif
 		virtual int64 GetCurrentSpeed() { return 0; }
 		virtual int GetPercentComplete() { return 0; }
 		virtual int64 GetTotalBytes() { return 0; }
@@ -1572,7 +1579,7 @@
 
 			if (this->GetBrowser())
 			{
-				CefRefPtr<CefFrame> _frame = this->GetBrowser()->GetFrame("frameEditor");
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(this->GetBrowser(), "frameEditor");
 				if (_frame)
 				{
 					std::string sCode = "window.Asc.editor.onLocalSaveToDrawingFormat(" + std::to_string(nError) + ");";
@@ -1608,7 +1615,7 @@
 				}
 				else
 				{
-					CefRefPtr<CefFrame> _frame = this->GetBrowser()->GetFrame("frameEditor");
+					CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(this->GetBrowser(), "frameEditor");
 					if (_frame)
 					{
 						std::wstring sCode = L"(function(){ if (window.Asc && window.Asc.editor) window.Asc.editor.endExternalConvertation(); })();";
@@ -1895,6 +1902,12 @@
 	IMPLEMENT_REFCOUNTING(CCefResizeTask);
 };
 
+#ifdef CEF_VERSION_ABOVE_128
+#define ASC_WOD_NEW_BACKGROUND_TAB CEF_WOD_NEW_BACKGROUND_TAB
+#else
+#define ASC_WOD_NEW_BACKGROUND_TAB WOD_NEW_BACKGROUND_TAB
+#endif
+
 class CAscClientHandler : public client::ClientHandler, public CCookieFoundCallback, public CCookieValueCallback, public client::ClientHandler::Delegate, public CefDialogHandler
 {
 public:
@@ -1975,12 +1988,21 @@
 	};
 
 public:
-	CAscClientHandler() : client::ClientHandler(this, false,
+	CAscClientHandler() : client::ClientHandler(
+											#ifdef CEF_VERSION_ABOVE_128
+												nullptr,
+											#else
+												this,
+											#endif
+												false,
 											#ifdef CEF_VERSION_ABOVE_102
 												false,
 											#endif
 												"https://onlyoffice.com/")
 	{
+#ifdef CEF_VERSION_ABOVE_128
+		delegate_ = this;
+#endif
 		m_pParent = NULL;
 		m_bIsLoaded = false;
 
@@ -2390,6 +2412,9 @@
 	virtual bool OnBeforePopup(
 			CefRefPtr<CefBrowser> browser,
 			CefRefPtr<CefFrame> frame,
+		#ifdef CEF_VERSION_ABOVE_128
+			int popup_id,
+		#endif
 			const CefString& target_url,
 			const CefString& target_frame_name,
 			CefLifeSpanHandler::WindowOpenDisposition target_disposition,
@@ -2417,7 +2442,7 @@
 			}
 		}
 
-		CheckPopup(target_url.ToWString(), false, (WOD_NEW_BACKGROUND_TAB == target_disposition) ? true : false, false, sFrameUrl);
+		CheckPopup(target_url.ToWString(), false, (ASC_WOD_NEW_BACKGROUND_TAB == target_disposition) ? true : false, false, sFrameUrl);
 		return true;
 	}
 
@@ -2432,7 +2457,7 @@
 		std::wstring sFrameUrl = L"";
 		if (frame)
 			sFrameUrl = frame->GetURL().ToWString();
-		CheckPopup(target_url.ToWString(), false, (WOD_NEW_BACKGROUND_TAB == target_disposition) ? true : false, true, sFrameUrl);
+		CheckPopup(target_url.ToWString(), false, (ASC_WOD_NEW_BACKGROUND_TAB == target_disposition) ? true : false, true, sFrameUrl);
 		return true;
 	}
 
@@ -3952,7 +3977,7 @@
 
 			if (nParams == 1)
 			{
-				CefRefPtr<CefFrame> frame = browser->GetFrame(nFrameID);
+				CefRefPtr<CefFrame> frame = NSCefCompat::GetFrame(browser, nFrameID);
 				if (frame)
 					frame->ExecuteJavaScript("window.onSystemMessage && window.onSystemMessage({ type : \"operation\", block : true, opType : 0 });", frame->GetURL(), 0);
 			}
@@ -4420,7 +4445,7 @@
 				}
 				else
 				{
-					CefRefPtr<CefFrame> _frame = browser->GetFrame("frameEditor");
+					CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, "frameEditor");
 					if (_frame)
 					{
 						std::wstring sCode = L"(function(){ if (window.Asc && window.Asc.editor) window.Asc.editor.startExternalConvertation('sendTo'); })();";
@@ -4906,13 +4931,16 @@
 
 virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) OVERRIDE
 {
+#ifdef CEF_VERSION_ABOVE_128
+	client::ClientHandler::OnBeforeClose(browser);
+	return;
+#endif
 	CEF_REQUIRE_UI_THREAD();
 
 	if (--browser_count_ == 0)
 	{
 		// Remove and delete message router handlers.
-		MessageHandlerSet::const_iterator it =
-				message_handler_set_.begin();
+		auto it = message_handler_set_.begin();
 		for (; it != message_handler_set_.end(); ++it)
 		{
 			message_router_->RemoveHandler(*(it));
@@ -5651,7 +5679,11 @@
 }
 
 virtual void OnRenderProcessTerminated(CefRefPtr<CefBrowser> browser,
-									   TerminationStatus status) OVERRIDE
+									   TerminationStatus status
+									#ifdef CEF_VERSION_ABOVE_128
+									   , int error_code, const CefString& error_string
+									#endif
+									   ) OVERRIDE
 {
 	CEF_REQUIRE_UI_THREAD();
 
@@ -5700,7 +5732,14 @@
 }
 #endif
 
-virtual void OnBeforeDownload(CefRefPtr<CefBrowser> browser,
+#ifdef CEF_VERSION_ABOVE_128
+#define ASC_DOWNLOAD_RESULT bool
+#define ASC_DOWNLOAD_HANDLED true
+#else
+#define ASC_DOWNLOAD_RESULT void
+#define ASC_DOWNLOAD_HANDLED
+#endif
+virtual ASC_DOWNLOAD_RESULT OnBeforeDownload(CefRefPtr<CefBrowser> browser,
 							  CefRefPtr<CefDownloadItem> download_item,
 							  const CefString& suggested_name,
 							  CefRefPtr<CefBeforeDownloadCallback> callback) OVERRIDE
@@ -5758,7 +5797,7 @@
 		NSStringUtils::string_replace(sDestPath, L"/", L"\\");
 #endif
 		callback->Continue(sDestPath, false);
-		return;
+		return ASC_DOWNLOAD_HANDLED;
 	}
 
 	// скачивание, которое надо отправлять наверх
@@ -5776,6 +5815,7 @@
 	pEvent->m_pData = pData;
 
 	m_pParent->GetAppManager()->Apply(pEvent);
+	return ASC_DOWNLOAD_HANDLED;
 }
 
 virtual void OnDownloadUpdated(CefRefPtr<CefBrowser> browser,
@@ -6020,6 +6060,15 @@
 // ClientHandlerDelegate
 virtual void OnBrowserCreated(CefRefPtr<CefBrowser> browser) OVERRIDE {}
 
+#ifdef CEF_VERSION_ABOVE_128
+virtual const void* GetTypeKey() const override { return &kTypeKey; }
+static constexpr int kTypeKey = 0;
+
+virtual bool UseViews() const override { return false; }
+virtual bool UseAlloyStyle() const override { return true; }
+virtual void OnContentsBounds(const CefRect& new_bounds) override {}
+#endif
+
 // Called when the browser is closing.
 virtual void OnBrowserClosing(CefRefPtr<CefBrowser> browser) OVERRIDE
 {
@@ -6502,7 +6551,7 @@
 #endif
 		if (GetBrowser())
 		{
-			CefRefPtr<CefFrame> _frame = GetBrowser()->GetFrame("frameEditor");
+			CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(GetBrowser(), "frameEditor");
 			if (_frame)
 			{
 				std::wstring sCode = L"(function(){ \n\
@@ -7577,7 +7626,7 @@
 			{
 				if (this->m_pInternal->GetBrowser())
 				{
-					CefRefPtr<CefFrame> _frame = this->m_pInternal->GetBrowser()->GetFrame("frameEditor");
+					CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(this->m_pInternal->GetBrowser(), "frameEditor");
 					if (_frame)
 					{
 						std::string sCode = "window.Asc.editor.onLocalSaveToDrawingFormat(0);";
@@ -8038,11 +8087,11 @@
 			std::wstring sCode = pData->get_Value();
 
 			std::vector<int64> arIds;
-			pBrowser->GetFrameIdentifiers(arIds);
+			NSCefCompat::GetFrameIdentifiers(pBrowser, arIds);
 
 			for (std::vector<int64>::iterator iter = arIds.begin(); iter != arIds.end(); iter++)
 			{
-				CefRefPtr<CefFrame> frame = pBrowser->GetFrame(*iter);
+				CefRefPtr<CefFrame> frame = NSCefCompat::GetFrame(pBrowser, *iter);
 				if (frame)
 					frame->ExecuteJavaScript(sCode, frame->GetURL(), 0);
 			}
@@ -8257,11 +8306,11 @@
 	std::string sCode = "(function(){window.AscDesktopEditor._setViewportSettings(\"" + sViewportInfo + "\");})();";
 
 	std::vector<int64> identifiers;
-	pBrowser->GetFrameIdentifiers(identifiers);
+	NSCefCompat::GetFrameIdentifiers(pBrowser, identifiers);
 
 	for (std::vector<int64>::iterator iter = identifiers.begin(); iter != identifiers.end(); iter++)
 	{
-		CefRefPtr<CefFrame> pFrame = pBrowser->GetFrame(*iter);
+		CefRefPtr<CefFrame> pFrame = NSCefCompat::GetFrame(pBrowser, *iter);
 		if (pFrame)
 		{
 			pFrame->ExecuteJavaScript(sCode, pFrame->GetURL(), 0);
@@ -8280,7 +8329,7 @@
 {
 	if (!View->m_handler || !View->m_handler->GetBrowser())
 		return nullptr;
-	return View->m_handler->GetBrowser()->GetFrame(FrameID);
+	return NSCefCompat::GetFrame(View->m_handler->GetBrowser(), FrameID);
 }
 
 void CCefView::ExecuteInAllFrames(const std::string& sCode, const bool& isMain)
@@ -8290,11 +8339,11 @@
 		return;
 
 	std::vector<int64> identifiers;
-	pBrowser->GetFrameIdentifiers(identifiers);
+	NSCefCompat::GetFrameIdentifiers(pBrowser, identifiers);
 
 	for (std::vector<int64>::iterator iter = identifiers.begin(); iter != identifiers.end(); iter++)
 	{
-		CefRefPtr<CefFrame> pFrame = pBrowser->GetFrame(*iter);
+		CefRefPtr<CefFrame> pFrame = NSCefCompat::GetFrame(pBrowser, *iter);
 		if (!pFrame)
 			continue;
 		if (!isMain && pFrame->IsMain())
@@ -8309,7 +8358,7 @@
 	CefRefPtr<CefBrowser> pBrowser = m_pInternal->GetBrowser();
 	if (!pBrowser)
 		return;
-	CefRefPtr<CefFrame> pFrame = pBrowser->GetFrame("frameEditor");
+	CefRefPtr<CefFrame> pFrame = NSCefCompat::GetFrame(pBrowser, "frameEditor");
 	if (pFrame)
 		pFrame->ExecuteJavaScript(sCode, pFrame->GetURL(), 0);
 }
@@ -8911,7 +8960,7 @@
 	if (!pBrowser)
 		return;
 
-	CefRefPtr<CefFrame> pFrame = pBrowser->GetFrame("frameEditor");
+	CefRefPtr<CefFrame> pFrame = NSCefCompat::GetFrame(pBrowser, "frameEditor");
 	if (pFrame)
 		pFrame->ExecuteJavaScript("if (window.UpdateInstallPlugins) window.UpdateInstallPlugins();", pFrame->GetURL(), 0);
 }
@@ -9029,11 +9078,11 @@
 	std::string sCode = "(function(){if (window.onChangeEditorsCount) window.onChangeEditorsCount(" + sCodeValue + ");})();";
 
 	std::vector<int64> identifiers;
-	pView->m_pInternal->GetBrowser()->GetFrameIdentifiers(identifiers);
+	NSCefCompat::GetFrameIdentifiers(pView->m_pInternal->GetBrowser(), identifiers);
 
 	for (std::vector<int64>::iterator iter = identifiers.begin(); iter != identifiers.end(); iter++)
 	{
-		CefRefPtr<CefFrame> pFrame = pView->m_pInternal->GetBrowser()->GetFrame(*iter);
+		CefRefPtr<CefFrame> pFrame = NSCefCompat::GetFrame(pView->m_pInternal->GetBrowser(), *iter);
 		if (pFrame)
 		{
 			pFrame->ExecuteJavaScript(sCode, pFrame->GetURL(), 0);
@@ -9056,7 +9105,7 @@
 
 		if (m_view->GetBrowser())
 		{
-			CefRefPtr<CefFrame> frame = m_view->GetBrowser()->GetFrame(frameId);
+			CefRefPtr<CefFrame> frame = NSCefCompat::GetFrame(m_view->GetBrowser(), frameId);
 			if (frame)
 				frame->ExecuteJavaScript(sCode, frame->GetURL(), 0);
 		}
@@ -9069,7 +9118,7 @@
 
 		if (m_view->GetBrowser())
 		{
-			CefRefPtr<CefFrame> frame = m_view->GetBrowser()->GetFrame(m_frameId);
+			CefRefPtr<CefFrame> frame = NSCefCompat::GetFrame(m_view->GetBrowser(), m_frameId);
 			if (frame)
 				frame->ExecuteJavaScript("console.log('[simplerequest]: attept " + std::to_string(m_nRetryCount + 1) + "');", frame->GetURL(), 0);
 		}

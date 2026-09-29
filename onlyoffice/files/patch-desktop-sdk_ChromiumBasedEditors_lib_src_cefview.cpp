--- desktop-sdk/ChromiumBasedEditors/lib/src/cefview.cpp.orig	2026-09-24 21:58:50 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/cefview.cpp
@@ -152,6 +152,13 @@ protected:
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
@@ -1390,7 +1397,7 @@ public:
 
 			if (this->GetBrowser())
 			{
-				CefRefPtr<CefFrame> _frame = this->GetBrowser()->GetFrame("frameEditor");
+				CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(this->GetBrowser(), "frameEditor");
 				if (_frame)
 				{
 					std::string sCode = "window.Asc.editor.onLocalSaveToDrawingFormat(" + std::to_string(nError) + ");";
@@ -1426,7 +1433,7 @@ public:
 				}
 				else
 				{
-					CefRefPtr<CefFrame> _frame = this->GetBrowser()->GetFrame("frameEditor");
+					CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(this->GetBrowser(), "frameEditor");
 					if (_frame)
 					{
 						std::wstring sCode = L"(function(){ if (window.Asc && window.Asc.editor) window.Asc.editor.endExternalConvertation(); })();";
@@ -1676,6 +1683,12 @@ private:
 	IMPLEMENT_REFCOUNTING(CCefResizeTask);
 };
 
+#ifdef CEF_VERSION_ABOVE_128
+#define ASC_WOD_NEW_BACKGROUND_TAB CEF_WOD_NEW_BACKGROUND_TAB
+#else
+#define ASC_WOD_NEW_BACKGROUND_TAB WOD_NEW_BACKGROUND_TAB
+#endif
+
 class CAscClientHandler : public client::ClientHandler, public CCookieFoundCallback, public client::ClientHandler::Delegate, public CefDialogHandler
 {
 public:
@@ -1756,12 +1769,21 @@ public:
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
 
@@ -2171,6 +2193,9 @@ public:
 	virtual bool OnBeforePopup(
 			CefRefPtr<CefBrowser> browser,
 			CefRefPtr<CefFrame> frame,
+		#ifdef CEF_VERSION_ABOVE_128
+			int popup_id,
+		#endif
 			const CefString& target_url,
 			const CefString& target_frame_name,
 			CefLifeSpanHandler::WindowOpenDisposition target_disposition,
@@ -2188,7 +2213,7 @@ public:
 		std::wstring sFrameUrl = L"";
 		if (frame)
 			sFrameUrl = frame->GetURL().ToWString();
-		CheckPopup(target_url.ToWString(), false, (WOD_NEW_BACKGROUND_TAB == target_disposition) ? true : false, false, sFrameUrl);
+		CheckPopup(target_url.ToWString(), false, (ASC_WOD_NEW_BACKGROUND_TAB == target_disposition) ? true : false, false, sFrameUrl);
 		return true;
 	}
 
@@ -2203,7 +2228,7 @@ public:
 		std::wstring sFrameUrl = L"";
 		if (frame)
 			sFrameUrl = frame->GetURL().ToWString();
-		CheckPopup(target_url.ToWString(), false, (WOD_NEW_BACKGROUND_TAB == target_disposition) ? true : false, true, sFrameUrl);
+		CheckPopup(target_url.ToWString(), false, (ASC_WOD_NEW_BACKGROUND_TAB == target_disposition) ? true : false, true, sFrameUrl);
 		return true;
 	}
 
@@ -3668,7 +3693,7 @@ public:
 
 			if (nParams == 1)
 			{
-				CefRefPtr<CefFrame> frame = browser->GetFrame(nFrameID);
+				CefRefPtr<CefFrame> frame = NSCefCompat::GetFrame(browser, nFrameID);
 				if (frame)
 					frame->ExecuteJavaScript("window.onSystemMessage && window.onSystemMessage({ type : \"operation\", block : true, opType : 0 });", frame->GetURL(), 0);
 			}
@@ -4147,7 +4172,7 @@ public:
 				}
 				else
 				{
-					CefRefPtr<CefFrame> _frame = browser->GetFrame("frameEditor");
+					CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(browser, "frameEditor");
 					if (_frame)
 					{
 						std::wstring sCode = L"(function(){ if (window.Asc && window.Asc.editor) window.Asc.editor.startExternalConvertation('sendTo'); })();";
@@ -4546,13 +4571,16 @@ virtual void OnAfterCreated(CefRefPtr<Ce
 
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
@@ -5251,7 +5279,11 @@ std::string GetMimeType(const std::wstri
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
 
@@ -5300,7 +5332,14 @@ virtual bool CanDownload(CefRefPtr<CefBr
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
@@ -5358,7 +5397,7 @@ virtual void OnBeforeDownload(CefRefPtr<
 		NSStringUtils::string_replace(sDestPath, L"/", L"\\");
 #endif
 		callback->Continue(sDestPath, false);
-		return;
+		return ASC_DOWNLOAD_HANDLED;
 	}
 
 	// скачивание, которое надо отправлять наверх
@@ -5376,6 +5415,7 @@ virtual void OnBeforeDownload(CefRefPtr<
 	pEvent->m_pData = pData;
 
 	m_pParent->GetAppManager()->Apply(pEvent);
+	return ASC_DOWNLOAD_HANDLED;
 }
 
 virtual void OnDownloadUpdated(CefRefPtr<CefBrowser> browser,
@@ -5643,6 +5683,15 @@ virtual void OnFoundCookies(std::map<std
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
@@ -6097,7 +6146,7 @@ void CCefView_Private::LocalSendTo(const
 #endif
 		if (GetBrowser())
 		{
-			CefRefPtr<CefFrame> _frame = GetBrowser()->GetFrame("frameEditor");
+			CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(GetBrowser(), "frameEditor");
 			if (_frame)
 			{
 				std::wstring sCode = L"(function(){ \n\
@@ -6660,6 +6709,9 @@ void CCefView::load(const std::wstring&
 
 #ifdef CEF_VERSION_ABOVE_102
 	info.SetAsChild(_handle, CefRect(0, 0, _w, _h));
+#ifdef CEF_VERSION_ABOVE_128
+	info.runtime_style = CEF_RUNTIME_STYLE_ALLOY;
+#endif
 #else
 
 #ifdef WIN32
@@ -7089,7 +7141,7 @@ void CCefView::Apply(NSEditorApi::CAscMe
 			{
 				if (this->m_pInternal->GetBrowser())
 				{
-					CefRefPtr<CefFrame> _frame = this->m_pInternal->GetBrowser()->GetFrame("frameEditor");
+					CefRefPtr<CefFrame> _frame = NSCefCompat::GetFrame(this->m_pInternal->GetBrowser(), "frameEditor");
 					if (_frame)
 					{
 						std::string sCode = "window.Asc.editor.onLocalSaveToDrawingFormat(0);";
@@ -7533,11 +7585,11 @@ void CCefView::Apply(NSEditorApi::CAscMe
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
@@ -7749,11 +7801,11 @@ void CCefView::SetParentWidgetInfo(const
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
@@ -7772,7 +7824,7 @@ CefRefPtr<CefFrame> CCefView_Private::CC
 {
 	if (!View->m_handler || !View->m_handler->GetBrowser())
 		return nullptr;
-	return View->m_handler->GetBrowser()->GetFrame(FrameID);
+	return NSCefCompat::GetFrame(View->m_handler->GetBrowser(), FrameID);
 }
 
 // CefViewEditor --------------------------------------------------------------------------
@@ -8357,7 +8409,7 @@ void CCefViewEditor::UpdatePlugins()
 	if (!pBrowser)
 		return;
 
-	CefRefPtr<CefFrame> pFrame = pBrowser->GetFrame("frameEditor");
+	CefRefPtr<CefFrame> pFrame = NSCefCompat::GetFrame(pBrowser, "frameEditor");
 	if (pFrame)
 		pFrame->ExecuteJavaScript("if (window.UpdateInstallPlugins) window.UpdateInstallPlugins();", pFrame->GetURL(), 0);
 }
@@ -8475,11 +8527,11 @@ void CAscApplicationManager_Private::Cha
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
@@ -8502,7 +8554,7 @@ namespace NSRequest
 
 		if (m_view->GetBrowser())
 		{
-			CefRefPtr<CefFrame> frame = m_view->GetBrowser()->GetFrame(frameId);
+			CefRefPtr<CefFrame> frame = NSCefCompat::GetFrame(m_view->GetBrowser(), frameId);
 			if (frame)
 				frame->ExecuteJavaScript(sCode, frame->GetURL(), 0);
 		}

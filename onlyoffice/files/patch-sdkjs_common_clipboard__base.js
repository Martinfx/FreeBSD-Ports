--- sdkjs/common/clipboard_base.js.orig	2026-11-05 00:00:00 UTC
+++ sdkjs/common/clipboard_base.js
@@ -558,7 +558,7 @@
 						if (g_clipboardBase.Api.asc_IsFocus(true) && !g_clipboardBase._isUseMobileNewCopy()) {
 							e.preventDefault();
 						}
-						return g_clipboardBase.Copy_New();
+						return g_clipboardBase.Copy_New(false, false, e);
 					} else {
 						return g_clipboardBase._private_oncopy(e)
 					}
@@ -569,7 +569,7 @@
 						if (g_clipboardBase.Api.asc_IsFocus(true) && !g_clipboardBase._isUseMobileNewCopy()) {
 							e.preventDefault();
 						}
-						return g_clipboardBase.Copy_New(true);
+						return g_clipboardBase.Copy_New(true, false, e);
 					} else {
 						return g_clipboardBase._private_oncut(e)
 					}
@@ -1084,7 +1084,7 @@
 			return this.Copy_New(isCut, true);
 		},
 
-		Copy_New : function(isCut, isButtonCopy)
+		Copy_New : function(isCut, isButtonCopy, event)
 		{
 			let oThis = this;
 			if (!this.isCopyEnabled()) {
@@ -1136,8 +1136,26 @@
 					//"web text/x-custom" : new Blob(["asc_internalData2;" + copy_data.data[c_oAscClipboardDataFormat.Internal]], {type: "web text/x-custom"})
 
 					if (this.isCopyOutEnabled()) {
-						const data = [new ClipboardItem(clipboardData)];
-						navigator.clipboard.write(data).then(function(){},function(){});
+						// navigator.clipboard.write() is refused by newer
+						// Chromium unless the document has the focus and the
+						// permissions policy lets the frame of the editors use
+						// the clipboard, and the refusal is ignored: nothing
+						// copied would reach the other applications.  When the
+						// copy or cut event of the desktop editors is cancelled,
+						// its DataTransfer is written to the clipboard instead,
+						// so put the data there (with the internal format, as
+						// with CEF before 109).
+						if (window["AscDesktopEditor"] && event && event.defaultPrevented && event.clipboardData) {
+							if (copy_data.data[c_oAscClipboardDataFormat.Text])
+								event.clipboardData.setData("text/plain", copy_data.data[c_oAscClipboardDataFormat.Text]);
+							if (copy_data.data[c_oAscClipboardDataFormat.Html])
+								event.clipboardData.setData("text/html", copy_data.data[c_oAscClipboardDataFormat.Html]);
+							if (copy_data.data[c_oAscClipboardDataFormat.Internal])
+								event.clipboardData.setData("text/x-custom", "asc_internalData2;" + copy_data.data[c_oAscClipboardDataFormat.Internal]);
+						} else {
+							const data = [new ClipboardItem(clipboardData)];
+							navigator.clipboard.write(data).then(function(){},function(){});
+						}
 					}
 
 					if (isCut === true)

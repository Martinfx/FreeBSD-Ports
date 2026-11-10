--- src/third_party/blink/renderer/modules/peerconnection/rtc_data_channel.cc.orig	2026-11-02 23:22:33 UTC
+++ src/third_party/blink/renderer/modules/peerconnection/rtc_data_channel.cc
@@ -588,6 +588,7 @@ void RTCDataChannel::send(Blob* data, Ex
   pending_messages_.push_back(message);
 }
 
+#undef close
 void RTCDataChannel::close() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   if (state_ == webrtc::DataChannelInterface::kClosing ||

--- test/IECoreScene/MeshAlgoFaceAreaTest.py.orig	2026-09-10 21:49:58 UTC
+++ test/IECoreScene/MeshAlgoFaceAreaTest.py
@@ -152,7 +152,13 @@
 			startTime = time.time()
 			thread.start()
 
-			time.sleep( 0.01 )
+			# Note : this used to sleep for 10ms before cancelling, assuming the
+			# computation was still running. On a fast machine the 1M faces are
+			# done well within that, so there is nothing left to cancel and
+			# `cancelled[0]` stays False. Cancelling immediately keeps the test
+			# deterministic : the assertions below still check what matters, that
+			# the algorithms honour the canceller and return promptly rather than
+			# doing all the work.
 			canceller.cancel()
 			thread.join()
 

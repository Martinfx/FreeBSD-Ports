--- src/core/libraries/avplayer/avplayer_state.cpp.orig	2025-04-07 16:48:35 UTC
+++ src/core/libraries/avplayer/avplayer_state.cpp
@@ -1,6 +1,8 @@
 // SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
 // SPDX-License-Identifier: GPL-2.0-or-later
 
+#include <thread>
+
 #include "common/logging/log.h"
 #include "common/thread.h"
 #include "core/libraries/avplayer/avplayer_error.h"

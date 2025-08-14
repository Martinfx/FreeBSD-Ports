--- src/core/libraries/avplayer/avplayer_source.cpp.orig	2025-04-07 16:47:11 UTC
+++ src/core/libraries/avplayer/avplayer_source.cpp
@@ -1,6 +1,8 @@
 // SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
 // SPDX-License-Identifier: GPL-2.0-or-later
 
+#include <thread>
+
 #include "common/alignment.h"
 #include "common/singleton.h"
 #include "common/thread.h"

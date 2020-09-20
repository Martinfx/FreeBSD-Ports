--- quickassist/build_system/build_files/defenses.mk.orig	2020-09-20 20:50:37 UTC
+++ quickassist/build_system/build_files/defenses.mk
@@ -89,14 +89,14 @@ LIB_SHARED_FLAGS += -z relro -z now
 EXE_FLAGS += -Wl,-z,relro -Wl,-z,now
 
 # Stack-based buffer overrun detection
-$(PROG_ACY)_DEFENSES_STACK_PROTECTION?=y
-ifeq ($($(PROG_ACY)_DEFENSES_STACK_PROTECTION),y)
-ifeq "$(STACK_PROTECTOR_STRONG_NOT_SUPPORTED)" "1"
-EXTRA_CFLAGS += -fstack-protector
-else
-EXTRA_CFLAGS += -fstack-protector-strong
-endif
-endif
+#$(PROG_ACY)_DEFENSES_STACK_PROTECTION?=y
+#ifeq ($($(PROG_ACY)_DEFENSES_STACK_PROTECTION),y)
+#ifeq "$(STACK_PROTECTOR_STRONG_NOT_SUPPORTED)" "1"
+#EXTRA_CFLAGS += -fstack-protector
+#else
+#EXTRA_CFLAGS += -fstack-protector-strong
+#endif
+#endif
 
 # Position Independent Execution
 EXE_FLAGS += -pie

--- src/backend/gpopt/gpopt.mk.orig	2022-10-24 13:33:18 UTC
+++ src/backend/gpopt/gpopt.mk
@@ -1,4 +1,4 @@
-override CPPFLAGS := -std=c++98 $(CPPFLAGS)
+override CPPFLAGS := -std=c++11 $(CPPFLAGS)
 override CPPFLAGS := -I$(top_builddir)/src/backend/gporca/libgpos/include $(CPPFLAGS)
 override CPPFLAGS := -I$(top_builddir)/src/backend/gporca/libgpopt/include $(CPPFLAGS)
 override CPPFLAGS := -I$(top_builddir)/src/backend/gporca/libnaucrates/include $(CPPFLAGS)

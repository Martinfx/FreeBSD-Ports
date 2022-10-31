--- src/backend/gporca/gporca.mk.orig	2022-10-05 17:37:13 UTC
+++ src/backend/gporca/gporca.mk
@@ -4,5 +4,5 @@ override CPPFLAGS := -I$(top_builddir)/src/backend/gpo
 override CPPFLAGS := -I$(top_builddir)/src/backend/gporca/libgpdbcost/include $(CPPFLAGS)
 # Do not omit frame pointer. Even with RELEASE builds, it is used for
 # backtracing.
-override CPPFLAGS := -Werror -Wextra -Wpedantic -Wno-variadic-macros -fno-omit-frame-pointer $(CPPFLAGS)
-override CPPFLAGS := -std=gnu++98 $(CPPFLAGS)
+override CPPFLAGS := -Wextra -Wpedantic -Wno-variadic-macros -fno-omit-frame-pointer $(CPPFLAGS)
+override CPPFLAGS := -std=gnu++11 $(CPPFLAGS)

--- include/IECorePython/NanobindConverter.h.orig	2026-09-10 21:49:58 UTC
+++ include/IECorePython/NanobindConverter.h
@@ -42,6 +42,8 @@
 #include "nanobind/nanobind.h"
 #include "nanobind/stl/shared_ptr.h"
 
+#include <stdexcept>
+
 namespace IECorePython
 {
 
@@ -60,7 +62,18 @@
 			// registry. `NB_MODULE` would normally do this for Nanobind-native
 			// modules, but our Boost::Python modules need to perform this step
 			// manually before any Nanobind cast can run.
+#if defined( NB_VERSION_MAJOR ) && NB_VERSION_MAJOR >= 3
+			// Nanobind 3 removed the internal `nb_module_exec()` entry point,
+			// which has been replaced by the public `register_module()`. That
+			// anchors the domain in the module which hosts the bindings, which
+			// is the current Boost::Python scope inside `BOOST_PYTHON_MODULE`.
+			if( !nanobind::register_module( boost::python::scope().ptr() ) )
+			{
+				boost::python::throw_error_already_set();
+			}
+#else
 			nanobind::detail::nb_module_exec( NB_DOMAIN_STR, nullptr );
+#endif
 		}
 
 		boost::python::to_python_converter<T, ToNanobind>();
@@ -77,9 +90,23 @@
 		{
 			static PyObject *convert( const T &t )
 			{
-				nanobind::object o = nanobind::cast( t );
-				Py_INCREF( o.ptr() );
-				return o.ptr();
+				try
+				{
+					nanobind::object o = nanobind::cast( t );
+					Py_INCREF( o.ptr() );
+					return o.ptr();
+				}
+				catch( const std::bad_cast & )
+				{
+					// `nanobind::cast_error` is an alias for `std::bad_cast`, so on its
+					// own it tells the caller nothing. It means Nanobind has no binding
+					// for the type, which in practice means the module providing it
+					// hasn't been imported, or wasn't built in the first place.
+					throw std::runtime_error(
+						"No Nanobind binding registered for this type. The Python module "
+						"which provides it (`openvdb` for VDB grids) must be built and imported."
+					);
+				}
 			}
 		};
 

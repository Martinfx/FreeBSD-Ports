--- include/IECorePython/NanobindConverter.h.orig	2026-09-24 18:05:26 UTC
+++ include/IECorePython/NanobindConverter.h
@@ -60,7 +60,16 @@ struct NanobindConverter
 			// registry. `NB_MODULE` would normally do this for Nanobind-native
 			// modules, but our Boost::Python modules need to perform this step
 			// manually before any Nanobind cast can run.
+#if NB_VERSION_MAJOR >= 3
+			// Nanobind 3 requires the module being initialised, which is
+			// the Boost::Python module currently being defined.
+			if( !nanobind::register_module( nanobind::handle( boost::python::scope().ptr() ) ) )
+			{
+				boost::python::throw_error_already_set();
+			}
+#else
 			nanobind::detail::nb_module_exec( NB_DOMAIN_STR, nullptr );
+#endif
 		}
 
 		boost::python::to_python_converter<T, ToNanobind>();

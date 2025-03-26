--- src/GafferBindings/DependencyNodeBinding.cpp.orig	2025-03-02 13:41:41 UTC
+++ src/GafferBindings/DependencyNodeBinding.cpp
@@ -74,7 +74,7 @@ PyTypeObject *GafferBindings::Detail::dependencyNodeMe
 		// because it has functionality critical to making the Boost bindings
 		// work. The only thing we're doing is adding `dependencyNodeMetaclassCall`
 		// as the implementation of the `__call__` method.
-		Py_TYPE( &g_dependencyNodeMetaclass ) = &PyType_Type;
+		Py_SET_TYPE(&g_dependencyNodeMetaclass, &PyType_Type);
 		g_dependencyNodeMetaclass.tp_name = "Gaffer.DependencyNodeMetaclass";
 		g_dependencyNodeMetaclass.tp_basicsize = PyType_Type.tp_basicsize,
 		g_dependencyNodeMetaclass.tp_base = boost::python::objects::class_metatype().get();

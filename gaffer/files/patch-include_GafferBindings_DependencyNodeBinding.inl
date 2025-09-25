--- include/GafferBindings/DependencyNodeBinding.inl.orig	2025-08-28 19:52:07 UTC
+++ include/GafferBindings/DependencyNodeBinding.inl
@@ -81,7 +81,7 @@ DependencyNodeClass<T, Ptr>::DependencyNodeClass( cons
 	this->def( "enabledPlug", &Detail::enabledPlug<T> );
 	this->def( "correspondingInput", &Detail::correspondingInput<T> );
 	// Install our custom metaclass.
-	Py_SET_TYPE( this->ptr(), Detail::dependencyNodeMetaclass() );
+	Py_TYPE( this->ptr(), Detail::dependencyNodeMetaclass() );
 }
 
 template<typename T, typename Ptr>
@@ -92,7 +92,7 @@ DependencyNodeClass<T, Ptr>::DependencyNodeClass( cons
 	this->def( "enabledPlug", &Detail::enabledPlug<T> );
 	this->def( "correspondingInput", &Detail::correspondingInput<T> );
 	// Install our custom metaclass.
-	Py_SET_TYPE( this->ptr(), Detail::dependencyNodeMetaclass() );
+	Py_TYPE( this->ptr(), Detail::dependencyNodeMetaclass() );
 }
 
 } // namespace GafferBindings

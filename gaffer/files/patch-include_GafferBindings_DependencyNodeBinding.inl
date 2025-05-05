--- include/GafferBindings/DependencyNodeBinding.inl.orig	2025-03-02 13:39:44 UTC
+++ include/GafferBindings/DependencyNodeBinding.inl
@@ -81,7 +81,11 @@ DependencyNodeClass<T, Ptr>::DependencyNodeClass( cons
 	this->def( "enabledPlug", &Detail::enabledPlug<T> );
 	this->def( "correspondingInput", &Detail::correspondingInput<T> );
 	// Install our custom metaclass.
-	Py_TYPE( this->ptr() ) = Detail::dependencyNodeMetaclass();
+	#if PY_VERSION_HEX >= 0x03090000
+		Py_SET_TYPE(this->ptr(), Detail::dependencyNodeMetaclass());
+	#else
+		Py_TYPE(this->ptr()) = Detail::dependencyNodeMetaclass();
+	#endif
 }
 
 template<typename T, typename Ptr>
@@ -92,7 +96,11 @@ DependencyNodeClass<T, Ptr>::DependencyNodeClass( cons
 	this->def( "enabledPlug", &Detail::enabledPlug<T> );
 	this->def( "correspondingInput", &Detail::correspondingInput<T> );
 	// Install our custom metaclass.
-	Py_TYPE( this->ptr() ) = Detail::dependencyNodeMetaclass();
+	#if PY_VERSION_HEX >= 0x03090000
+		Py_SET_TYPE(this->ptr(), Detail::dependencyNodeMetaclass());
+	#else
+		Py_TYPE(this->ptr()) = Detail::dependencyNodeMetaclass();
+	#endif
 }
 
 } // namespace GafferBindings

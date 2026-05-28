--- include/GafferBindings/NodeBinding.inl.orig	2026-05-27 19:02:41 UTC
+++ include/GafferBindings/NodeBinding.inl
@@ -50,13 +50,13 @@ template<typename T, typename TWrapper>
 // node constructor bindings
 
 template<typename T, typename TWrapper>
-void defNodeConstructor( NodeClass<T, TWrapper> &cls, typename boost::enable_if<boost::mpl::not_< boost::is_abstract<TWrapper> > >::type *enabler = nullptr )
+void defNodeConstructor( NodeClass<T, TWrapper> &cls, typename boost::enable_if<boost::mpl::not_< std::is_abstract<TWrapper> > >::type *enabler = nullptr )
 {
 	cls.def( boost::python::init< const std::string & >( boost::python::arg( "name" ) = Gaffer::GraphComponent::defaultName<T>() ) );
 }
 
 template<typename T, typename TWrapper>
-void defNodeConstructor( NodeClass<T, TWrapper> &cls, typename boost::enable_if<boost::is_abstract<TWrapper> >::type *enabler = nullptr )
+void defNodeConstructor( NodeClass<T, TWrapper> &cls, typename boost::enable_if<std::is_abstract<TWrapper> >::type *enabler = nullptr )
 {
 	// nothing to bind for abstract classes
 }

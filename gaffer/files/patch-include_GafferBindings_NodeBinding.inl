--- include/GafferBindings/NodeBinding.inl.orig	2025-03-02 13:36:57 UTC
+++ include/GafferBindings/NodeBinding.inl
@@ -46,13 +46,13 @@ template<typename T, typename TWrapper>
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

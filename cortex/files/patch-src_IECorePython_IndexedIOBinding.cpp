--- src/IECorePython/IndexedIOBinding.cpp.orig	2026-09-10 21:49:58 UTC
+++ src/IECorePython/IndexedIOBinding.cpp
@@ -169,7 +169,7 @@
 	{
 		assert(p);
 
-		const typename T::value_type *data = &(x->readable())[0];
+		const typename T::value_type *data = x->readable().data();
 		p->write( name, data, x->readable().size() );
 	}
 
@@ -187,7 +187,7 @@
 		size_t count = entry.arrayLength();
 		typename TypedData<std::vector<T> >::Ptr x = new TypedData<std::vector<T> > ();
 		x->writable().resize( entry.arrayLength() );
-		T *data = &(x->writable()[0]);
+		T *data = x->writable().data();
 		p->read(name, data, count);
 
 		return x;

--- src/IECoreScene/PDCParticleReader.cpp.orig	2026-09-10 21:49:58 UTC
+++ src/IECoreScene/PDCParticleReader.cpp
@@ -279,7 +279,7 @@
 			{
 				IntVectorDataPtr d( new IntVectorData );
 				d->writable().resize( numParticles() );
-				readElements( &d->writable()[0], it->second.position, numParticles() );
+				readElements( d->writable().data(), it->second.position, numParticles() );
 				result = filterAttr<IntVectorData, IntVectorData>( d.get(), particlePercentage(), idAttr );
 			}
 			break;
@@ -303,7 +303,7 @@
 			{
 				DoubleVectorDataPtr d( new DoubleVectorData );
 				d->writable().resize( numParticles() );
-				readElements( &d->writable()[0], it->second.position, numParticles() );
+				readElements( d->writable().data(), it->second.position, numParticles() );
 				switch( realType() )
 				{
 					case PDCParticleReader::RealType::Native :
@@ -350,7 +350,7 @@
 				/// this resize problem only occurs with V3d, and not with V3f, or double, or even
 				/// a struct with 3 doubles in, or even a template struct with 3 doubles in.
 				d->writable().resize( numParticles(), V3d( 0 ) );
-				readElements( (double *)&d->writable()[0], it->second.position, numParticles() * 3 );
+				readElements( (double *)d->writable().data(), it->second.position, numParticles() * 3 );
 				switch( realType() )
 				{
 					case PDCParticleReader::RealType::Native :
@@ -390,14 +390,14 @@
 			{
 				DoubleVectorDataPtr doubleVec = new DoubleVectorData;
 				doubleVec->writable().resize( numParticles() );
-				readElements( &doubleVec->writable()[0], it->second.position, numParticles() );
+				readElements( doubleVec->writable().data(), it->second.position, numParticles() );
 				m_idAttribute = doubleVec;
 			}
 			if( it->second.type==IntegerArray )
 			{
 				IntVectorDataPtr intVec = new IntVectorData;
 				intVec->writable().resize( numParticles() );
-				readElements( &intVec->writable()[0], it->second.position, numParticles() );
+				readElements( intVec->writable().data(), it->second.position, numParticles() );
 				m_idAttribute = intVec;
 			}
 		}

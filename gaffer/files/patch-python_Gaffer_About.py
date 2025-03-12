--- python/Gaffer/About.py.orig	2025-03-12 17:28:43 UTC
+++ python/Gaffer/About.py
@@ -47,22 +47,22 @@ class About :
 	@staticmethod
 	def milestoneVersion() :
 
-		return !GAFFER_MILESTONE_VERSION!
+		return GAFFER_MILESTONE_VERSION
 
 	@staticmethod
 	def majorVersion() :
 
-		return !GAFFER_MAJOR_VERSION!
+		return GAFFER_MAJOR_VERSION
 
 	@staticmethod
 	def minorVersion() :
 
-		return !GAFFER_MINOR_VERSION!
+		return GAFFER_MINOR_VERSION
 
 	@staticmethod
 	def patchVersion() :
 
-		return !GAFFER_PATCH_VERSION!
+		return GAFFER_PATCH_VERSION
 
 	@staticmethod
 	def versionSuffix() :

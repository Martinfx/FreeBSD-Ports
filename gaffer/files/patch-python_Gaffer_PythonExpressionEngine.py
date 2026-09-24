--- python/Gaffer/PythonExpressionEngine.py.orig	2026-09-24 19:41:12 UTC
+++ python/Gaffer/PythonExpressionEngine.py
@@ -284,9 +284,9 @@ class _Parser( ast.NodeVisitor ) :
 					elif node.func.attr == "getFramesPerSecond" :
 						self.contextReads.add( "framesPerSecond" )
 					elif node.func.attr == "get" :
-						if not isinstance( node.args[0], ast.Str ) :
+						if not ( isinstance( node.args[0], ast.Constant ) and isinstance( node.args[0].value, str ) ) :
 							raise SyntaxError( "Context name must be a string" )
-						self.contextReads.add( node.args[0].s )
+						self.contextReads.add( node.args[0].value )
 
 		ast.NodeVisitor.generic_visit( self, node )
 
@@ -305,10 +305,10 @@ class _Parser( ast.NodeVisitor ) :
 		if node.comparators[0].id != "context" :
 			return
 
-		if not isinstance( node.left, ast.Str ) :
+		if not ( isinstance( node.left, ast.Constant ) and isinstance( node.left.value, str ) ) :
 			raise SyntaxError( "Context name must be a string" )
 
-		self.contextReads.add( node.left.s )
+		self.contextReads.add( node.left.value )
 
 	def __path( self, node ) :
 

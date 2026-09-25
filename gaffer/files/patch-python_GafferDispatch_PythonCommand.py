--- python/GafferDispatch/PythonCommand.py.orig	2026-09-24 19:41:12 UTC
+++ python/GafferDispatch/PythonCommand.py
@@ -250,9 +250,9 @@ class _Parser( ast.NodeVisitor ) :
 					elif node.func.attr == "getFramesPerSecond" :
 						self.contextReads.add( "framesPerSecond" )
 					elif node.func.attr == "get" :
-						if not isinstance( node.args[0], ast.Str ) :
+						if not ( isinstance( node.args[0], ast.Constant ) and isinstance( node.args[0].value, str ) ) :
 							raise SyntaxError( "Context name must be a string" )
-						self.contextReads.add( node.args[0].s )
+						self.contextReads.add( node.args[0].value )
 
 		ast.NodeVisitor.generic_visit( self, node )
 

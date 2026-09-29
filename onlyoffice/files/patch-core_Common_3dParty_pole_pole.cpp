--- core/Common/3dParty/pole/pole.cpp.orig	2026-09-24 21:58:50 UTC
+++ core/Common/3dParty/pole/pole.cpp
@@ -1283,19 +1283,19 @@ void DirTree::debug()
     DirEntry* e = entry( i );
     if( !e ) continue;
     std::cout << i << ": ";
-	if( !e->valid ) std::cout << L"INVALID ";
+	if( !e->valid ) std::cout << "INVALID ";
     std::wcout << e->name << L" ";
-    if( e->dir ) std::cout << L"(Dir) ";
-    else std::cout << L"(File) ";
-    std::cout << e->size << L" ";
-	std::cout << L"s:" << e->start << L" ";
-    std::cout << L"(";
-    if( e->child == End ) std::cout << L"-"; else std::cout << e->child;
+    if( e->dir ) std::cout << "(Dir) ";
+    else std::cout << "(File) ";
+    std::cout << e->size << " ";
+	std::cout << "s:" << e->start << " ";
+    std::cout << "(";
+    if( e->child == End ) std::cout << "-"; else std::cout << e->child;
     std::cout << " ";
-    if( e->prev == End ) std::cout << L"-"; else std::cout << e->prev;
-    std::cout << L":";
-    if( e->next == End ) std::cout << L"-"; else std::cout << e->next;
-    std::cout << L")";    
+    if( e->prev == End ) std::cout << "-"; else std::cout << e->prev;
+    std::cout << ":";
+    if( e->next == End ) std::cout << "-"; else std::cout << e->next;
+    std::cout << ")";    
     std::cout << std::endl;
   }
 }

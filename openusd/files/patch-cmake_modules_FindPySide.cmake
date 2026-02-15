--- cmake/modules/FindPySide.cmake.orig	2025-10-24 16:21:56 UTC
+++ cmake/modules/FindPySide.cmake
@@ -14,6 +14,9 @@ execute_process(
     COMMAND "${PYTHON_EXECUTABLE}" "-c" "import PySide6"
     RESULT_VARIABLE pySideImportResult 
 )
+
+set(PYSIDEUICBINARY "/usr/local/PySide6/bin/uic")
+
 if (pySideImportResult EQUAL 0)
     set(pySideImportResult "PySide6")
     set(pySideUIC pyside6-uic python3-pyside6-uic)
@@ -23,7 +26,7 @@ if (pySideImportResult EQUAL 1 OR PYSIDE_USE_PYSIDE2)
 if (pySideImportResult EQUAL 1 OR PYSIDE_USE_PYSIDE2)
     execute_process(
         COMMAND "${PYTHON_EXECUTABLE}" "-c" "import PySide2"
-        RESULT_VARIABLE pySideImportResult 
+        RESULT_VARIABLE pySideImportResult
     )
     if (pySideImportResult EQUAL 0)
         set(pySideImportResult "PySide2")

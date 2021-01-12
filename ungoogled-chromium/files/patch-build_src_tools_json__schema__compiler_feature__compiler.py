--- build/src/tools/json_schema_compiler/feature_compiler.py.orig	2021-01-12 12:43:39 UTC
+++ build/src/tools/json_schema_compiler/feature_compiler.py
@@ -242,7 +242,7 @@ FEATURE_GRAMMAR = ({
             'enum_map': {
                 'chromeos': 'Feature::CHROMEOS_PLATFORM',
                 'lacros': 'Feature::LACROS_PLATFORM',
-                'linux': 'Feature::LINUX_PLATFORM',
+                'bsd': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
             }

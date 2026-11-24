--- src/third_party/spirv-tools/src/utils/ggt.py.orig	2026-11-24 22:41:31 UTC
+++ src/third_party/spirv-tools/src/utils/ggt.py
@@ -24,7 +24,12 @@ from typing import Dict, List, Tuple, An
 # Find modules relative to the root directory of the repository.
 # This is needed for hermetic Bazel builds, where the Table files are bundled
 # together with this script, while keeping their relative locations.
-sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
+# Put it first rather than last: the FreeBSD port runs this with a PYTHONPATH
+# whose third_party/depot_tools has a utils.py, which would otherwise shadow
+# the utils package here ("'utils' is not a package").  Being first is not
+# enough on its own, a module beats a namespace package wherever it is on
+# sys.path, hence the utils/__init__.py the port adds as well.
+sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
 
 from utils.Table.Context import Context
 from utils.Table.IndexRange import IndexRange

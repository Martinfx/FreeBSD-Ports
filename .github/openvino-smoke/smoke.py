# Smoke test for the Python bindings of devel/openvino: the same model as
# smoke.cpp, built with the opset API, run on CPU and read back from IR.
import sys

import numpy as np
import openvino as ov
import openvino.opset13 as ops

print("openvino", ov.get_version())
core = ov.Core()
for d in core.available_devices:
    print("device", d, core.get_property(d, "FULL_DEVICE_NAME"))
print("frontends", sorted(ov.frontend.FrontEndManager().get_available_front_ends()))

x = ops.parameter([2, 4], np.float32, name="x")
w = ops.constant(np.array([[1, 0, 0], [0, 1, 0], [0, 0, 1], [1, 1, 1]], np.float32))
relu = ops.relu(ops.add(ops.matmul(x, w, False, False), ops.constant(np.array([-1, 0, 1], np.float32))))
model = ov.Model([ops.softmax(relu, 1), relu], [x], "smoke")

inp = np.array([[1, 2, 3, 4], [-1, -2, -3, -4]], np.float32)
want = np.maximum(inp @ w.get_data() + np.array([-1, 0, 1], np.float32), 0)
xml = sys.argv[1] if len(sys.argv) > 1 else "smoke_py.xml"
ov.save_model(model, xml, compress_to_fp16=False)
for what, m in (("built model", model), ("IR model", core.read_model(xml))):
    res = core.compile_model(m, "CPU")(inp)
    r, s = res[1], res[0]
    print(what, "relu", r.tolist(), "softmax", s.round(4).tolist())
    assert np.allclose(r, want), r
    e = np.exp(want - want.max(axis=1, keepdims=True))
    assert np.allclose(s, e / e.sum(axis=1, keepdims=True), atol=1e-5), s
print("python OK")

// Smoke test for the installed devel/openvino package: build a small model,
// run it on the CPU plugin, save it as IR, read it back through the IR
// frontend and run it again.
#include <openvino/openvino.hpp>
#include <openvino/op/ops.hpp>

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>

static std::shared_ptr<ov::Model> make_model() {
    auto x = std::make_shared<ov::op::v0::Parameter>(ov::element::f32, ov::Shape{2, 4});
    auto w = ov::op::v0::Constant::create(ov::element::f32, ov::Shape{4, 3},
                                          {1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1});
    auto mm = std::make_shared<ov::op::v0::MatMul>(x, w);
    auto b = ov::op::v0::Constant::create(ov::element::f32, ov::Shape{3}, {-1, 0, 1});
    auto add = std::make_shared<ov::op::v1::Add>(mm, b);
    auto relu = std::make_shared<ov::op::v0::Relu>(add);
    auto sm = std::make_shared<ov::op::v8::Softmax>(relu, 1);
    return std::make_shared<ov::Model>(ov::OutputVector{sm, relu}, ov::ParameterVector{x}, "smoke");
}

static bool run(ov::Core& core, const std::shared_ptr<ov::Model>& model, const char* what) {
    auto compiled = core.compile_model(model, "CPU");
    auto req = compiled.create_infer_request();
    std::vector<float> in = {1, 2, 3, 4, -1, -2, -3, -4};
    req.set_input_tensor(ov::Tensor(ov::element::f32, ov::Shape{2, 4}, in.data()));
    req.infer();
    // relu(x @ w + b): row 0 = [1+4-1, 2+4, 3+4+1] = [4, 6, 8], row 1 = 0
    const std::vector<float> want_relu = {4, 6, 8, 0, 0, 0};
    auto relu = req.get_output_tensor(1);
    auto sm = req.get_output_tensor(0);
    const float* r = relu.data<float>();
    const float* s = sm.data<float>();
    bool ok = true;
    for (size_t i = 0; i < want_relu.size(); i++)
        ok = ok && std::fabs(r[i] - want_relu[i]) < 1e-5f;
    for (int row = 0; row < 2; row++) {
        float sum = s[row * 3] + s[row * 3 + 1] + s[row * 3 + 2];
        ok = ok && std::fabs(sum - 1.0f) < 1e-5f;
    }
    ok = ok && std::fabs(s[3] - 1.0f / 3) < 1e-5f && s[2] > s[1] && s[1] > s[0];
    std::cout << what << ": relu =";
    for (size_t i = 0; i < 6; i++) std::cout << ' ' << r[i];
    std::cout << ", softmax =";
    for (size_t i = 0; i < 6; i++) std::cout << ' ' << s[i];
    std::cout << (ok ? "  OK" : "  WRONG") << std::endl;
    return ok;
}

int main(int argc, char** argv) {
    try {
        std::cout << ov::get_openvino_version() << std::endl;
        ov::Core core;
        for (const auto& d : core.get_available_devices())
            std::cout << "device " << d << ": "
                      << core.get_property(d, ov::device::full_name) << std::endl;
        auto model = make_model();
        bool ok = run(core, model, "built model");
        const std::string xml = argc > 1 ? argv[1] : "smoke.xml";
        ov::serialize(model, xml);
        ok = run(core, core.read_model(xml), "IR model") && ok;
        return ok ? EXIT_SUCCESS : EXIT_FAILURE;
    } catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}

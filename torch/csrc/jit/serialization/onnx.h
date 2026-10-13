#pragma once

C10_DIAGNOSTIC_PUSH_AND_IGNORED_IF_DEFINED(
    "-Winconsistent-missing-destructor-override")
C10_DIAGNOSTIC_PUSH_AND_IGNORED_IF_DEFINED("-Wsuggest-override")
C10_DIAGNOSTIC_PUSH_AND_IGNORED_IF_DEFINED(
    "-Wdeprecated-dynamic-exception-spec")
// Protobuf includes Abseil logging, whose macros collide with c10 logging.
#pragma push_macro("LOG")
#pragma push_macro("VLOG")
#pragma push_macro("LOG_IF")
#pragma push_macro("DLOG")
#undef LOG
#undef VLOG
#undef LOG_IF
#undef DLOG
#include <onnx/onnx_pb.h>
#undef LOG
#undef VLOG
#undef LOG_IF
#undef DLOG
#pragma pop_macro("DLOG")
#pragma pop_macro("LOG_IF")
#pragma pop_macro("VLOG")
#pragma pop_macro("LOG")
C10_DIAGNOSTIC_POP()
C10_DIAGNOSTIC_POP()
C10_DIAGNOSTIC_POP()
#include <torch/csrc/jit/ir/ir.h>

namespace torch::jit {

TORCH_API std::string prettyPrint(const ::ONNX_NAMESPACE::ModelProto& model);

} // namespace torch::jit

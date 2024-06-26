/*******************************************************************************
 * Copyright 2023 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/

#ifndef GRAPH_BACKEND_GRAPH_COMPILER_CORE_SRC_COMPILER_JIT_XBYAK_IR_TRANSFORM_AVX2_MASK_INDEXING_TRANSFORM_HPP
#define GRAPH_BACKEND_GRAPH_COMPILER_CORE_SRC_COMPILER_JIT_XBYAK_IR_TRANSFORM_AVX2_MASK_INDEXING_TRANSFORM_HPP

#include <compiler/config/context.hpp>
#include <compiler/ir/function_pass.hpp>

namespace dnnl {
namespace impl {
namespace graph {
namespace gc {
namespace xbyak {

/* *
 * avx2 mask indexing transformation for xbyak backend, make sure indexing is
 * not nested. So that avx2 legalize pass can handle indexing correctly.
 * */
class avx2_mask_indexing_t : public function_pass_t {
public:
  avx2_mask_indexing_t(const runtime::target_machine_t &target_machine)
      : target_machine_(target_machine) {}
  func_c operator()(func_c v) override;

private:
  const runtime::target_machine_t &target_machine_;
};

} // namespace xbyak
} // namespace gc
} // namespace graph
} // namespace impl
} // namespace dnnl

#endif

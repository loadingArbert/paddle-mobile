/* Copyright (c) 2018 PaddlePaddle Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#pragma once

#include <algorithm>
#include <vector>
#include "framework/tensor.h"
#include "operators/math/conv_func.h"

namespace paddle_mobile {
namespace operators {
namespace math {

void DepthwiseConv3x3(const framework::Tensor *input,
                      const std::vector<int> &strides,
                      const std::vector<int> &paddings,
                      const framework::Tensor *filter, framework::Tensor *bias,
                      framework::Tensor *output, bool if_bias);

void DepthwiseConv3x3s1p1(const framework::Tensor *input,
                          const framework::Tensor *filter,
                          framework::Tensor *output, framework::Tensor *bias,
                          bool if_bias, bool if_relu);

void DepthwiseConvAddBNRelu3x3s1p1(const framework::Tensor *input,
                                   const framework::Tensor *filter,
                                   framework::Tensor *output,
                                   const framework::Tensor *new_scale,
                                   const framework::Tensor *new_bias,
                                   bool if_relu);

void DepthwiseConvAddBNRelu3x3s2p1(const framework::Tensor *input,
                                   const framework::Tensor *filter,
                                   framework::Tensor *output,
                                   const framework::Tensor *new_scale,
                                   const framework::Tensor *new_bias,
                                   bool if_relu);

void DepthwiseConv3x3s2p1v2(const framework::Tensor *input,
                            const framework::Tensor *filter,
                            framework::Tensor *output, framework::Tensor *bias,
                            bool if_bias, bool if_relu);

void DepthwiseConvAddBNRelu3x3s2p1v2(const framework::Tensor *input,
                                     const framework::Tensor *filter,
                                     framework::Tensor *output,
                                     const framework::Tensor *new_scale,
                                     const framework::Tensor *new_bias,
                                     bool if_relu);

void DepthwiseConv3x3s2p0(const framework::Tensor *input,
                          const framework::Tensor *filter,
                          framework::Tensor *output, framework::Tensor *bias,
                          bool if_bias, bool if_relu);

// TODO(hjchen2) need to be implemented
// template<typename Itype, typename Otype>
// void DepthwiseConv3x3(const framework::Tensor *input,
//                      const framework::Tensor *filter,
//                      const std::vector<int> &strides,
//                      const std::vector<int> &paddings,
//                      framework::Tensor *output);

template <typename Itype, typename Otype>
void DepthwiseConv3x3S1(const framework::Tensor &input,
                        const framework::Tensor &filter,
                        const std::vector<int> &paddings,
                        framework::Tensor *output);

template <typename Itype, typename Otype>
void DepthwiseConv3x3S2(const framework::Tensor &input,
                        const framework::Tensor &filter,
                        const std::vector<int> &paddings,
                        framework::Tensor *output);

}  // namespace math
}  // namespace operators
}  // namespace paddle_mobile

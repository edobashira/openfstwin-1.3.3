
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Copyright 2005-2010 Google, Inc.
// Author: jpr@google.com (Jake Ratkiewicz)

#ifndef FST_SCRIPT_EQUAL_H_
#define FST_SCRIPT_EQUAL_H_

#include <fst/script/arg-packs.h>
#include <fst/script/fst-class.h>
#include <fst/equal.h>

namespace fst {
namespace script {

typedef args::Package<const FstClass&, const FstClass&, float> EqualInnerArgs;
typedef args::WithReturnValue<bool, EqualInnerArgs> EqualArgs;

template<class Arc>
void Equal(EqualArgs *args) {
  const Fst<Arc> &fst1 = *(args->args.arg1.GetFst<Arc>());
  const Fst<Arc> &fst2 = *(args->args.arg2.GetFst<Arc>());

  args->retval = Equal(fst1, fst2, args->args.arg3);
}

bool OPENFSTDLL Equal(const FstClass &fst1, const FstClass &fst2, //ChangedPD
           float delta = kDelta);

}  // namespace script
}  // namespace fst


#endif  // FST_SCRIPT_EQUAL_H_

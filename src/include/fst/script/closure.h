
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

#ifndef FST_SCRIPT_CLOSURE_H_
#define FST_SCRIPT_CLOSURE_H_

#include <fst/script/arg-packs.h>
#include <fst/script/fst-class.h>
#include <fst/closure.h>

namespace fst {
namespace script {

typedef args::Package<MutableFstClass*, const ClosureType> ClosureArgs;

template<class Arc>
void Closure(ClosureArgs *args) {
  MutableFst<Arc> *fst = args->arg1->GetMutableFst<Arc>();

  Closure(fst, args->arg2);
}

void OPENFSTDLL Closure(MutableFstClass *ofst, ClosureType closure_type); //ChangedPD

}  // namespace script
}  // namespace fst

#endif  // FST_SCRIPT_CLOSURE_H_

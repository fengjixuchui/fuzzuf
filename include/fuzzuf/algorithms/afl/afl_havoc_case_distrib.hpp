/*
 * fuzzuf
 * Copyright (C) 2022 Ricerca Security
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */

#ifndef FUZZUF_INCLUDE_ALGORITHMS_AFL_AFL_HAVOC_CASE_DISTRIB_HPP
#define FUZZUF_INCLUDE_ALGORITHMS_AFL_AFL_HAVOC_CASE_DISTRIB_HPP

#include <variant>

#include "fuzzuf/utils/common.hpp"
#include "fuzzuf/mutator/havoc_case.hpp"
#include "fuzzuf/optimizer/optimizer.hpp"

namespace fuzzuf::algorithm::afl::optimizer {

class AFLHavocCaseDistrib : public optimizer::Optimizer<u32> {
public:
    AFLHavocCaseDistrib();
    ~AFLHavocCaseDistrib();

    u32 CalcValue() override;
}

} // namespace fuzzuf::algorithm::afl::optimizer

#endif

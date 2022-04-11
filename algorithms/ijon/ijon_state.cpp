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

#include "fuzzuf/algorithms/ijon/ijon_state.hpp"

namespace fuzzuf::algorithm::ijon {

IJONState::IJONState(
    std::shared_ptr<const afl::AFLSetting> setting,
    std::shared_ptr<executor::AFLExecutorInterface> executor,
    std::unique_ptr<optimizer::Optimizer<u32>>&& mutop_optimizer
) : 
    afl::AFLStateTemplate<IJONTestcase>(setting, executor) {}

IJONState::~IJONState() {}

} // namespace fuzzuf::algorithm::ijon

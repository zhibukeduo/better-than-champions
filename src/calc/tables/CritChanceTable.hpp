#pragma once

#include "calc/primitives/Ratio.hpp"
#include "util/Array.hpp"

namespace calc::tables {

constexpr u8 MAX_CRIT_STAGE = 4;

using crit_stage_table = util::Array<primitives::Ratio<>, MAX_CRIT_STAGE + 1>;

constexpr crit_stage_table CRIT_CHANCE = { {
    { .num = 1, .den = 16 }, // 0
    { .num = 1, .den = 8 },
    { .num = 1, .den = 4 },
    { .num = 1, .den = 3 },
    { .num = 1, .den = 2 }, // +4
} };

} // namespace calc::tables

#pragma once

#include "calc/primitives/Ratio.hpp"
#include "calc/primitives/Stage.hpp"
#include "util/Array.hpp"

namespace calc::tables {

using acc_stage_table = util::Array<primitives::Ratio<>, primitives::Stage::COUNT>;

constexpr acc_stage_table ACCURACY_STAGE_TABLE = { {
    { .num = 3, .den = 9 }, // -6
    { .num = 3, .den = 8 },
    { .num = 3, .den = 7 },
    { .num = 3, .den = 6 },
    { .num = 3, .den = 5 },
    { .num = 3, .den = 4 },
    { .num = 3, .den = 3 }, // 0
    { .num = 4, .den = 3 },
    { .num = 5, .den = 3 },
    { .num = 6, .den = 3 },
    { .num = 7, .den = 3 },
    { .num = 8, .den = 3 },
    { .num = 9, .den = 3 }, // +6
} };

} // namespace calc::tables

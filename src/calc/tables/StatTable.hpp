#pragma once

#include "calc/primitives/Ratio.hpp"
#include "calc/primitives/Stage.hpp"
#include "util/Array.hpp"

namespace calc::tables {

using stat_stage_table = util::Array<primitives::Ratio<>, primitives::Stage::COUNT>;

constexpr stat_stage_table STAT_STAGE_TABLE = { {
    { .num = 2, .den = 8 }, // -6
    { .num = 2, .den = 7 },
    { .num = 2, .den = 6 },
    { .num = 2, .den = 5 },
    { .num = 2, .den = 4 },
    { .num = 2, .den = 3 },
    { .num = 2, .den = 2 }, //  0
    { .num = 3, .den = 2 },
    { .num = 4, .den = 2 },
    { .num = 5, .den = 2 },
    { .num = 6, .den = 2 },
    { .num = 7, .den = 2 },
    { .num = 8, .den = 2 }, // +6
} };

} // namespace calc::tables

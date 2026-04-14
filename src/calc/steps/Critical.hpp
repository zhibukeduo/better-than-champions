#pragma once

#include "calc/primitives/Ratio.hpp"
#include "calc/tables/CritChanceTable.hpp"
#include "types/aliases.hpp"
#include "util/Rng.hpp"

#include <cassert>

namespace calc::steps {

constexpr u8 CRIT_MULTIPLIER = 2;

inline auto roll_crit(u8 stage, util::Rng &rng) -> bool {
    using namespace tables;

    assert(stage <= MAX_CRIT_STAGE);
    return rng.chance(CRIT_CHANCE[stage].num, CRIT_CHANCE[stage].den);
}

constexpr auto apply_crit(u32 dmg, bool is_crit) -> u32 {
    return is_crit ? dmg * CRIT_MULTIPLIER : dmg;
}

} // namespace calc::steps

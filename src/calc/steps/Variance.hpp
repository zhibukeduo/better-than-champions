#pragma once

#include "calc/primitives/Ratio.hpp"
#include "util/Rng.hpp"

namespace calc::steps {

inline auto apply_random_variance(u32 dmg, util::Rng &rng) -> u32 {
    using primitives::Ratio;

    constexpr u8 DAMAGE_PCT_FLOOR = 85;
    constexpr u8 DAMAGE_PCT_CEIL  = 100;

    const auto roll_pct = Ratio<u8>::from_percent(rng.range(DAMAGE_PCT_FLOOR, DAMAGE_PCT_CEIL));

    return roll_pct.multiplied_by(dmg);
}

} // namespace calc::steps
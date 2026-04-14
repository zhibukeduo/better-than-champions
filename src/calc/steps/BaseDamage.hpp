#pragma once

#include "types/aliases.hpp"

#include <algorithm>
#include <limits>

namespace calc::steps {

// NOLINTNEXTLINE(bugprone-easily-swappable-parameters) - attack before defense enforced upstream
constexpr auto calc_base_damage(u8 level, u8 power, effective_stat attack, effective_stat defense)
    -> u32 {
    // NOLINTBEGIN(readability-magic-numbers) - dmg formula constants cannot be meaningfully named
    u32 dmg = (2U * level / 5U) + 2U;
    dmg     = dmg * power * attack;
    dmg     = dmg / defense;
    dmg     = (dmg / 50U) + 2U;
    // NOLINTEND(readability-magic-numbers)

    return dmg;
}

constexpr auto enforce_minimum(u32 dmg, u8 effectiveness) -> u32 {
    return (dmg == 0 && effectiveness != 0) ? 1U : dmg;
}

constexpr auto saturate_to_u16(u32 value) -> u16 {
    return static_cast<u16>(std::min(value, static_cast<u32>(std::numeric_limits<u16>::max())));
}

} // namespace calc::steps

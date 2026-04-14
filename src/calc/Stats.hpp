#pragma once

#include "calc/primitives/Ratio.hpp"
#include "calc/steps/Nature.hpp"
#include "types/aliases.hpp"
#include "types/ids/NatureStat.hpp"

namespace calc::detail {

struct StatInput {
    base_stat base;
    u8        iv;
    u8        ev;
    u8        level;
};

// NOLINTBEGIN(readability-magic-numbers) - stat formula constants cannot be meaningfully named

constexpr auto calc_hp(const StatInput &si) -> effective_stat {
    using primitives::Ratio;

    u16 inner = (2U * si.base) + si.iv + (si.ev / 4U);
    return static_cast<effective_stat>(Ratio<u8>::from_percent(si.level).multiplied_by(inner) +
                                       si.level + 10U);
}

constexpr auto calc_stat(const StatInput &si, ids::Nature nature, ids::NatureStat stat)
    -> effective_stat {
    using primitives::Ratio;

    u16 inner = static_cast<u16>(
        Ratio<u8>::from_percent(si.level).multiplied_by((2U * si.base) + si.iv + (si.ev / 4U)) +
        5U);
    return steps::apply_nature(static_cast<effective_stat>(inner), nature, stat);
}

// NOLINTEND(readability-magic-numbers)

} // namespace calc::detail

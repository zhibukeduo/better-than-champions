#pragma once

#include "calc/primitives/Ratio.hpp"
#include "types/aliases.hpp"
#include "types/ids/Nature.hpp"
#include "types/ids/NatureStat.hpp"

namespace calc::steps {

constexpr auto apply_nature(effective_stat stat, ids::Nature nature, ids::NatureStat queried)
    -> effective_stat {

    using primitives::Ratio;

    constexpr Ratio<> BOOSTED_NATURE  = { .num = 11, .den = 10 };
    constexpr Ratio<> HINDERED_NATURE = { .num = 9, .den = 10 };

    auto nature_id    = static_cast<u8>(nature);
    auto boosted_idx  = static_cast<u8>(nature_id / ids::NATURE_STAT_COUNT);
    auto hindered_idx = static_cast<u8>(nature_id % ids::NATURE_STAT_COUNT);
    auto queried_idx  = static_cast<u8>(queried);

    if (boosted_idx == hindered_idx) {
        return stat;
    }
    if (queried_idx == boosted_idx) {
        return BOOSTED_NATURE.multiplied_by(stat);
    }
    if (queried_idx == hindered_idx) {
        return HINDERED_NATURE.multiplied_by(stat);
    }

    return stat;
}

} // namespace calc::steps

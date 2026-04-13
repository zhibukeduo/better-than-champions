#pragma once

#include "types/models/Species.hpp"
#include "util/Array.hpp"

namespace data {

using species_table = util::Array<models::Species, ids::SPECIES_COUNT>;

inline constexpr species_table SPECIES_DATA_TABLE = []() -> species_table {
    using p = ids::Species;
    using t = ids::Type;
    using s = models::BaseStat;

    // clang-format off
    // NOLINTBEGIN(modernize-use-designated-initializers) - keep table within viewport
    // NOLINTBEGIN(readability-magic-numbers) - stat values are inherently magic numbers

    return {{
        { p::BULBASAUR, t::GRASS, t::POISON, s({ 45, 49, 49, 65, 65, 45 }) },
        { p::CHARMANDER, t::FIRE, t::NONE, s({ 39, 52, 43, 60, 50, 65 }) },
        { p::SQUIRTLE, t::WATER, t::NONE, s({ 44, 48, 65, 50, 64, 43 }) }
    }};

    // NOLINTEND(readability-magic-numbers)
    // NOLINTEND(modernize-use-designated-initializers)
    // clang-format on
}();

} // namespace data

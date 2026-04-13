#pragma once

#include "types/models/MonSet.hpp"
#include "util/Array.hpp"

namespace data {

using monset_table = util::Array<models::MonSet, ids::MONSET_COUNT>;

inline constexpr monset_table MONSET_DATA_TABLE = []() -> monset_table {
    using s = ids::MonSet;
    using m = ids::Move;

    // clang-format off
    // NOLINTBEGIN(modernize-use-designated-initializers) - keep table within viewport

    return {{
        { s::BULBASAUR_0, { m::TACKLE, m::LEECH_SEED, m::NONE, m::NONE } },
        { s::CHARMANDER_0, { m::SCRATCH, m::EMBER, m::NONE, m::NONE } },
        { s::SQUIRTLE_0, { m::TACKLE, m::BUBBLE, m::NONE, m::NONE } }
    }};

    // NOLINTEND(modernize-use-designated-initializers)
    // clang-format on
}();

} // namespace data
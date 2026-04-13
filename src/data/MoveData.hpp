#pragma once

#include "types/models/Move.hpp"
#include "util/Array.hpp"

namespace data {

using move_table = util::Array<models::Move, ids::MOVE_COUNT>;

inline constexpr move_table MOVE_DATA_TABLE = []() -> move_table {
    using m = ids::Move;
    using t = ids::Type;

    // clang-format off
    // NOLINTBEGIN(modernize-use-designated-initializers) - keep table within viewport
    // NOLINTBEGIN(readability-magic-numbers) - stat values are inherently magic numbers

    return {{
        { m::NONE, t::NONE, 0, 0, 0, 0 },
        { m::BUBBLE, t::WATER, 20, 100, 30, 0 },
        { m::EMBER, t::FIRE, 40, 100, 25, 0 },
        { m::LEECH_SEED, t::GRASS, 0, 90, 10, 0 },
        { m::SCRATCH, t::NORMAL, 40, 100, 35, 0 },
        { m::TACKLE, t::NORMAL, 35, 95, 35, 0 }
    }};

    // NOLINTEND(readability-magic-numbers)
    // NOLINTEND(modernize-use-designated-initializers)
    // clang-format on
}();

} // namespace data
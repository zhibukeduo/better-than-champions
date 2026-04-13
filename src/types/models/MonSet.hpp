#pragma once

#include "types/ids/MonSet.hpp"
#include "types/ids/Move.hpp"
#include "types/limits.hpp"
#include "util/Array.hpp"

namespace models {

using move_array = util::Array<ids::Move, limits::MON_MAX_MOVES>;

struct MonSet {
    ids::MonSet id;
    move_array  moves;
};

} // namespace models
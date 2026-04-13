#pragma once

#include "types/aliases.hpp"

namespace ids {

enum class Move : u8 { NONE, BUBBLE, EMBER, LEECH_SEED, SCRATCH, TACKLE, COUNT };

constexpr u8 MOVE_COUNT = static_cast<u8>(Move::COUNT);

} // namespace ids

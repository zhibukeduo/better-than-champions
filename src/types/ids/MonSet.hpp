#pragma once

#include "types/aliases.hpp"

namespace ids {

enum class MonSet : u8 { BULBASAUR_0, CHARMANDER_0, SQUIRTLE_0, COUNT };

constexpr u8 MONSET_COUNT = static_cast<u8>(MonSet::COUNT);

} // namespace ids

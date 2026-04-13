#pragma once

#include "types/aliases.hpp"

namespace ids {

enum class Species : u8 { BULBASAUR, CHARMANDER, SQUIRTLE, COUNT };

constexpr u8 SPECIES_COUNT = static_cast<u8>(Species::COUNT);

} // namespace ids

#pragma once

#include "types/aliases.hpp"

namespace ids {

enum class NatureStat : u8 { ATK, DEF, SPE, SPA, SPD, COUNT };

constexpr u8 NATURE_STAT_COUNT = static_cast<u8>(NatureStat::COUNT);

} // namespace ids

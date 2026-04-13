#pragma once

#include "types/aliases.hpp"

namespace ids {

enum class Type : u8 {
    NONE,

    NORMAL,
    FIGHTING,
    FLYING,
    POISON,
    GROUND,
    ROCK,
    BUG,
    GHOST,
    STEEL,
    FIRE,
    WATER,
    GRASS,
    ELECTRIC,
    PSYCHIC,
    ICE,
    DRAGON,
    DARK,

    COUNT
};

constexpr u8 TYPE_COUNT = static_cast<u8>(Type::COUNT);

} // namespace ids

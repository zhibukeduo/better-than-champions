#pragma once

#include "types/aliases.hpp"

namespace ids {

// clang-format off
enum class Nature : u8 {
    HARDY,  LONELY, BRAVE,   ADAMANT, NAUGHTY,
    BOLD,   DOCILE, RELAXED, IMPISH,  LAX,
    TIMID,  HASTY,  SERIOUS, JOLLY,   NAIVE,
    MODEST, MILD,   QUIET,   BASHFUL, RASH,
    CALM,   GENTLE, SASSY,   CAREFUL, QUIRKY,
    COUNT
};
// clang-format on

constexpr u8 NATURE_COUNT = static_cast<u8>(Nature::COUNT);

} // namespace ids

#pragma once

#include "types/aliases.hpp"

namespace ids {

enum class Efficacy : u8 {
    // clang-format off
    IMMUNE  = 0,
    RESIST  = 2,
    NEUTRAL = 4,
    SUPER   = 8
    // clang-format on
};

} // namespace ids

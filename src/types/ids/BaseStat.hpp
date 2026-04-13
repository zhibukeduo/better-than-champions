#pragma once

#include "types/aliases.hpp"

namespace ids {

enum class BaseStat : base_stat { HP, ATTACK, DEFENSE, SP_ATK, SP_DEF, SPEED, COUNT };

constexpr base_stat BASE_STAT_COUNT = static_cast<base_stat>(BaseStat::COUNT);

} // namespace ids

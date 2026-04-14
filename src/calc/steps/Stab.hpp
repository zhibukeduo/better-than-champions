#pragma once

#include "calc/primitives/Ratio.hpp"
#include "types/aliases.hpp"
#include "types/ids/Type.hpp"

namespace calc::steps {

struct StabMatchup {
    ids::Type move_type;
    ids::Type atk_type1;
    ids::Type atk_type2 = ids::Type::NONE;
};

constexpr auto has_stab(const StabMatchup &matchup) -> bool {
    return matchup.move_type == matchup.atk_type1 || matchup.move_type == matchup.atk_type2;
}

constexpr auto apply_stab(u32 dmg, const StabMatchup &matchup) -> u32 {
    using primitives::Ratio;

    constexpr Ratio<> STAB_BONUS = { .num = 3, .den = 2 };

    return has_stab(matchup) ? STAB_BONUS.multiplied_by(dmg) : dmg;
}

} // namespace calc::steps

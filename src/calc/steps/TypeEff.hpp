#pragma once

#include "data/TypeChart.hpp"

namespace calc::steps {

struct TypeMatchup {
    ids::Type move_type;
    ids::Type def_type1;
    ids::Type def_type2 = ids::Type::NONE;
};

constexpr u8 DUAL_NEUTRAL =
    static_cast<u8>(ids::Efficacy::NEUTRAL) * static_cast<u8>(ids::Efficacy::NEUTRAL);

constexpr auto calc_effectiveness(const TypeMatchup &params) -> u8 {
    auto atk  = static_cast<u8>(params.move_type);
    auto def1 = static_cast<u8>(params.def_type1);
    auto def2 = static_cast<u8>(params.def_type2);

    auto mult1 = static_cast<u8>(data::TYPE_CHART[atk][def1]);
    auto mult2 = static_cast<u8>(data::TYPE_CHART[atk][def2]);

    return mult1 * mult2;
}

constexpr auto apply_effectiveness(u32 dmg, u8 eff) -> u32 {
    return dmg * eff / DUAL_NEUTRAL;
}

constexpr auto is_immune(u8 eff) -> bool {
    return eff == 0;
}
constexpr auto is_super_effective(u8 eff) -> bool {
    return eff > DUAL_NEUTRAL;
}
constexpr auto is_not_very_effective(u8 eff) -> bool {
    return eff > 0 && eff < DUAL_NEUTRAL;
}

} // namespace calc::steps

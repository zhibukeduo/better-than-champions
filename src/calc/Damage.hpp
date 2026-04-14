#pragma once

#include "calc/steps/BaseDamage.hpp"
#include "calc/steps/Critical.hpp"
#include "calc/steps/Stab.hpp"
#include "calc/steps/StatStage.hpp"
#include "calc/steps/TypeEff.hpp"
#include "calc/steps/Variance.hpp"
#include "types/aliases.hpp"
#include "types/ids/Type.hpp"
#include "util/Rng.hpp"

namespace calc {

struct DamageParams {
    // attacker
    u8             level;
    effective_stat attack;
    stat_stage     attack_stage = 0;
    ids::Type      atk_type1;
    ids::Type      atk_type2 = ids::Type::NONE;

    // defender
    effective_stat defense;
    stat_stage     defense_stage = 0;
    ids::Type      def_type1;
    ids::Type      def_type2 = ids::Type::NONE;

    // move
    u8        power;
    ids::Type move_type;

    // modifiers
    u8 crit_stage = 0;
};

struct DamageResult {
    u16  damage        = 0;
    u8   effectiveness = steps::DUAL_NEUTRAL;
    bool critical      = false;
};

inline auto calc_damage(const DamageParams &params, util::Rng &rng) -> DamageResult {
    using namespace steps;

    DamageResult result;

    // 1. critical hit
    result.critical = roll_crit(params.crit_stage, rng);

    // 2. resolve stat stages (crit-aware)
    auto atk = crit_aware_stage(params.attack, params.attack_stage, result.critical, true);
    auto def = crit_aware_stage(params.defense, params.defense_stage, result.critical, false);
    if (def == 0) {
        def = 1;
    }

    // 3. base damage
    u32 dmg = calc_base_damage(params.level, params.power, atk, def);

    // 4. critical multiplier
    dmg = apply_crit(dmg, result.critical);

    // 5. STAB
    dmg = apply_stab(dmg, { .move_type = params.move_type,
                            .atk_type1 = params.atk_type1,
                            .atk_type2 = params.atk_type2 });

    // 6. type effectiveness
    result.effectiveness = calc_effectiveness({ .move_type = params.move_type,
                                                .def_type1 = params.def_type1,
                                                .def_type2 = params.def_type2 });
    dmg                  = apply_effectiveness(dmg, result.effectiveness);

    // 7. immunity gate
    if (is_immune(result.effectiveness)) {
        return result;
    }

    // 8. random variance
    dmg = apply_random_variance(dmg, rng);

    // 9. minimum damage
    dmg = enforce_minimum(dmg, result.effectiveness);

    result.damage = saturate_to_u16(dmg);
    return result;
}

} // namespace calc

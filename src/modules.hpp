#pragma once

// temporary: bring every tu into build for tooling to better pick up on

#include "calc/Damage.hpp"
#include "calc/HitCheck.hpp"
#include "calc/Stats.hpp"
#include "data/MonSetData.hpp"
#include "data/MoveData.hpp"
#include "data/SpeciesData.hpp"
#include "data/TypeChart.hpp"

inline auto use_all_modules() -> void {
    (void)data::TYPE_CHART;
    (void)data::SPECIES_DATA_TABLE;
    (void)data::MOVE_DATA_TABLE;
    (void)data::MONSET_DATA_TABLE;

    (void)calc::calc_damage;
    (void)calc::check_hit;
    (void)calc::detail::calc_hp;
    (void)calc::detail::calc_stat;
}

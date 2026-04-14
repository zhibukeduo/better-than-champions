#pragma once

#include "calc/tables/StatTable.hpp"

namespace calc::steps {

constexpr auto apply_stat_stage(effective_stat stat, primitives::Stage stage) -> effective_stat {
    using tables::STAT_STAGE_TABLE;

    const auto &ratio = STAT_STAGE_TABLE[stage.index()];
    return ratio.multiplied_by(stat);
}

constexpr auto crit_aware_stage(effective_stat stat, stat_stage raw, bool is_crit, bool is_attack)
    -> effective_stat {

    using primitives::Stage;

    if (is_crit) {
        // ignore negative attack stages and positive defense stages
        bool favourable = is_attack ? (raw > 0) : (raw < 0);
        if (!favourable) {
            return stat;
        }
    }
    return apply_stat_stage(stat, Stage{ raw });
}

} // namespace calc::steps

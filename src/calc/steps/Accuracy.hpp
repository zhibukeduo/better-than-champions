#pragma once

#include "calc/primitives/Accuracy.hpp"
#include "calc/tables/AccuracyTable.hpp"

namespace calc::steps {

constexpr auto resolve_accuracy(primitives::Accuracy base, primitives::Stage accuracy_stage,
                                primitives::Stage evasion_stage) -> primitives::Accuracy {
    using primitives::Accuracy;
    using tables::ACCURACY_STAGE_TABLE;

    if (base.is_guaranteed()) {
        return Accuracy::guaranteed();
    }

    u8 computed_accuracy = base.percent().value();

    const auto &attackers_accuracy = ACCURACY_STAGE_TABLE[accuracy_stage.index()];
    const auto &defenders_evasion  = ACCURACY_STAGE_TABLE[evasion_stage.index()];

    computed_accuracy = attackers_accuracy.multiplied_by(computed_accuracy);
    computed_accuracy = defenders_evasion.divided_by(computed_accuracy);

    return Accuracy::percentage(computed_accuracy);
}

} // namespace calc::steps

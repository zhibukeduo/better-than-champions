#pragma once

#include "calc/steps/Accuracy.hpp"
#include "util/Rng.hpp"

namespace calc {

inline auto check_hit(primitives::Accuracy base, primitives::Stage acc_stage,
                      primitives::Stage eva_stage, util::Rng &rng) -> bool {

    using primitives::Percent;

    if (base.is_guaranteed()) {
        return true;
    }

    auto effective = steps::resolve_accuracy(base, acc_stage, eva_stage);
    return rng.chance(effective.percent().value(), Percent::MAX);
}

} // namespace calc

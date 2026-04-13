#pragma once

#include "types/ids/Efficacy.hpp"
#include "types/ids/Type.hpp"
#include "util/Array.hpp"

namespace data {

using type_chart_row = util::Array<ids::Efficacy, ids::TYPE_COUNT>;
using type_chart     = util::Array<type_chart_row, ids::TYPE_COUNT>;

inline constexpr type_chart TYPE_CHART = []() -> type_chart {
    // NOLINTBEGIN(readability-identifier-length) - keep type chart definition sane
    constexpr auto I = ids::Efficacy::IMMUNE;
    constexpr auto R = ids::Efficacy::RESIST;
    constexpr auto N = ids::Efficacy::NEUTRAL;
    constexpr auto S = ids::Efficacy::SUPER;
    // NOLINTEND(readability-identifier-length)

    // clang-format off

    return type_chart {{
    //        NON NOR FIG FLY POI GRO ROC BUG GHO STE FIR WAT GRA ELE PSY ICE DRA DAR
    /*NON*/ { N,  N,  N,  N,  N,  N,  N,  N,  N,  N,  N,  N,  N,  N,  N,  N,  N,  N },
    /*NOR*/ { N,  N,  N,  N,  N,  N,  R,  N,  I,  R,  N,  N,  N,  N,  N,  N,  N,  N },
    /*FIG*/ { N,  S,  N,  R,  R,  N,  S,  R,  I,  S,  N,  N,  N,  N,  R,  S,  N,  S },
    /*FLY*/ { N,  N,  S,  N,  N,  N,  R,  S,  N,  R,  N,  N,  S,  R,  N,  N,  N,  N },
    /*POI*/ { N,  N,  N,  N,  R,  R,  R,  N,  R,  I,  N,  N,  S,  N,  N,  N,  N,  N },
    /*GRO*/ { N,  N,  N,  I,  S,  N,  S,  R,  N,  S,  S,  N,  R,  S,  N,  N,  N,  N },
    /*ROC*/ { N,  N,  R,  S,  N,  R,  N,  S,  N,  R,  S,  N,  N,  N,  N,  S,  N,  N },
    /*BUG*/ { N,  N,  R,  R,  R,  N,  N,  N,  R,  R,  R,  N,  S,  N,  S,  N,  N,  S },
    /*GHO*/ { N,  I,  N,  N,  N,  N,  N,  N,  S,  R,  N,  N,  N,  N,  S,  N,  N,  R },
    /*STE*/ { N,  N,  N,  N,  N,  N,  S,  N,  N,  R,  R,  R,  N,  R,  N,  S,  N,  N },
    /*FIR*/ { N,  N,  N,  N,  N,  N,  R,  S,  N,  S,  R,  R,  S,  N,  N,  S,  R,  N },
    /*WAT*/ { N,  N,  N,  N,  N,  S,  S,  N,  N,  N,  S,  R,  R,  N,  N,  N,  R,  N },
    /*GRA*/ { N,  N,  N,  R,  R,  S,  S,  R,  N,  R,  R,  S,  R,  N,  N,  N,  R,  N },
    /*ELE*/ { N,  N,  N,  S,  N,  I,  N,  N,  N,  N,  N,  S,  R,  R,  N,  N,  R,  N },
    /*PSY*/ { N,  N,  S,  N,  S,  N,  N,  N,  N,  R,  N,  N,  N,  N,  R,  N,  N,  I },
    /*ICE*/ { N,  N,  N,  S,  N,  S,  N,  N,  N,  R,  R,  R,  S,  N,  N,  R,  S,  N },
    /*DRA*/ { N,  N,  N,  N,  N,  N,  N,  N,  N,  R,  N,  N,  N,  N,  N,  N,  S,  N },
    /*DAR*/ { N,  N,  R,  N,  N,  N,  N,  N,  S,  R,  N,  N,  N,  N,  S,  N,  N,  R },
    }};

    // clang-format on
}();

} // namespace data

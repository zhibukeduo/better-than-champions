#pragma once

#include "types/ids/Species.hpp"
#include "types/ids/Type.hpp"
#include "types/models/BaseStat.hpp"

namespace models {

struct Species {
    ids::Species id;
    ids::Type    type1;
    ids::Type    type2;

    BaseStat stats;
};

} // namespace models

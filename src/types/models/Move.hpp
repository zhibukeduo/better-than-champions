#pragma once

#include "types/ids/Move.hpp"
#include "types/ids/Type.hpp"

namespace models {

struct Move {
    ids::Move id;
    ids::Type type;

    u8 power;
    u8 accuracy;
    u8 pp;
    s8 priority;
};

} // namespace models

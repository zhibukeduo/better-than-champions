#include "data/TypeChart.hpp"

#include <doctest/doctest.h>

using ids::Efficacy;
using ids::Type;

static constexpr auto eff(Type atk, Type def) -> Efficacy {
    return data::TYPE_CHART[static_cast<u8>(atk)][static_cast<u8>(def)];
}

TEST_CASE("TypeChart: Gen3-scoped ghost/dark vs steel") {
    CHECK(eff(Type::GHOST, Type::STEEL) == Efficacy::RESIST);
    CHECK(eff(Type::DARK, Type::STEEL) == Efficacy::RESIST);
}

TEST_CASE("TypeChart: Standard immunities") {
    CHECK(eff(Type::NORMAL, Type::GHOST) == Efficacy::IMMUNE);
    CHECK(eff(Type::FIGHTING, Type::GHOST) == Efficacy::IMMUNE);
    CHECK(eff(Type::POISON, Type::STEEL) == Efficacy::IMMUNE);
    CHECK(eff(Type::GROUND, Type::FLYING) == Efficacy::IMMUNE);
    CHECK(eff(Type::ELECTRIC, Type::GROUND) == Efficacy::IMMUNE);
    CHECK(eff(Type::PSYCHIC, Type::DARK) == Efficacy::IMMUNE);
}

#include "calc/steps/Nature.hpp"
#include "types/ids/Nature.hpp"
#include "types/ids/NatureStat.hpp"

#include <doctest/doctest.h>

// if ids/Nature.hpp or ids/NatureStat.hpp is modified, everything *WILL* explode. :)
// ... so if you saw this test suit fail, don't break the divmod math downstream
// ... Pls man, it's a clever abstraction TT

using ids::Nature;
using ids::NatureStat;

TEST_CASE("NatureStat: count and ordering") {
    CHECK(ids::NATURE_STAT_COUNT == 5);

    CHECK(static_cast<u8>(NatureStat::ATK) == 0);
    CHECK(static_cast<u8>(NatureStat::DEF) == 1);
    CHECK(static_cast<u8>(NatureStat::SPE) == 2);
    CHECK(static_cast<u8>(NatureStat::SPA) == 3);
    CHECK(static_cast<u8>(NatureStat::SPD) == 4);
}

TEST_CASE("Nature: enum ordering") {
    CHECK(ids::NATURE_COUNT == 25);

    // check the first element down column 0
    CHECK(static_cast<u8>(Nature::HARDY) == 0);
    CHECK(static_cast<u8>(Nature::BOLD) == 5);
    CHECK(static_cast<u8>(Nature::TIMID) == 10);
    CHECK(static_cast<u8>(Nature::MODEST) == 15);
    CHECK(static_cast<u8>(Nature::CALM) == 20);
}

TEST_CASE("Nature: neutral natures are on the diagonal") {
    // diagonal entries have boosted == hindered, so no effect
    constexpr effective_stat STAT = 100;

    CHECK(calc::steps::apply_nature(STAT, Nature::HARDY, NatureStat::ATK) == STAT);
    CHECK(calc::steps::apply_nature(STAT, Nature::DOCILE, NatureStat::DEF) == STAT);
    CHECK(calc::steps::apply_nature(STAT, Nature::SERIOUS, NatureStat::SPE) == STAT);
    CHECK(calc::steps::apply_nature(STAT, Nature::BASHFUL, NatureStat::SPA) == STAT);
    CHECK(calc::steps::apply_nature(STAT, Nature::QUIRKY, NatureStat::SPD) == STAT);
}

TEST_CASE("Nature: ADAMANT is +Atk -SpA") {
    constexpr effective_stat STAT = 100;

    CHECK(calc::steps::apply_nature(STAT, Nature::ADAMANT, NatureStat::ATK) == 110);
    CHECK(calc::steps::apply_nature(STAT, Nature::ADAMANT, NatureStat::SPA) == 90);
    CHECK(calc::steps::apply_nature(STAT, Nature::ADAMANT, NatureStat::DEF) == STAT);
    CHECK(calc::steps::apply_nature(STAT, Nature::ADAMANT, NatureStat::SPD) == STAT);
    CHECK(calc::steps::apply_nature(STAT, Nature::ADAMANT, NatureStat::SPE) == STAT);
}

TEST_CASE("Nature: MODEST is +SpA -Atk") {
    constexpr effective_stat STAT = 100;

    CHECK(calc::steps::apply_nature(STAT, Nature::MODEST, NatureStat::SPA) == 110);
    CHECK(calc::steps::apply_nature(STAT, Nature::MODEST, NatureStat::ATK) == 90);
    CHECK(calc::steps::apply_nature(STAT, Nature::MODEST, NatureStat::DEF) == STAT);
}

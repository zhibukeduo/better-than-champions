#include "types/models/BaseStat.hpp"

#include <doctest/doctest.h>

TEST_CASE("BaseStat: constructor ordering") {
    const models::base_stat_array stats = {1, 2, 3, 4, 5, 6};
    const models::BaseStat        phony_mon(stats);

    CHECK(phony_mon.hp() == 1);
    CHECK(phony_mon.attack() == 2);
    CHECK(phony_mon.defense() == 3);
    CHECK(phony_mon.sp_atk() == 4);
    CHECK(phony_mon.sp_def() == 5);
    CHECK(phony_mon.speed() == 6);
}

#include "types/models/StatBlock.hpp"
#include "util/Array.hpp"

#include <doctest/doctest.h>

// catch misordering shenanigans at the constructor seam

TEST_CASE("StatBlock: constructor ordering") {
    const util::Array<base_stat, ids::BASE_STAT_COUNT> stats = {{ 1, 2, 3, 4, 5, 6 }};
    const models::base_stats phony_mon(stats);

    CHECK(phony_mon.hp() == 1);
    CHECK(phony_mon.attack() == 2);
    CHECK(phony_mon.defense() == 3);
    CHECK(phony_mon.sp_atk() == 4);
    CHECK(phony_mon.sp_def() == 5);
    CHECK(phony_mon.speed() == 6);
}

#pragma once

#include "types/ids/BaseStat.hpp"
#include "util/Array.hpp"

#include <concepts>

namespace models {

template <std::unsigned_integral T> class StatBlock {
  public:
    constexpr StatBlock(const util::Array<T, ids::BASE_STAT_COUNT> &stats) : _stats(stats) {}

    [[nodiscard]] auto operator[](ids::BaseStat stat) const -> T {
        return _stats[static_cast<u8>(stat)];
    }

    [[nodiscard]] auto hp() const -> T { return (*this)[ids::BaseStat::HP]; }
    [[nodiscard]] auto attack() const -> T { return (*this)[ids::BaseStat::ATTACK]; }
    [[nodiscard]] auto defense() const -> T { return (*this)[ids::BaseStat::DEFENSE]; }
    [[nodiscard]] auto sp_atk() const -> T { return (*this)[ids::BaseStat::SP_ATK]; }
    [[nodiscard]] auto sp_def() const -> T { return (*this)[ids::BaseStat::SP_DEF]; }
    [[nodiscard]] auto speed() const -> T { return (*this)[ids::BaseStat::SPEED]; }

  private:
    util::Array<T, ids::BASE_STAT_COUNT> _stats;
};

using base_stats      = StatBlock<base_stat>;
using effective_stats = StatBlock<effective_stat>;

} // namespace models

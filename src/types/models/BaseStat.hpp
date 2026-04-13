#pragma once

#include "types/aliases.hpp"
#include "types/ids/BaseStat.hpp"
#include "util/Array.hpp"

namespace models {

using base_stat_array = util::Array<base_stat, ids::BASE_STAT_COUNT>;

class BaseStat {
  public:
    constexpr BaseStat(const base_stat_array &stats) { _stats = stats; }

    [[nodiscard]] auto operator[](ids::BaseStat stat) const -> base_stat {
        return _stats[static_cast<base_stat>(stat)];
    }

    [[nodiscard]] auto hp() const -> base_stat { return (*this)[ids::BaseStat::HP]; }
    [[nodiscard]] auto attack() const -> base_stat { return (*this)[ids::BaseStat::ATTACK]; }
    [[nodiscard]] auto defense() const -> base_stat { return (*this)[ids::BaseStat::DEFENSE]; }
    [[nodiscard]] auto sp_atk() const -> base_stat { return (*this)[ids::BaseStat::SP_ATK]; }
    [[nodiscard]] auto sp_def() const -> base_stat { return (*this)[ids::BaseStat::SP_DEF]; }
    [[nodiscard]] auto speed() const -> base_stat { return (*this)[ids::BaseStat::SPEED]; }

  private:
    base_stat_array _stats;
};

} // namespace models

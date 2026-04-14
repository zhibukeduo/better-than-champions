#pragma once

#include "types/aliases.hpp"

#include <algorithm>

namespace calc::primitives {

class Stage {
  private:
    static constexpr stat_stage MIN  = -6;
    static constexpr stat_stage MAX  = 6;
    static constexpr stat_stage NONE = 0;

  public:
    static constexpr stat_stage COUNT = MAX - MIN + 1;

    constexpr Stage() : Stage(NONE) {}
    constexpr Stage(stat_stage stage) : _stage(clamp(stage)) {}

    [[nodiscard]] constexpr auto value() const -> stat_stage { return _stage; }
    [[nodiscard]] constexpr auto index() const -> u8 { return static_cast<u8>(_stage - MIN); }

    auto modify_by(stat_stage stage) -> void {
        _stage = clamp(static_cast<stat_stage>(_stage + stage));
    }

  private:
    stat_stage _stage;

    static constexpr auto clamp(stat_stage stage) -> stat_stage {
        return std::clamp(stage, MIN, MAX);
    }
};

} // namespace calc::primitives

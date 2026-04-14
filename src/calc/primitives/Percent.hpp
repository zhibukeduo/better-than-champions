#pragma once

#include "types/aliases.hpp"

#include <cassert>

namespace calc::primitives {

class Percent {
  public:
    static constexpr u8 MAX = 100;

    [[nodiscard]] auto value() const -> u8 { return _value; }

    [[nodiscard]] static constexpr auto from(u8 value) -> Percent {
        assert(value <= MAX);
        return { value };
    }

  private:
    constexpr Percent(u8 value) : _value(value) {}

    u8 _value;
};

} // namespace calc::primitives
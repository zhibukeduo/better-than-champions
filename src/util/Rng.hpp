#pragma once

#include "types/aliases.hpp"

namespace util {

class Rng {
    static constexpr u32 MULTIPLIER   = 0x41C64E6DU;
    static constexpr u32 INCREMENT    = 0x00006073U;
    static constexpr int OUTPUT_SHIFT = 16;

  public:
    constexpr explicit Rng(u32 seed) : _seed(seed) {}

    auto range(u16 lo, u16 hi) -> u16 { return static_cast<u16>((next() % (hi - lo + 1)) + lo); }

    auto chance(u16 numerator, u16 denominator) -> bool {
        return (next() % denominator) < numerator;
    }

    [[nodiscard]] auto seed() const -> u32 { return _seed; }

  private:
    auto next() -> u16 {
        _seed = (_seed * MULTIPLIER) + INCREMENT;
        return static_cast<u16>(_seed >> OUTPUT_SHIFT);
    }

    u32 _seed;
};

} // namespace util

#pragma once

#include "types/aliases.hpp"

#include <cassert>
#include <concepts>
#include <limits>

namespace calc::primitives {

template <std::unsigned_integral T = u8> struct Ratio {
    T num;
    T den;

    template <typename V> [[nodiscard]] constexpr auto multiplied_by(V value) const -> V {
        assert(num == 0 || value <= std::numeric_limits<V>::max() / num);
        return static_cast<V>(value * num / den);
    }

    [[nodiscard]] static constexpr auto from_percent(T pct) -> Ratio {
        return { .num = pct, .den = 100 }; // NOLINT(readability-magic-numbers) - definitional to %
    }

    template <typename V> [[nodiscard]] constexpr auto divided_by(V value) const -> V {
        assert(den == 0 || value <= std::numeric_limits<V>::max() / den);
        return static_cast<V>(value * den / num);
    }
};

template <typename T> Ratio(T, T) -> Ratio<T>;

} // namespace calc::primitives

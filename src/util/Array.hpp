#pragma once

#include "types/aliases.hpp"

namespace util {

template <typename T, u8 N> struct Array {
    T data[N]; // NOLINT(modernize-avoid-c-arrays) - lol...

    constexpr auto operator[](u8 idx) -> T & { return data[idx]; }
    constexpr auto operator[](u8 idx) const -> const T & { return data[idx]; }
};

} // namespace util

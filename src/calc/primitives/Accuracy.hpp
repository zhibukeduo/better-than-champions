#pragma once

#include "calc/primitives/Percent.hpp"

#include <algorithm>
#include <cassert>

namespace calc::primitives {

class Accuracy {
  public:
    enum class Kind : u8 { PERCENTAGE, GUARANTEED };

    [[nodiscard]] static constexpr auto guaranteed() -> Accuracy {
        return Accuracy{ Kind::GUARANTEED, Percent::from(0) };
    }

    [[nodiscard]] static constexpr auto percentage(u16 value) -> Accuracy {
        return Accuracy{ Kind::PERCENTAGE,
                         Percent::from(static_cast<u8>(std::min<u16>(value, Percent::MAX))) };
    }

    [[nodiscard]] constexpr auto is_guaranteed() const -> bool { return _kind == Kind::GUARANTEED; }

    [[nodiscard]] constexpr auto percent() const -> Percent {
        assert(_kind == Kind::PERCENTAGE); // see, misuse is impossible to observe :D  ◄───┐
        return _value;                     //                                              │
    }

  private:                                       //                                        │
    constexpr Accuracy(Kind kind, Percent value) //                                        │
        : _kind(kind), _value(value) {}          //                                        │
                                                 //                                        │
    Kind    _kind;                               //                                        │
    Percent _value; // who needs std::variant  ────────────────────────────────────────────┘
};

} // namespace calc::primitives

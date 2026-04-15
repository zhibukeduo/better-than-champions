# Pokemon: Better Than Champions

a pokemon battle simulator for that special graphing calculator in your life.

you should also check out the [banner artwork](src/main.cpp).

## cmake+make??

develop/test on host with CMake, cross-compile intended target with make

... because setting up tooling for embedded is a pita.

## deps

| thing you need installed                                        | for?         |
| --------------------------------------------------------------- | ------------ |
| CMake >= 3.20                                                   | host build   |
| Ninja                                                           | host build   |
| clang++ (C++20)                                                 | host build   |
| [doctest](https://github.com/doctest/doctest) v2.5.1            | tests        |
| [CE dev toolchain](https://ce-programming.github.io/toolchain/) | CE build     |

## building

```sh
# host
cmake --preset default
cmake --build build
# tests
./build/tests

# ce
make
```

## git hooks

cmake sets `core.hooksPath` to `hooks/`.

pre-commit hook runs formatting, linting, the host build, its tests, and ce build.

let it. :)
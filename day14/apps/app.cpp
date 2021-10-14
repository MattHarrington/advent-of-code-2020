#include <fmt/core.h>

#include "lib.hpp"

int main()
{
    auto puzzle_input{ read_input("day14_input.txt") };

    const auto part1_answer{ part1(puzzle_input) };
    fmt::print("Part 1 answer: {}\n", part1_answer);

    return 0;
}

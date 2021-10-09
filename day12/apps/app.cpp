#include <fmt/core.h>

#include "lib.hpp"

int main()
{
    auto puzzle_input{ read_input("day12_input.txt") };

    const auto part1_answer{ part1(puzzle_input) };
    fmt::print("Part 1 answer: {}\n", part1_answer);

    const auto part2_answer{ part2(puzzle_input) };
    fmt::print("Part 2 answer: {}\n", part2_answer);

    return 0;
}

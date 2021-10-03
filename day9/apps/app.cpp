#include <fmt/core.h>

#include "lib.hpp"

int main()
{
    const auto puzzle_input{ read_input("day9_input.txt") };

    const auto part1_answer{ part1(25, puzzle_input) };
    fmt::print("Part 1 answer: {}\n", part1_answer);

    const auto part2_answer{ part2(part1_answer, puzzle_input) };
    fmt::print("Part 2 answer: {}\n", part2_answer);
    return 0;
}

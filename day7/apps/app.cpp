#include <fmt/core.h>

#include "lib.hpp"

int main()
{
    const auto puzzle_input{ read_input("day7_input.txt") };
    const auto graph{ Graph(puzzle_input) };

    const auto part1_answer{ part1(graph) };
    fmt::print("Part 1 answer: {}\n", part1_answer);

    const auto part2_answer{ part2(graph) };
    fmt::print("Part 2 answer: {}\n", part2_answer);

    return 0;
}

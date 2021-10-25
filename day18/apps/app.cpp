#include <cassert>
#include <fmt/core.h>

#include "lib.hpp"

int main()
{
    const auto puzzle_input{ read_input("day18_input.txt") };

    const auto part1_answer{ part1(puzzle_input) };
    fmt::print("Part 1 answer: {}\n", part1_answer);
    assert(part1_answer == 401);

    //const auto part2_answer{ part2(puzzle_input) };
    //fmt::print("Part 2 answer: {}\n", part2_answer);
    //assert(part2_answer == 2224);

    return 0;
}

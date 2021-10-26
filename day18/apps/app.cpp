#include <cassert>
#include <fmt/core.h>

#include "lib.hpp"

int main()
{
    auto puzzle_input{ read_input("day18_input.txt") };

    const auto part1_answer{ solve_part(puzzle_input, Part::one) };
    fmt::print("Part 1 answer: {}\n", part1_answer);
    assert(part1_answer == 1'402'255'785'165);

    const auto part2_answer{ solve_part(puzzle_input, Part::two) };
    fmt::print("Part 2 answer: {}\n", part2_answer);
    assert(part2_answer == 119'224'703'255'966);

    return 0;
}

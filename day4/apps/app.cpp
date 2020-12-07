#include <fmt/core.h>

#include "lib.hpp"

int main()
{
    const auto puzzle_input{ read_input("day4_input.txt") };

    const auto part1_answer{ process_passports(puzzle_input, problem_part::one) };
    fmt::print("Part 1 answer: {}\n", part1_answer);

    const auto part2_answer{ process_passports(puzzle_input, problem_part::two) };
    fmt::print("Part2 answer: {}\n", part2_answer);

    return 0;
}

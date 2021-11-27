#include <cassert>
#include <fmt/core.h>

#include "lib.hpp"

int main()
{
    auto puzzle_input{ read_input("day19_input.txt") };
    const auto messages{ puzzle_input.second };

    const auto r_part1{ get_regex_from_rules(puzzle_input.first, Part::one) };
    const auto part1_answer{ count_matches(messages, r_part1) };
    fmt::print("Part 1 answer: {}\n", part1_answer);
    assert(part1_answer == 109);

    const auto r_part2{ get_regex_from_rules(puzzle_input.first, Part::two) };
    const auto part2_answer{ count_matches(messages, r_part2) };
    fmt::print("Part 2 answer: {}\n", part2_answer);
    assert(part1_answer == 301);

    return 0;
}

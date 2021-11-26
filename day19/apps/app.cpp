#include <cassert>
#include <fmt/core.h>

#include "lib.hpp"

int main()
{
    auto puzzle_input{ read_input("day19_input.txt") };

    const auto r{ get_regex_from_rules(puzzle_input.first) };
    const auto messages{ puzzle_input.second };
    const auto part1_answer{ part1(messages, r) };

    fmt::print("Part 1 answer: {}\n", part1_answer);
    assert(part1_answer == 109);

    return 0;
}

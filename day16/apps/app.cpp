#include <cassert>
#include <fmt/core.h>

#include "lib.hpp"

int main()
{
    auto [puzzle_rules, puzzle_ticket, puzzle_nearby_tickets] = read_input("day16_input.txt");

    const auto part1_answer{ part1("day16_input.txt") };
    fmt::print("Part 1 answer: {}\n", part1_answer);
    assert(part1_answer == 25'895);

    const auto part2_answer{ part2(puzzle_rules, puzzle_ticket, puzzle_nearby_tickets) };
    fmt::print("Part 2 answer: {}\n", part2_answer);
    assert(part2_answer == 5'865'723'727'753);

    return 0;
}

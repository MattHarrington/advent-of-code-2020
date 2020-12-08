#include <fmt/core.h>

#include "lib.hpp"

int main()
{
    const auto puzzle_input{ read_input("day5_input.txt") };

    auto seat_ids{ get_seat_ids(puzzle_input) };

    // Part 1

    const auto part1_answer{ get_max_seat_id(seat_ids) };
    fmt::print("Part 1 answer: {}\n", part1_answer);

    // Part 2

    const auto part2_answer{ get_missing_seat_id(seat_ids) };
    fmt::print("Part2 answer: {}\n", part2_answer);

    return 0;
}

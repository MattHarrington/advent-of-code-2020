#include <vector>
#include <fmt/core.h>

#include "lib.hpp"

int main()
{
    const auto input{ read_input("day1_input.txt") };

    fmt::print("Part 1 answer: {}\n", part1(input));
    fmt::print("Part 2 answer: {}\n", part2(input));

    return 0;
}

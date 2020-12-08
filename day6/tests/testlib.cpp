#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include "lib.hpp"

TEST_CASE("Sample input file length should be 15")
{
    const auto puzzle_input{ read_input("day6_sample_input.txt") };
    CHECK(puzzle_input.size() == 15);
}

TEST_CASE("Input file length should be 2040")
{
    const auto puzzle_input{ read_input("day6_input.txt") };
    CHECK(puzzle_input.size() == 2040);
}

TEST_CASE("Part 1 answer with sample input should be 11")
{
    const auto puzzle_input{ read_input("day6_sample_input.txt") };
    const auto part1_answer{ part1(puzzle_input) };
    CHECK(part1_answer == 11);
}

TEST_CASE("Part 1 answer should be 6335")
{
    const auto puzzle_input{ read_input("day6_input.txt") };
    const auto part1_answer{ part1(puzzle_input) };
    CHECK(part1_answer == 6335);
}

TEST_CASE("Part 2 answer with sample input should be 6")
{
    const auto puzzle_input{ read_input("day6_sample_input.txt") };
    const auto part2_answer{ part2(puzzle_input) };
    CHECK(part2_answer == 6);
}

TEST_CASE("Part 2 answer should be 3392")
{
    const auto puzzle_input{ read_input("day6_input.txt") };
    const auto part2_answer{ part2(puzzle_input) };
    CHECK(part2_answer == 3392);
}

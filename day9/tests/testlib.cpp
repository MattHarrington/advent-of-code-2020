#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include "lib.hpp"

const auto sample_input{ read_input("day9_sample_input.txt") };
const auto puzzle_input{ read_input("day9_input.txt") };

TEST_CASE("Sample input file length should be 20")
{
    CHECK(sample_input.size() == 20);
}

TEST_CASE("Puzzle input file length should be 1000")
{
    CHECK(puzzle_input.size() == 1000);
}

TEST_CASE("Part 1 answer with sample input should be 127")
{
    CHECK(part1(5, sample_input) == 127);
}

TEST_CASE("Part 1 answer with puzzle input should be 14'144'619")
{
    auto part_1_answer{ part1(25, puzzle_input) };
    CHECK(part_1_answer == 14'144'619);
}

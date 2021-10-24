#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include "lib.hpp"

const auto sample_input{ read_input("day17_sample_input.txt") };
const auto puzzle_input{ read_input("day17_input.txt") };

TEST_CASE("Sample input should contain 3 lines")
{
    CHECK(sample_input.size() == 3);
}

TEST_CASE("Puzzle input should contain 8 lines")
{
    CHECK(puzzle_input.size() == 8);
}

TEST_CASE("Part 1 answer with sample data should be 112")
{
    const auto part1_answer{ part1(sample_input) };
    CHECK(part1_answer == 112);
}

TEST_CASE("Part 1 answer with puzzle data should be 401")
{
    const auto part1_answer{ part1(puzzle_input) };
    CHECK(part1_answer == 401);
}

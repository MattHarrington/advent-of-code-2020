#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include "lib.hpp"

const auto sample_input{ read_input("day12_sample_input.txt") };
const auto puzzle_input{ read_input("day12_input.txt") };

TEST_CASE("Sample input file length should be 5")
{
    CHECK(sample_input.size() == 5);
}

TEST_CASE("Puzzle input file length should be 781")
{
    CHECK(puzzle_input.size() == 781);
}

TEST_CASE("Part 1 answer with sample input should be 25")
{
    auto part1_answer{ part1(sample_input) };
    CHECK(part1_answer == 25);
}

TEST_CASE("Part 1 answer with puzzle input should be 1565")
{
    auto part1_answer{ part1(puzzle_input) };
    CHECK(part1_answer == 1565);
}

TEST_CASE("Part 2 answer with sample input should be 286")
{
    auto part2_answer{ part2(sample_input) };
    CHECK(part2_answer == 286);
}

TEST_CASE("Part 2 answer with sample input should be 78883")
{
    auto part2_answer{ part2(puzzle_input) };
    CHECK(part2_answer == 78883);
}


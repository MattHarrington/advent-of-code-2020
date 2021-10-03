#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include "lib.hpp"

const auto sample_input{ read_input("day10_sample_input.txt") };
const auto puzzle_input{ read_input("day10_input.txt") };

TEST_CASE("Sample input file length should be 31")
{
    CHECK(sample_input.size() == 31);
}

TEST_CASE("Puzzle input file length should be 91")
{
    CHECK(puzzle_input.size() == 91);
}

TEST_CASE("Part 1 solution with sample input should be 220")
{
    const auto part1_answer{ part1(sample_input) };
    CHECK(part1_answer == 220);
}

TEST_CASE("Part 1 solution with puzzle input should be 1755")
{
    const auto part1_answer{ part1(puzzle_input) };
    CHECK(part1_answer == 1755);
}

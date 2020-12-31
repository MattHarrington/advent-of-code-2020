#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include "lib.hpp"

const auto sample_input{ read_input("day8_sample_input.txt") };
const auto puzzle_input{ read_input("day8_input.txt") };

TEST_CASE("Sample input file length should be 9")
{
    CHECK(sample_input.size() == 9);
}

TEST_CASE("Input file length should be 613")
{
    CHECK(puzzle_input.size() == 613);
}

TEST_CASE("Length of sample input when processed should be 9")
{
    CHECK(process_input(sample_input).size() == 9);
}

TEST_CASE("Length of puzzle input when processed should be 613")
{
    CHECK(process_input(puzzle_input).size() == 613);
}

TEST_CASE("Part 1 answer with sample input should be 5")
{
    CHECK(part1(process_input(sample_input)) == 5);
}

TEST_CASE("Part 1 answer with puzzle input should be 1087")
{
    CHECK(part1(process_input(puzzle_input)) == 1087);
}

TEST_CASE("Part 2 answer with sample input should be 8")
{
    CHECK(part2(process_input(sample_input)) == 8);
}

TEST_CASE("Part 2 answer with puzzle input should be 780")
{
    CHECK(part2(process_input(puzzle_input)) == 780);
}

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
    const auto part1_answer{ part1(25, puzzle_input) };
    CHECK(part1_answer == 14'144'619);
}

TEST_CASE("Part 2 answer with sample input should be 62")
{
    const auto invalid_number{part1(5, sample_input)};
    const auto part2_answer{ part2(invalid_number, sample_input) };
    CHECK(part2_answer == 62);
}

TEST_CASE("Part 2 answer with puzzle input should be 1'766'397")
{
    const auto invalid_number{part1(25, puzzle_input)};
    const auto part2_answer{ part2(invalid_number, puzzle_input) };
    CHECK(part2_answer == 1'766'397);
}

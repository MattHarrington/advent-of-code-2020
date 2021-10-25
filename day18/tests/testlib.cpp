#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include "lib.hpp"

auto sample_input{ read_input("day18_sample_input.txt") };
auto puzzle_input{ read_input("day18_input.txt") };

TEST_CASE("Sample input should contain 6 lines")
{
    CHECK(sample_input.size() == 6);
}

TEST_CASE("Puzzle input should contain 378 lines")
{
    CHECK(puzzle_input.size() == 378);
}

TEST_CASE("Part 1 answer with sample input should be 26'457")
{
    const auto part1_answer{ part1(sample_input) };
    CHECK(part1_answer == 71 + 51 + 26 + 437 + 12'240 + 13'632);
}

TEST_CASE("Part 1 answer with puzzle input should be 1'402'255'785'165)")
{
    const auto part1_answer{ part1(puzzle_input) };
    CHECK(part1_answer == 1'402'255'785'165);
}

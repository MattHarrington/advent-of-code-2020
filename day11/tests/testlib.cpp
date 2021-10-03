#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include "lib.hpp"

auto sample_input{ read_input("day11_sample_input.txt") };
auto puzzle_input{ read_input("day11_input.txt") };

TEST_CASE("Sample input file length should be 10")
{
    CHECK(sample_input.size() == 10);
}

TEST_CASE("Puzzle input file length should be 97")
{
    CHECK(puzzle_input.size() == 97);
}

TEST_CASE("Part 1 answer with sample input is 37")
{
    auto part1_answer{ part1(sample_input) };
    CHECK(part1_answer == 37);
}

TEST_CASE("Part 1 answer with puzzle input is 2441")
{
    auto part1_answer{ part1(puzzle_input) };
    CHECK(part1_answer == 2441);
}

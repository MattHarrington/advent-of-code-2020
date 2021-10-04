#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include "lib.hpp"

const auto sample_input{ read_input("day11_sample_input.txt") };
const auto puzzle_input{ read_input("day11_input.txt") };

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
    auto mutable_sample_input{ sample_input };
    auto part1_answer{ part1_and_2(true, mutable_sample_input) };
    CHECK(part1_answer == 37);
}

TEST_CASE("Part 1 answer with puzzle input is 2441")
{
    auto mutable_puzzle_input{ puzzle_input };
    auto part1_answer{ part1_and_2(true,mutable_puzzle_input) };
    CHECK(part1_answer == 2441);
}

TEST_CASE("Part 2 answer with sample input is 26")
{
    auto mutable_sample_input{ sample_input };
    auto part2_answer{ part1_and_2(false, mutable_sample_input) };
    CHECK(part2_answer == 26);
}

TEST_CASE("Part 2 answer with puzzle input is 2190")
{
    auto mutable_puzzle_input{ puzzle_input };
    auto part2_answer{ part1_and_2(false, mutable_puzzle_input) };
    CHECK(part2_answer == 2190);
}

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include "lib.hpp"

const auto sample_input{ read_input("day13_sample_input.txt") };
const auto puzzle_input{ read_input("day13_input.txt") };

TEST_CASE("Sample input should be correct")
{
    auto earliest_timestamp{ sample_input.first };
    auto bus_schedule{ sample_input.second };

    CHECK(earliest_timestamp == 939);
    CHECK(bus_schedule.size() == 5);
}

TEST_CASE("Puzzle input should be correct")
{
    auto earliest_timestamp{ puzzle_input.first };
    auto bus_schedule{ puzzle_input.second };

    CHECK(earliest_timestamp == 1'008'169);
    CHECK(bus_schedule.size() == 9);
}

TEST_CASE("Part 1 answer with sample input should be 295")
{
    auto part1_answer{ part1(sample_input) };
    CHECK(part1_answer == 295);
}

TEST_CASE("Part 1 answer with puzzle input should be 4938")
{
    auto part1_answer{ part1(puzzle_input) };
    CHECK(part1_answer == 4938);
}

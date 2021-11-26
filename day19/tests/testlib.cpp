#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include "lib.hpp"

const auto sample_input{ read_input("day19_sample_input.txt") };
const auto puzzle_input{ read_input("day19_input.txt") };

TEST_CASE("Sample input rules should contain 6 lines")
{
    CHECK(sample_input.first.size() == 6);
}

TEST_CASE("Sample input messages should contain 5 lines")
{
    CHECK(sample_input.second.size() == 5);
}

TEST_CASE("Sample input rule regex should match 2 messages")
{
    const auto r{ get_regex_from_rules(sample_input.first) };
    const auto messages{ sample_input.second };
    CHECK(part1(messages, r) == 2);
}

TEST_CASE("Puzzle input rule regex should match 109 messages")
{
    const auto r{ get_regex_from_rules(puzzle_input.first) };
    const auto messages{ puzzle_input.second };
    CHECK(part1(messages, r) == 109);
}

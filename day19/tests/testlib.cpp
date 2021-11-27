#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include "lib.hpp"

const auto sample_input{ read_input("day19_sample_input.txt") };
const auto sample_input_part2{ read_input("day19_sample_input_part2.txt") };
const auto puzzle_input{ read_input("day19_input.txt") };

TEST_CASE("Sample input rules should contain 6 lines")
{
    CHECK(sample_input.first.size() == 6);
}

TEST_CASE("Sample input for part 2 rules should contain 31 lines")
{
    CHECK(sample_input_part2.first.size() == 31);
}

TEST_CASE("Sample input messages should contain 5 lines")
{
    CHECK(sample_input.second.size() == 5);
}

TEST_CASE("Sample input messages for part 2 should contain 15 lines")
{
    CHECK(sample_input_part2.second.size() == 15);
}

TEST_CASE("Sample input rule regex for part 1 should match 2 messages")
{
    const auto r{ get_regex_from_rules(sample_input.first, Part::one) };
    const auto messages{ sample_input.second };
    CHECK(count_matches(messages, r) == 2);
}

TEST_CASE("Puzzle input rule regex for part 1 should match 109 messages")
{
    const auto r{ get_regex_from_rules(puzzle_input.first, Part::one) };
    const auto messages{ puzzle_input.second };
    CHECK(count_matches(messages, r) == 109);
}

TEST_CASE("Sample input rule regex for part 2 after updating should match 12 messages")
{
    const auto r{ get_regex_from_rules(sample_input_part2.first, Part::two) };
    const auto messages{ sample_input_part2.second };
    CHECK(count_matches(messages, r) == 12);
}

TEST_CASE("Puzzle input rule regex for part 2 after updating should match 301 messages")
{
    const auto r{ get_regex_from_rules(puzzle_input.first, Part::two) };
    const auto messages{ puzzle_input.second };
    CHECK(count_matches(messages, r) == 301);
}

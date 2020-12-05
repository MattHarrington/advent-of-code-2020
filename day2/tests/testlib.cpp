#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include "lib.hpp"

TEST_CASE("Test input file length") {
    const auto puzzle_input{ read_input("day2_input.txt") };
    CHECK(puzzle_input.size() == 1000);
}

TEST_CASE("Number of valid passwords in part 1 sample input is 2")
{
    const auto puzzle_input{ read_input("day2_sample_input.txt") };
    const auto part1_answer{ part1(puzzle_input) };
    CHECK(part1_answer == 2);
}

TEST_CASE("Number of valid password in part 1 puzzle input is 434")
{
    const auto puzzle_input{ read_input("day2_input.txt") };
    const auto part1_answer{ part1(puzzle_input) };
    CHECK(part1_answer == 434);
}

TEST_CASE("Number of valid passwords in part 2 sample input is 2")
{
    const auto puzzle_input{ read_input("day2_sample_input.txt") };
    const auto part2_answer{ part2(puzzle_input) };
    CHECK(part2_answer == 1);
}

TEST_CASE("Number of valid password in part 2 puzzle input is 509")
{
    const auto puzzle_input{ read_input("day2_input.txt") };
    const auto part2_answer{ part2(puzzle_input) };
    CHECK(part2_answer == 509);
}

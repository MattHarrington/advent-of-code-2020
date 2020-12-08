#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include "lib.hpp"

TEST_CASE("Sample input file length should be 3")
{
    const auto puzzle_input{ read_input("day5_sample_input.txt") };
    CHECK(puzzle_input.size() == 3);
}

TEST_CASE("Input file length should be 799")
{
    const auto puzzle_input{ read_input("day5_input.txt") };
    CHECK(puzzle_input.size() == 799);
}

TEST_CASE("Seat BFFFBBFRRR should be row 70, column 7")
{
    const auto seat{ get_seat("BFFFBBFRRR") };
    CHECK(seat == std::make_pair(70, 7));
}

TEST_CASE("Seat FFFBBBFRRR should be row 14, column 7")
{
    const auto seat{ get_seat("FFFBBBFRRR") };
    CHECK(seat == std::make_pair(14, 7));
}

TEST_CASE("Seat BBFFBBFRLL should be row 14, column 7")
{
    const auto seat{ get_seat("BBFFBBFRLL") };
    CHECK(seat == std::make_pair(102, 4));
}

TEST_CASE("Part 1 answer should be 888")
{
    const auto puzzle_input{ read_input("day5_input.txt") };
    const auto seat_ids{ get_seat_ids(puzzle_input) };
    const auto part1_answer{ get_max_seat_id(seat_ids) };
    CHECK(part1_answer == 888);
}

TEST_CASE("Part 2 answer should be 522")
{
    const auto puzzle_input{ read_input("day5_input.txt") };
    auto seat_ids{ get_seat_ids(puzzle_input) };
    const auto part1_answer{ get_missing_seat_id(seat_ids) };
    CHECK(part1_answer == 522);
}

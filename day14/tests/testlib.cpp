#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include "lib.hpp"

const auto sample_input{ read_input("day14_sample_input.txt") };
const auto puzzle_input{ read_input("day14_input.txt") };

TEST_CASE("Sample input file length should be 4")
{
    CHECK(sample_input.size() == 4);
}

TEST_CASE("Puzzle input file length should be 559")
{
    CHECK(puzzle_input.size() == 559);
}

TEST_CASE("Mask XXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXX0X applied to 11 should return 73")
{
	auto result{ apply_mask("XXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXX0X",11) };
	CHECK(result == 73);
}

TEST_CASE("Mask XXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXX0X applied to 101 should return 101")
{
	auto result{ apply_mask("XXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXX0X", 101) };
	CHECK(result == 101);
}

TEST_CASE("Mask XXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXX0X applied to 0 should return 64")
{
	auto result{ apply_mask("XXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXX0X", 0) };
	CHECK(result == 64);
}

TEST_CASE("Part 1 answer with sample data should be 165")
{
	auto part1_answer{ part1(sample_input) };
	CHECK(part1_answer == 165);
}

TEST_CASE("Part 1 answer with puzzle data should be 6'317'049'172'545")
{
	auto part1_answer{ part1(puzzle_input) };
	CHECK(part1_answer == 6'317'049'172'545);
}

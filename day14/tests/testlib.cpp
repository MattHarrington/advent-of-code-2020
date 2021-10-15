#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include "lib.hpp"

const auto sample_input{ read_input("day14_sample_input.txt") };
const auto sample_input_part2{ read_input("day14_sample_input_part2.txt") };
const auto puzzle_input{ read_input("day14_input.txt") };

TEST_CASE("Sample input file length should be 4")
{
	CHECK(sample_input.size() == 4);
}

TEST_CASE("Sample input for part 2 file length should be 4")
{
	CHECK(sample_input_part2.size() == 4);
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

TEST_CASE("Mask 000000000000000000000000000000X1001X applied with v2 to 42 should be 000000000000000000000000000000X1101X")
{
	auto result{ get_mask_v2("000000000000000000000000000000X1001X", 42) };
	CHECK(result == "000000000000000000000000000000X1101X");
}

TEST_CASE("Resolving 000000000000000000000000000000X1101X should give 4 results")
{
	auto results{ resolve_floating_bits("000000000000000000000000000000X1101X") };
	CHECK(results.size() == 4);
}

TEST_CASE("Resolving 00000000000000000000000000000001X0XX should give 8 results")
{
	auto results{ resolve_floating_bits("00000000000000000000000000000001X0XX") };
	CHECK(results.size() == 8);
}

TEST_CASE("Part 2 answer with sample data should be 208")
{
	auto part2_answer{ part2(sample_input_part2) };
	CHECK(part2_answer == 208);
}

TEST_CASE("Part 2 answer with puzzle data should be 3'434'009'980'379")
{
	auto part2_answer{ part2(puzzle_input) };
	CHECK(part2_answer == 3'434'009'980'379);
}

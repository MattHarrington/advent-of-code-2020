#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include "lib.hpp"

const std::vector<int> sample_input{ 0,3,6 };
const std::vector<int> puzzle_input{ 20,0,1,11,6,3 };

TEST_CASE("Part 1 answer with sample data should be 436")
{
	auto part1_answer{ play_game(2020, sample_input) };
	CHECK(part1_answer == 436);
}

TEST_CASE("Part 1 answer with puzzle data should be 421")
{
	auto part1_answer{ play_game(2020, puzzle_input) };
	CHECK(part1_answer == 421);
}

TEST_CASE("Part 2 answer with sample data should be 175'594")
{
	auto part2_answer{ play_game(30'000'000, sample_input) };
	CHECK(part2_answer == 175'594);
}

TEST_CASE("Part 2 answer with puzzle data should be 436")
{
	auto part2_answer{ play_game(30'000'000, puzzle_input) };
	CHECK(part2_answer == 436);
}

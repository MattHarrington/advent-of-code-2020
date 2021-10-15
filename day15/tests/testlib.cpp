#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include "lib.hpp"

const std::vector<int> sample_input{ 0,3,6 };
const std::vector<int> puzzle_input{ 20,0,1,11,6,3 };

TEST_CASE("Part 1 answer with sample data should be 436")
{
	CHECK(part1(sample_input) == 436);
}

TEST_CASE("Part 1 answer with puzzle data should be 421")
{
	CHECK(part1(puzzle_input) == 421);
}

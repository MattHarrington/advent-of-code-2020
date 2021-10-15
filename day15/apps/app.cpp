#include <fmt/core.h>

#include "lib.hpp"

int main()
{
	std::vector<int> puzzle_input{ 20,0,1,11,6,3 };

	const auto part1_answer{ part1(puzzle_input) };
	fmt::print("Part 1 answer: {}\n", part1_answer);

	return 0;
}

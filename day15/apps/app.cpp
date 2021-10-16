#include <fmt/core.h>

#include "lib.hpp"

int main()
{
	std::vector<int> puzzle_input{ 20,0,1,11,6,3 };

	const auto part1_answer{ play_game(2020, puzzle_input) };
	fmt::print("Part 1 answer: {}\n", part1_answer);

	const auto part2_answer{ play_game(30'000'000, puzzle_input) };
	fmt::print("Part 2 answer: {}\n", part2_answer);

	return 0;
}

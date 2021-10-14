#include <fmt/core.h>

#include "lib.hpp"

int main()
{
	auto puzzle_input_part1{ read_input_part1("day13_input.txt") };
	auto puzzle_input_part2{ read_input_part2("day13_input.txt") };

	const auto part1_answer{ part1(puzzle_input_part1) };
	fmt::print("Part 1 answer: {}\n", part1_answer);

	const auto part2_answer{ part2(puzzle_input_part2) };
	fmt::print("Part 2 answer: {}\n", part2_answer);

	return 0;
}

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include "lib.hpp"

auto [sample_rules, sample_ticket, sample_nearby_tickets] = read_input("day16_sample_input.txt");
auto [sample_rules_part2, sample_ticket_part2, sample_nearby_tickets_part2] = read_input("day16_sample_input_part2.txt");
auto [puzzle_rules, puzzle_ticket, puzzle_nearby_tickets] = read_input("day16_input.txt");

TEST_CASE("Sample input should contain 3 rules")
{
	CHECK(sample_rules.size() == 3);
}

TEST_CASE("Sample input should contain 4 nearby tickets")
{
	CHECK(sample_nearby_tickets.size() == 4);
}

TEST_CASE("Sample input for part 2 should contain 3 rules")
{
	CHECK(sample_rules_part2.size() == 3);
}

TEST_CASE("Sample input for part 2 should contain 3 nearby tickets")
{
	CHECK(sample_nearby_tickets_part2.size() == 3);
}

TEST_CASE("Puzzle input should contain 20 rules")
{
	CHECK(puzzle_rules.size() == 20);
}

TEST_CASE("Puzzle input should contain 241 nearby tickets")
{
	CHECK(puzzle_nearby_tickets.size() == 241);
}

TEST_CASE("Part 1 answer with sample input should be 71")
{
	const auto part1_answer{ part1("day16_sample_input.txt") };
	CHECK(part1_answer == 71);
}

TEST_CASE("Part 1 answer with puzzle input should be 25'895")
{
	const auto part1_answer{ part1("day16_input.txt") };
	CHECK(part1_answer == 25'895);
}

TEST_CASE("Sample ticket matrix for part 2 should be 3x3")
{
	const auto sample_ticket_matrix{ get_ticket_matrix(sample_nearby_tickets_part2) };
	CHECK(sample_ticket_matrix.rows() == 3);
	CHECK(sample_ticket_matrix.cols() == 3);
}

TEST_CASE("Sample ticket matrix for part 2 should have correct coefficients")
{
	const auto sample_ticket_matrix{ get_ticket_matrix(sample_nearby_tickets_part2) };
	Eigen::MatrixXi m(3, 3);
	m(0, 0) = 3; m(0, 1) = 9; m(0, 2) = 18;
	m(1, 0) = 15; m(1, 1) = 1; m(1, 2) = 5;
	m(2, 0) = 5; m(2, 1) = 14; m(2, 2) = 9;
	CHECK(sample_ticket_matrix == m);
}

TEST_CASE("Puzzle ticket matrix for part 2 should be 241x20")
{
	const auto puzzle_ticket_matrix{ get_ticket_matrix(puzzle_nearby_tickets) };
	CHECK(puzzle_ticket_matrix.rows() == 241);
	CHECK(puzzle_ticket_matrix.cols() == 20);
}

TEST_CASE("Part 2 answer with puzzle data should be 5'865'723'727'753")
{
	const auto part2_answer{ part2(puzzle_rules, puzzle_ticket, puzzle_nearby_tickets) };
	CHECK(part2_answer == 5'865'723'727'753);
}

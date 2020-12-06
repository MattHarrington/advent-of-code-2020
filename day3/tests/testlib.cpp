#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <numeric>

#include "lib.hpp"

TEST_CASE("Sample input file length should be 11")
{
    const auto puzzle_input{ read_input("day3_sample_input.txt") };
    CHECK(puzzle_input.size() == 11);
}

TEST_CASE("Input file length should be 323")
{
    const auto puzzle_input{ read_input("day3_input.txt") };
    CHECK(puzzle_input.size() == 323);
}

TEST_CASE("Sample terrain part 1 answer should be 7")
{
    const auto puzzle_input{ read_input("day3_sample_input.txt") };
    CHECK(calc_num_trees_hit(puzzle_input, 3ULL, 1ULL) == 7);
}

TEST_CASE("Part 1 answer should be 159")
{
    const auto puzzle_input{ read_input("day3_input.txt") };
    CHECK(calc_num_trees_hit(puzzle_input, 3ULL, 1ULL) == 159);
}

TEST_CASE("Sample terrain part 2 answer should be 336")
{
    const auto puzzle_input{ read_input("day3_sample_input.txt") };
    std::vector<size_t> trees_hit;
    trees_hit.push_back( calc_num_trees_hit(puzzle_input, 1ULL, 1ULL) );
    trees_hit.push_back( calc_num_trees_hit(puzzle_input, 3ULL, 1ULL) );
    trees_hit.push_back( calc_num_trees_hit(puzzle_input, 5ULL, 1ULL) );
    trees_hit.push_back( calc_num_trees_hit(puzzle_input, 7ULL, 1ULL) );
    trees_hit.push_back( calc_num_trees_hit(puzzle_input, 1ULL, 2ULL) );
    const auto part2_answer{std::accumulate(std::begin(trees_hit),
        std::end(trees_hit), 1ULL, std::multiplies<>())};
    CHECK(part2_answer == 336);
}

TEST_CASE("Part 2 answer should be 6'419'669'520")
{
    const auto puzzle_input{ read_input("day3_input.txt") };
    std::vector<size_t> trees_hit;
    trees_hit.push_back( calc_num_trees_hit(puzzle_input, 1ULL, 1ULL) );
    trees_hit.push_back( calc_num_trees_hit(puzzle_input, 3ULL, 1ULL) );
    trees_hit.push_back( calc_num_trees_hit(puzzle_input, 5ULL, 1ULL) );
    trees_hit.push_back( calc_num_trees_hit(puzzle_input, 7ULL, 1ULL) );
    trees_hit.push_back( calc_num_trees_hit(puzzle_input, 1ULL, 2ULL) );
    const auto part2_answer{std::accumulate(std::begin(trees_hit),
        std::end(trees_hit), 1ULL, std::multiplies<>())};
    CHECK(part2_answer == 6'419'669'520);
}

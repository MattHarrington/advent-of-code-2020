#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>

#include "lib.hpp"

const auto sample_input{ read_input("day7_sample_input.txt") };
const auto puzzle_input{ read_input("day7_input.txt") };

TEST_CASE("Sample input file length should be 9")
{
    CHECK(sample_input.size() == 9);
}

TEST_CASE("Input file length should be 594")
{
    CHECK(puzzle_input.size() == 594);
}

TEST_CASE("Adjacency list length with sample data should be 9")
{
    const auto graph{ Graph(sample_input) };
    CHECK(graph.adjacency_list.size() == 9);
}

TEST_CASE("Adjacency list length with puzzle data should be 594")
{
    const auto graph{ Graph(puzzle_input) };
    CHECK(graph.adjacency_list.size() == 594);
}

TEST_CASE("Part 1 answer with sample data should be 4")
{
    const auto graph{ Graph(sample_input) };
    CHECK(part1(graph) == 4);
}

TEST_CASE("Part 1 answer with puzle data should be 131")
{
    const auto graph{ Graph(puzzle_input) };
    CHECK(part1(graph) == 131);
}

TEST_CASE("Part 2 answer with sample data should be 32")
{
    const auto graph{ Graph(sample_input) };
    CHECK(part2(graph) == 32);
}

TEST_CASE("Part 2 answer with puzzle data should be 11,261")
{
    const auto graph{ Graph(puzzle_input) };
    CHECK(part2(graph) == 11'261);
}

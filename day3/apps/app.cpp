#include <numeric>
#include <fmt/core.h>

#include "lib.hpp"

int main()
{
    // Part 1

    const auto puzzle_input{ read_input("day3_input.txt") };
    const auto part1_answer{ calc_num_trees_hit(puzzle_input, 3ULL, 1ULL) };
    fmt::print("Part 1 answer: {}\n", part1_answer);

    // Part 2

    std::vector<size_t> trees_hit;
    trees_hit.push_back(calc_num_trees_hit(puzzle_input, 1ULL, 1ULL));
    trees_hit.push_back(calc_num_trees_hit(puzzle_input, 3ULL, 1ULL));
    trees_hit.push_back(calc_num_trees_hit(puzzle_input, 5ULL, 1ULL));
    trees_hit.push_back(calc_num_trees_hit(puzzle_input, 7ULL, 1ULL));
    trees_hit.push_back(calc_num_trees_hit(puzzle_input, 1ULL, 2ULL));
    const auto part2_answer{ std::accumulate(std::begin(trees_hit),
        std::end(trees_hit), 1ULL, std::multiplies<>()) };
    fmt::print("Part 2 answer: {}\n", part2_answer);

    return 0;
}

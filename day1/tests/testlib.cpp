#include <gtest/gtest.h>

#include "lib.hpp"

TEST(ReadInput, PuzzleInputIsReadable)
{
    const auto input{ read_input("day1_input.txt") };
    EXPECT_EQ(input.size(), 200) << "Puzzle length incorrect";
}

TEST(Puzzles, Part1AnswerIsCorrect)
{
    const auto input{ read_input("day1_input.txt") };
    const auto part1_answer{ part1(input) };
    EXPECT_EQ(part1_answer, 1'016'131) << "Part 1 answer incorrect";
}

TEST(Puzzles, Part2AnswerIsCorrect)
{
    const auto input{ read_input("day1_input.txt") };
    const auto part2_answer{ part2(input) };
    EXPECT_EQ(part2_answer, 276'432'018) << "Part 2 answer incorrect";
}

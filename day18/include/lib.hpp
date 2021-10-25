#pragma once

#include <queue>
#include <string>
#include <vector>

enum class Token : long long
{
    none = -1, zero, one, two, three, four, five, six, seven, eight, nine, plus, times, left_parens, right_parens
};

std::vector<std::queue<Token>> read_input(const std::string&);

long long part1(std::vector<std::queue <Token>>);

#pragma once

#include <queue>
#include <string>
#include <vector>

enum class Part
{
    one, two
};

enum class Token : long long
{
    none, one, two, three, four, five, six, seven, eight, nine, plus, times, left_parens, right_parens
};

std::vector<std::queue<Token>> read_input(const std::string&);

long long solve_part(std::vector<std::queue <Token>>, const Part&);

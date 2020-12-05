#pragma once

#include <string>
#include <vector>

struct password_policy
{
    int minimum;
    int maximum;
    char letter;
};

struct password_with_policy
{
    std::string password;
    password_policy policy;
};

std::vector<password_with_policy> read_input(const std::string&);

size_t part1(const std::vector<password_with_policy>&);

size_t part2(const std::vector<password_with_policy>&);

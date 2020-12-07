#pragma once

#include <string>
#include <vector>

enum class problem_part
{
    one, two
};

std::vector<std::string> read_input(const std::string&);

int process_passports(const std::vector<std::string>&, const problem_part&);

#pragma once

#include <string>
#include <vector>

std::vector<std::string> read_input(const std::string&);

long long apply_mask(const std::string& mask, long long value);

long long part1(const std::vector<std::string>&);

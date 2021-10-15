#pragma once

#include <string>
#include <vector>

std::vector<std::string> read_input(const std::string&);

long long apply_mask(const std::string& mask, long long value);

std::string get_mask_v2(const std::string& mask, long long value);

std::vector<std::string> resolve_floating_bits(const std::string&);

long long part1(const std::vector<std::string>&);

long long part2(const std::vector<std::string>&);

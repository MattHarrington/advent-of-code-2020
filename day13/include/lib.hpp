#pragma once

#include <string>
#include <utility>
#include <vector>

struct Bus
{
	int id;
	int stop_number;
};

std::pair<int, std::vector<int>> read_input_part1(const std::string&);

std::vector<Bus> read_input_part2(const std::string&);

int part1(const std::pair<int, std::vector<int>>&);

long long part2(const std::vector<Bus>&);

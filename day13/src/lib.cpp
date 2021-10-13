#include <algorithm>
#include <cmath>
#include <fstream>
#include <regex>
#include <stdexcept>
#include <sstream>

#include "lib.hpp"

std::pair<int, std::vector<int>> read_input(const std::string& filename)
{
	std::fstream in{ filename };
	if (!in.is_open()) throw std::runtime_error("Could not open file");
	std::string line1;
	std::string line2;
	std::vector<int> buses;
	std::regex r{ R"((\d+))" };

	getline(in, line1);
	getline(in, line2);

	auto search_start(line2.cbegin());
	std::smatch sm;

	while (std::regex_search(search_start, line2.cend(), sm, r))
	{
		buses.push_back(std::stoi(sm[1]));
		search_start = sm.suffix().first;
	}

	return std::make_pair(std::stoi(line1), buses);
}

int part1(const std::pair<int, std::vector<int>>& input)
{
	auto earliest_timestamp = static_cast<float>(input.first);
	auto buses{ input.second };

	auto best_bus_timestamp{ std::max_element(buses.cbegin(), buses.cend(),
		[earliest_timestamp](auto a, auto b) {float iaPtr; float ibPtr;
		return std::modff(earliest_timestamp / a, &iaPtr) < std::modff(earliest_timestamp / b, &ibPtr); }) };

	int time_bus_leaves{ static_cast<int>(std::ceil((earliest_timestamp / *best_bus_timestamp)) * *best_bus_timestamp) };
	int timestamps_to_wait{ time_bus_leaves - static_cast<int>(earliest_timestamp) };

	return timestamps_to_wait * *best_bus_timestamp;
}

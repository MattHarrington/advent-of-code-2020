#include <algorithm>
#include <cmath>
#include <fstream>
#include <regex>
#include <stdexcept>
#include <sstream>

#include "lib.hpp"

std::pair<int, std::vector<int>> read_input_part1(const std::string& filename)
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

std::vector<Bus> read_input_part2(const std::string& filename)
{
	// I rewrote read_input() used for part1 rather
	// than adapt it for use in part 2.

	std::fstream in{ filename };
	if (!in.is_open()) throw std::runtime_error("Could not open file");
	std::string line1;
	std::string line2;
	std::string substring;
	std::vector<Bus> buses;

	getline(in, line1); // Ignore this for part 2
	getline(in, line2);

	std::stringstream line2_sstr(line2);
	int stop_number{ -1 };
	while (getline(line2_sstr, substring, ','))
	{
		++stop_number;
		if (substring == "x") continue;
		buses.emplace_back(Bus{ std::stoi(substring), stop_number });
	}

	return buses;
}

int part1(const std::pair<int, std::vector<int>>& input)
{
	auto earliest_timestamp = static_cast<float>(input.first);
	auto buses{ input.second };

	// Best bus has the largest decimal portion when earliest_timestamp
	// is divided by the bus ID. Use std::modff() and std::max_element
	// to find this.
	auto best_bus_timestamp{ std::max_element(buses.cbegin(), buses.cend(),
		[earliest_timestamp](auto a, auto b) {float iaPtr; float ibPtr;
		return std::modff(earliest_timestamp / a, &iaPtr) < std::modff(earliest_timestamp / b, &ibPtr); }) };

	int time_bus_leaves{ static_cast<int>(std::ceil((earliest_timestamp / *best_bus_timestamp)) * *best_bus_timestamp) };
	int timestamps_to_wait{ time_bus_leaves - static_cast<int>(earliest_timestamp) };

	return timestamps_to_wait * *best_bus_timestamp; // Per problem statement
}

long long part2(const std::vector<Bus>& buses)
{
	// Sieve approach. Credit: https://youtu.be/4_5mluiXF5I
	long long t{ 0 };
	long long step_size{ 1 };

	for (const auto& bus : buses)
	{
		while ((t + bus.stop_number) % bus.id != 0)
		{
			t += step_size; // Not all timestamps need to be checked. Only need to check multiples of the bus IDs.
		}
		step_size *= bus.id; // Increment step_size before we move to next bus
	}
	return t;
}

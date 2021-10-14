#include <bitset>
#include <cmath>
#include <fstream>
#include <map>
#include <numeric>
#include <regex>
#include <stdexcept>
#include <sstream>

#include "lib.hpp"

std::vector<std::string> read_input(const std::string& filename)
{
	std::fstream in{ filename };
	if (!in.is_open()) throw std::runtime_error("Could not open file");
	std::string line;
	std::vector <std::string> instructions;

	while (getline(in, line))
	{
		instructions.emplace_back(line);
	}
	return instructions;
}

long long apply_mask(const std::string& mask, long long value)
{
	std::bitset<36> bitvalue{ static_cast<unsigned long>(value) };
	auto bitvalue_counter{ 0 }; // Serves as an index into bitvalue

	// Reverse iterate through mask because most significant bit of the mask
	// is on the left and least significant is on the right. std::bitset<>
	// is the opposite.
	for (auto mask_it{ mask.rbegin() }; mask_it != mask.rend(); ++mask_it)
	{
		if (*mask_it == '0')
		{
			bitvalue.set(bitvalue_counter, 0);
		}
		else if (*mask_it == '1')
		{
			bitvalue.set(bitvalue_counter, 1);
		}
		++bitvalue_counter;
	}
	return static_cast<long long>(bitvalue.to_ullong());
}

long long part1(const std::vector<std::string>& instructions)
{
	std::map<long long, long long> memory; // Map of memory position to value
	std::string mask;
	const std::regex mask_regex{ R"(mask = ([X01]+))" };
	const std::regex mem_regex{ R"(mem\[(\d+)\] = (\d+))" };

	for (const auto& instruction : instructions)
	{
		std::smatch sm;
		if (std::regex_match(instruction, sm, mask_regex)) // Change mask
		{
			mask = sm[1];
		}
		else if (std::regex_match(instruction, sm, mem_regex)) // Assign memory
		{
			auto address{ std::stoll(sm[1]) };
			auto value{ std::stoll(sm[2]) };
			memory[address] = apply_mask(mask, value);
		}
	}
	return std::accumulate(memory.begin(), memory.end(), 0LL, [](auto acc, auto m) {return acc + m.second; });
}

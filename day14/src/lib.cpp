#include <bitset>
#include <cmath>
#include <fstream>
#include <map>
#include <numeric>
#include <queue>
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
	std::bitset<36> bitvalue{ static_cast<unsigned long>(value) }; // Converts value to binary
	auto pos{ 0 }; // Serves as an index into bitvalue

	// Reverse iterate through mask because most significant bit of the mask
	// is on the left and least significant is on the right. std::bitset<>
	// is the opposite.
	for (auto mask_it{ mask.rbegin() }; mask_it != mask.rend(); ++mask_it)
	{
		if (*mask_it == '0')
		{
			bitvalue.set(pos, 0);
		}
		else if (*mask_it == '1')
		{
			bitvalue.set(pos, 1);
		}
		++pos;
	}
	return static_cast<long long>(bitvalue.to_ullong());
}

std::string get_mask_v2(const std::string& mask, long long value)
{
	std::bitset<36> bitvalue(value); // Converts value to binary
	auto bitstring{ bitvalue.to_string() }; // Convert to string because new values can be 0, 1, or X
	auto pos{ 0 }; // Serves as an index into bitstring

	for (const auto c : mask)
	{
		if (c == '1')
		{
			bitstring.at(pos) = '1';
		}
		else if (c == 'X')
		{
			bitstring.at(pos) = 'X';
		}
		++pos;
	}
	return bitstring;
}

std::vector<std::string> resolve_floating_bits(const std::string& mask)
{
	std::vector<std::string> results;
	std::queue<std::string> q;
	q.push(mask);

	while (!q.empty())
	{
		auto m{ q.front() }; // Get a mask from front of queue
		q.pop();
		auto it{ std::find(m.begin(), m.end(), 'X') };
		if (it == m.end())
		{
			// No X found in mask, so add it to results
			results.emplace_back(m);
		}
		else
		{
			// Found an X. Create 2 new masks with X replaced by 0 and 1.
			auto i{ std::distance(m.begin(), it) };
			auto bits0{ m };
			auto bits1{ m };
			bits0.at(i) = '0';
			bits1.at(i) = '1';
			// Put the 2 new masks on the queue
			q.push(bits0);
			q.push(bits1);
		}
	}

	return results;
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

long long part2(const std::vector<std::string>& instructions)
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
			auto address_mask_floating_bits{ get_mask_v2(mask, address) };
			auto address_masks_no_floating_bits{ resolve_floating_bits(address_mask_floating_bits) };
			for (const auto& address_mask : address_masks_no_floating_bits)
			{
				auto new_address{ apply_mask(address_mask, address) };
				memory[new_address] = value;
			}
		}
	}
	return std::accumulate(memory.begin(), memory.end(), 0LL, [](auto acc, auto m) {return acc + m.second; });
}

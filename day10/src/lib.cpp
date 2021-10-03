#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <unordered_map>

#include "lib.hpp"

std::vector<int> read_input(const std::string& filename)
{
    std::fstream in{filename};
    if (!in.is_open()) throw std::runtime_error("Could not open file");
    std::string line;
    std::vector<int> input;

    while (getline(in, line))
    {
        input.emplace_back(std::stoi(line));
    }
    return input;
}

int part1(std::vector<int> adapters)
{
    std::unordered_map<int, int> joltage_differences;

    std::sort(adapters.begin(), adapters.end());

    int current_adapter{ 0 };

    for (const auto adapter : adapters)
    {
        int difference{ adapter - current_adapter };
        ++joltage_differences[difference];
        current_adapter = adapter;
    }

    ++joltage_differences[3]; // For the built-in adapter in the device

    return joltage_differences[1] * joltage_differences[3];
}

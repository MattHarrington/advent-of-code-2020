#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <sstream>

#include "lib.hpp"

std::vector<long long> read_input(const std::string& filename)
{
    std::fstream in{filename};
    if (!in.is_open()) throw std::runtime_error("Could not open file");
    std::string line;
    std::vector<long long> input;

    while (getline(in, line))
    {
        input.emplace_back(std::stoll(line));
    }
    return input;
}

bool is_valid_xmas_number(const long long num, const std::vector<long long>& previous_numbers)
{
    for (const auto n : previous_numbers)
    {
        const auto result{std::find(previous_numbers.cbegin(), previous_numbers.cend(), num - n)};
        if (result == previous_numbers.cend()) // No result found
        {
            continue;
        }
        else if (n == *result) // Skip because the two numbers in the pair must be different
        {
            continue;
        }
        else
        {
            return true;
        }
    }
    return false;
}

long long part1(const long long preamble_length, const std::vector<long long>& input)
{
    for (size_t i = preamble_length; i < input.size(); i++)
    {
        const auto num{input[i]};
        const auto previous_numbers_start{input.cbegin() + i - preamble_length};
        const auto previous_numbers_end{previous_numbers_start + preamble_length};
        const std::vector<long long> previous_numbers{previous_numbers_start, previous_numbers_end};
        if (is_valid_xmas_number(num, previous_numbers))
        {
            continue;
        }
        else
        {
            return num;
        }
    }
    return -1; // No invalid XMAS number found
}

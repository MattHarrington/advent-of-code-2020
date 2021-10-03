#include <algorithm>
#include <fstream>
#include <numeric>
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
    for (size_t i = preamble_length; i < input.size(); ++i)
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
            return num; // Return the invalid number
        }
    }
    return -1; // No invalid XMAS number found
}

long long part2(const long long invalid_number, const std::vector<long long>& input)
{
    std::vector<long long> sequence{};
    for (auto it{input.cbegin()}; it != input.cend(); ++it)
    {
        for (auto it_inner{it}; it != input.cend(); ++it_inner)
        {
            sequence.push_back(*it_inner);
            const auto acc{std::accumulate(sequence.cbegin(), sequence.cend(), 0LL)};

            if (acc == invalid_number) // Found a sequence. Return sum of min element + max element.
            {
                return (*std::min_element(sequence.cbegin(), sequence.cend()) +
                    *std::max_element(sequence.cbegin(), sequence.cend()));
            }
            else if (acc > invalid_number) // No luck with this sequence. Try again.
            {
                sequence.clear();
                break;
            }
        }
    }
    return -1; // No sequence found
}

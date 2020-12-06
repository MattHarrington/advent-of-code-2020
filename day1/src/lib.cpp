#include <fstream>
#include <stdexcept>

#include "lib.hpp"

std::vector<int> read_input(const std::string& filename)
{
    std::fstream in{ filename };
    if (!in.is_open()) throw std::runtime_error("Could not open file");
    std::string line;
    std::vector<int> input;
    while (getline(in, line)) {
        input.push_back(std::stoi(line));
    }
    return input;
}

int part1(const std::vector<int>& input)
{
    for (auto it{ input.begin() }; it != std::prev(input.end()); ++it) {
        for (auto it2{ std::next(it) }; it2 != input.end(); ++it2) {
            if (*it + *it2 == 2020) {
                return *it * *it2;
            }
        }
    }
    return -1; // No solution found
}

int part2(const std::vector<int>& input)
{
    for (auto it{ input.begin() }; it != input.end() - 2; ++it) {
        for (auto it2{ std::next(it) }; it2 != std::prev(input.end()); ++it2) {
            for (auto it3{ std::next(it2) }; it3 != input.end(); ++it3) {
                if (*it + *it2 + *it3 == 2020) {
                    return *it * *it2 * *it3;
                }
            }
        }
    }
    return -1; // No solution found
}

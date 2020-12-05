#include <algorithm>
#include <fstream>
#include <regex>
#include <stdexcept>

#include "lib.hpp"

std::vector<password_with_policy> read_input(const std::string& filename)
{
    std::fstream in{ filename };
    if (!in.is_open()) throw std::runtime_error("Could not open file");
    std::string line;
    std::vector<password_with_policy> input;
    std::regex r{ R"((\d+)-(\d+) ([a-z]): ([a-z]+))" };

    while (getline(in, line)) {
        std::smatch sm;
        std::regex_match(line, sm, r);
        password_policy policy{ std::stoi(sm[1].str()), std::stoi(sm[2].str()), sm[3].str().front() };
        input.emplace_back(password_with_policy{ sm[4], policy });
    }
    return input;
}

size_t part1(const std::vector<password_with_policy>& passwords)
{
    auto password_is_valid{ [](const password_with_policy& p)
    {
       const auto char_count{std::count(std::begin(p.password), std::end(p.password), p.policy.letter)};
       return char_count >= p.policy.minimum && char_count <= p.policy.maximum;
    } };
    return std::count_if(std::begin(passwords), std::end(passwords), password_is_valid);
}

size_t part2(const std::vector<password_with_policy>& passwords)
{
    auto password_is_valid{ [](const password_with_policy& p)
    {
            auto acc{0};
            if (p.password.at(p.policy.minimum - 1) == p.policy.letter) ++acc;
            if (p.password.at(p.policy.maximum - 1) == p.policy.letter) ++acc;
            return acc == 1;
    } };
    return std::count_if(std::begin(passwords), std::end(passwords), password_is_valid);
}

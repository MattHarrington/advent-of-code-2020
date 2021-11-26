#include <algorithm>
#include <fstream>
#include <regex>
#include <sstream>
#include <stdexcept>

#include "lib.hpp"

std::pair<std::map<int, std::string>, std::vector <std::string>> read_input(const std::string& filename)
{
    std::map<int, std::string> rules;
    std::vector<std::string> messages;

    std::fstream in{ filename };
    if (!in.is_open()) throw std::runtime_error("Could not open file");

    std::string line;

    // Read rules
    const std::regex r{ R"((\d+): \"*([\d \|\w]+)\"*)" };
    std::smatch sm;
    while (getline(in, line))
    {
        if (line == "") break; // Reached end of rules
        std::regex_match(line, sm, r);
        rules[std::stoi(sm[1])] = sm[2];
    }

    // Read messages
    while (getline(in, line))
    {
        messages.emplace_back(line);
    }

    return std::make_pair(rules, messages);
}

std::regex get_regex_from_rules(std::map<int, std::string> rules)
{
    std::string s{ rules[0] };
    const std::regex num_regex{ R"((\s*\d+\s*))" };
    std::smatch sm;
    while (std::regex_search(s, sm, num_regex))
    {
        auto pos{ s.find(sm[1]) };
        s.replace(pos, sm[1].length(), "(?:" + rules[std::stoi(sm[1])] + ")");
    }

    return std::regex{ "^" + s + "$"};
}

int part1(const std::vector<std::string>& messages, const std::regex& r)
{
    int matches{ 0 };
    for (const auto& message : messages)
    {
        std::smatch sm;
        if (std::regex_match(message, sm, r))
        {
            ++matches;
        }
    }
    return matches;
}

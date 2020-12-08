#include <algorithm>
#include <numeric>
#include <fstream>
#include <stdexcept>
#include <unordered_map>

#include "lib.hpp"

std::vector<std::string> read_input(const std::string& filename)
{
    std::fstream in{ filename };
    if (!in.is_open()) throw std::runtime_error("Could not open file");
    std::string line;
    std::vector<std::string> input;

    while (getline(in, line)) {
        input.emplace_back(line);
    }
    return input;
}

size_t part1(const std::vector<std::string>& customs_forms)
{
    std::unordered_map<char, int> customs_form;
    std::vector<size_t> questions_answered_yes;

    for (const auto& line : customs_forms)
    {
        if (line.empty())
        {
            // Empty lines separate forms
            questions_answered_yes.push_back(customs_form.size());
            customs_form.clear();
            continue;
        }
        std::for_each(line.cbegin(), line.cend(), [&customs_form](const char c) {customs_form[c]++; });
    }
    // See part2() for a way to handle last form besides repeating logic
    questions_answered_yes.push_back(customs_form.size()); // Handle last form in file, since no blank line follows it
    return std::accumulate(questions_answered_yes.begin(), questions_answered_yes.end(), 0ULL);
}

size_t part2(const std::vector<std::string>& customs_forms)
{
    std::unordered_map<char, int> customs_form;
    std::vector<size_t> questions_everyone_answered_yes;
    auto people_on_form{ 0 };

    for (auto it{ customs_forms.begin() }; true; ++it)
    {
        people_on_form++;
        std::for_each((*it).cbegin(), (*it).cend(), [&customs_form](const char c) {customs_form[c]++; });

        // Check if we're at the end of a customs form
        if (std::next(it) == customs_forms.end() || (*std::next(it)).empty())
        {
            // When value == number of people on form, everyone answered yes
            const auto num_all_answered_yes{ std::count_if(customs_form.cbegin(), customs_form.cend(),
                [people_on_form](const std::pair<const char, int> elem) {return elem.second == people_on_form; }) };

            questions_everyone_answered_yes.push_back(num_all_answered_yes);

            if (std::next(it) == customs_forms.end()) break; // All forms have been processed, so break

            // Reset, because we're about to process a new form
            customs_form.clear();
            people_on_form = 0;

            ++it; // Skip over the next line since it's blank.  Start processing a new form next iteration.
        }
    }

    return std::accumulate(questions_everyone_answered_yes.begin(), questions_everyone_answered_yes.end(), 0ULL);
}

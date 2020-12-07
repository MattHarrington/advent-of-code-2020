#include <algorithm>
#include <fstream>
#include <regex>
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

bool birth_year_is_valid(const std::unordered_map<std::string, std::string>& passport)
{
    // byr (Birth Year) - four digits; at least 1920 and at most 2002
    if (passport.at("byr").size() != 4) return false;
    const auto byr{ std::stoi(passport.at("byr")) };
    return byr >= 1920 && byr <= 2002;
}

bool issue_year_is_valid(const std::unordered_map<std::string, std::string>& passport)
{
    // iyr (Issue Year) - four digits; at least 2010 and at most 2020
    if (passport.at("iyr").size() != 4) return false;
    const auto iyr{ std::stoi(passport.at("iyr")) };
    return iyr >= 2010 && iyr <= 2020;
}

bool expiration_year_is_valid(const std::unordered_map<std::string, std::string>& passport)
{
    // eyr (Expiration Year) - four digits; at least 2020 and at most 2030
    if (passport.at("eyr").size() != 4) return false;
    const auto eyr{ std::stoi(passport.at("eyr")) };
    return eyr >= 2020 && eyr <= 2030;
}

bool height_is_valid(const std::unordered_map<std::string, std::string>& passport)
{
    // hgt (Height) - a number followed by either cm or in:
    //    If cm, the number must be at least 150 and at most 193.
    //    If in, the number must be at least 59 and at most 76.
    const std::regex r{ R"(([\d]+)(in|cm)?)" };
    std::smatch sm;
    std::regex_match(passport.at("hgt"), sm, r);
    const auto value{ std::stoi(sm[1]) };
    if (sm[2] == "cm") return value >= 150 && value <= 193;
    return value >= 59 && value <= 76;
}

bool hair_color_is_valid(const std::unordered_map<std::string, std::string>& passport)
{
    // hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f
    if (passport.at("hcl").size() != 7) return false;
    const std::regex r{ R"(#[0-9a-f]{6})" };
    std::smatch sm;
    return std::regex_match(passport.at("hcl"), sm, r);
}

bool eye_color_is_valid(const std::unordered_map<std::string, std::string>& passport)
{
    // ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth
    const auto ecl{ passport.at("ecl") };
    std::vector<std::string> permitted_eye_colors{ "amb", "blu", "brn", "gry", "grn", "hzl", "oth" };
    return std::find(std::begin(permitted_eye_colors), std::end(permitted_eye_colors), ecl) != std::end(permitted_eye_colors);
}

bool passport_id_is_valid(const std::unordered_map<std::string, std::string>& passport)
{
    // pid (Passport ID) - a nine-digit number, including leading zeroes
    if (passport.at("pid").size() != 9) return false;
    try
    {
        std::stoi(passport.at("pid")); // throws if not a number
        return true;
    }
    catch (const std::invalid_argument& e)
    {
        // pid is not a number
        return false;
    }
}

bool passport_is_valid(const std::unordered_map<std::string, std::string>& passport, const problem_part& part)
{
    // Valid passports have 8 fields, or 7 fields with the only missing field "cid"
    if (part == problem_part::one)
    {
        return passport.size() == 8 ||
            (passport.size() == 7 && (passport.find("cid") == passport.end()));
    }

    // Extra validation for part 2

    if (passport.size() == 8 ||
        (passport.size() == 7 && (passport.find("cid") == passport.end()))) {
        return birth_year_is_valid(passport) &&
            issue_year_is_valid(passport) &&
            expiration_year_is_valid(passport) &&
            height_is_valid(passport) &&
            hair_color_is_valid(passport) &&
            eye_color_is_valid(passport) &&
            passport_id_is_valid(passport);
    }
    else return false;
}

int process_passports(const std::vector<std::string>& input, const problem_part& part)
{
    const std::regex r{ R"(([a-z]+):([\w#]+))" };
    auto number_of_valid_passports{ 0 };
    std::unordered_map<std::string, std::string> passport;

    for (const auto& line : input)
    {
        if (line.empty()) // Empty line separates passports
        {
            if (passport_is_valid(passport, part)) ++number_of_valid_passports;
            passport.clear();
            continue;
        }

        auto search_start(line.cbegin());
        std::smatch sm;
        while (std::regex_search(search_start, line.cend(), sm, r))
        {
            passport[sm[1]] = sm[2];
            search_start = sm.suffix().first;
        }
    }
    // Check last passport:
    if (passport_is_valid(passport, part)) ++number_of_valid_passports;
    return number_of_valid_passports;
}

#pragma once

#include <map>
#include <string>
#include <utility>
#include <regex>
#include <vector>

std::pair<std::map<int, std::string>, std::vector<std::string>> read_input(const std::string&);

std::regex get_regex_from_rules(std::map<int, std::string>);

int part1(const std::vector<std::string>&, const std::regex&);

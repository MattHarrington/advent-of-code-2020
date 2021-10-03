#pragma once

#include <string>
#include <tuple>
#include <vector>

using seating_chart = std::vector<std::string>;

seating_chart read_input(const std::string&);

std::tuple<seating_chart,bool> process_seating_chart(const seating_chart&);

int part1(seating_chart&);

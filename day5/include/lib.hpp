#pragma once

#include <string>
#include <utility>
#include <vector>

std::vector<std::string> read_input(const std::string&);

std::pair<int, int> get_seat(const std::string&);

int get_seat_id(const std::pair<int, int>&);

std::vector<int> get_seat_ids(const std::vector<std::string>&);

int get_max_seat_id(const std::vector<int>&);

int get_missing_seat_id(std::vector<int>&);

#pragma once

#include <string>
#include <vector>

using terrain = std::vector<std::string>;

terrain read_input(const std::string&);

int calc_num_trees_hit(const terrain&, const size_t delta_x, const size_t delta_y);

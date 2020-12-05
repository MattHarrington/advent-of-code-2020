#include <fstream>
#include <stdexcept>

#include "lib.hpp"

terrain read_input(const std::string& filename)
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

int calc_num_trees_hit(const terrain& terrain, const size_t delta_x, const size_t delta_y)
{
    const auto width{ terrain.front().size() };
    const auto height{ terrain.size() };

    auto x{ 0ULL };
    auto num_trees{ 0 };

    for (auto y{ 0ULL }; y < height; y += delta_y)
    {
        if (terrain[y][x] == '#') ++num_trees;
        x += delta_x;
        if (x >= width) x -= width;
    }

    return num_trees;
}

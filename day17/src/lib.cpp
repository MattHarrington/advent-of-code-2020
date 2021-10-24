#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unordered_set>

#include "lib.hpp"

std::vector<std::string> read_input(const std::string& filename)
{
    std::vector<std::string> output;
    std::fstream in{ filename };
    if (!in.is_open()) throw std::runtime_error("Could not open file");

    std::string line;

    while (getline(in, line))
    {
        output.emplace_back(line);
    }
    return output;
}

std::vector<Point3D> process_input_3D(const std::vector<std::string>& input)
{
    std::vector<Point3D> cubes;
    for (auto y{ 0 }; y < input.size(); ++y)
    {
        for (auto x{ 0 }; x < input.front().size(); ++x)
        {
            if (input[y][x] == '#')
            {
                Point3D cube{ x, y, 0 };
                cubes.emplace_back(cube);
            }
        }
    }
    return cubes;
}

std::vector<Point4D> process_input_4D(const std::vector<std::string>& input)
{
    std::vector<Point4D> cubes;
    for (auto y{ 0 }; y < input.size(); ++y)
    {
        for (auto x{ 0 }; x < input.front().size(); ++x)
        {
            if (input[y][x] == '#')
            {
                Point4D cube{ x, y, 0, 0 };
                cubes.emplace_back(cube);
            }
        }
    }
    return cubes;
}

std::vector<Point3D> get_neighbors_3D(const Point3D& cube)
{
    std::vector<Point3D> neighbors;

    // z = -1
    neighbors.emplace_back(Point3D{ cube.x - 1, cube.y - 1, cube.z - 1 });
    neighbors.emplace_back(Point3D{ cube.x, cube.y - 1, cube.z - 1 });
    neighbors.emplace_back(Point3D{ cube.x + 1, cube.y - 1, cube.z - 1 });
    neighbors.emplace_back(Point3D{ cube.x - 1, cube.y, cube.z - 1 });
    neighbors.emplace_back(Point3D{ cube.x, cube.y, cube.z - 1 });
    neighbors.emplace_back(Point3D{ cube.x + 1, cube.y, cube.z - 1 });
    neighbors.emplace_back(Point3D{ cube.x - 1, cube.y + 1, cube.z - 1 });
    neighbors.emplace_back(Point3D{ cube.x, cube.y + 1, cube.z - 1 });
    neighbors.emplace_back(Point3D{ cube.x + 1, cube.y + 1, cube.z - 1 });
    // z = 0
    neighbors.emplace_back(Point3D{ cube.x - 1, cube.y - 1, cube.z });
    neighbors.emplace_back(Point3D{ cube.x, cube.y - 1, cube.z });
    neighbors.emplace_back(Point3D{ cube.x + 1, cube.y - 1, cube.z });
    neighbors.emplace_back(Point3D{ cube.x - 1, cube.y, cube.z });
    neighbors.emplace_back(Point3D{ cube.x + 1, cube.y, cube.z });
    neighbors.emplace_back(Point3D{ cube.x - 1, cube.y + 1, cube.z });
    neighbors.emplace_back(Point3D{ cube.x, cube.y + 1, cube.z });
    neighbors.emplace_back(Point3D{ cube.x + 1, cube.y + 1, cube.z });
    // z = 1 
    neighbors.emplace_back(Point3D{ cube.x - 1, cube.y - 1, cube.z + 1 });
    neighbors.emplace_back(Point3D{ cube.x, cube.y - 1, cube.z + 1 });
    neighbors.emplace_back(Point3D{ cube.x + 1, cube.y - 1, cube.z + 1 });
    neighbors.emplace_back(Point3D{ cube.x - 1, cube.y, cube.z + 1 });
    neighbors.emplace_back(Point3D{ cube.x, cube.y, cube.z + 1 });
    neighbors.emplace_back(Point3D{ cube.x + 1, cube.y, cube.z + 1 });
    neighbors.emplace_back(Point3D{ cube.x - 1, cube.y + 1, cube.z + 1 });
    neighbors.emplace_back(Point3D{ cube.x, cube.y + 1, cube.z + 1 });
    neighbors.emplace_back(Point3D{ cube.x + 1, cube.y + 1, cube.z + 1 });

    return neighbors;
}

std::vector<Point4D> get_neighbors_4D(const Point4D& cube)
{
    std::vector<Point4D> neighbors;

    // z = 1, w = -1
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y - 1, cube.z - 1, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y - 1, cube.z - 1, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y - 1, cube.z - 1, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y,     cube.z - 1, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y,     cube.z - 1, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y,     cube.z - 1, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y + 1, cube.z - 1, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y + 1, cube.z - 1, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y + 1, cube.z - 1, cube.w - 1 });
    // z = -1, w = 1
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y - 1, cube.z - 1, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y - 1, cube.z - 1, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y - 1, cube.z - 1, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y,     cube.z - 1, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y,     cube.z - 1, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y,     cube.z - 1, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y + 1, cube.z - 1, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y + 1, cube.z - 1, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y + 1, cube.z - 1, cube.w + 1 });
    // z = -1, w = 0
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y - 1, cube.z - 1, cube.w });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y - 1, cube.z - 1, cube.w });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y - 1, cube.z - 1, cube.w });
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y,     cube.z - 1, cube.w });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y,     cube.z - 1, cube.w });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y,     cube.z - 1, cube.w });
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y + 1, cube.z - 1, cube.w });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y + 1, cube.z - 1, cube.w });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y + 1, cube.z - 1, cube.w });
    // z = 0, w = -1
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y - 1, cube.z, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y - 1, cube.z, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y - 1, cube.z, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y,     cube.z, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y,     cube.z, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y,     cube.z, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y + 1, cube.z, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y + 1, cube.z, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y + 1, cube.z, cube.w - 1 });
    // z = 0, w = 0
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y - 1, cube.z, cube.w });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y - 1, cube.z, cube.w });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y - 1, cube.z, cube.w });
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y,     cube.z, cube.w });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y,     cube.z, cube.w });
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y + 1, cube.z, cube.w });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y + 1, cube.z, cube.w });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y + 1, cube.z, cube.w });
    // z = 1, w = -1
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y - 1, cube.z + 1, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y - 1, cube.z + 1, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y - 1, cube.z + 1, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y,     cube.z + 1, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y,     cube.z + 1, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y,     cube.z + 1, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y + 1, cube.z + 1, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y + 1, cube.z + 1, cube.w - 1 });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y + 1, cube.z + 1, cube.w - 1 });
    // z = 1, w = 0 
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y - 1, cube.z + 1, cube.w });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y - 1, cube.z + 1, cube.w });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y - 1, cube.z + 1, cube.w });
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y,     cube.z + 1, cube.w });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y,     cube.z + 1, cube.w });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y,     cube.z + 1, cube.w });
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y + 1, cube.z + 1, cube.w });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y + 1, cube.z + 1, cube.w });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y + 1, cube.z + 1, cube.w });
    // z = 0, w = 1
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y - 1, cube.z, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y - 1, cube.z, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y - 1, cube.z, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y,     cube.z, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y,     cube.z, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y,     cube.z, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y + 1, cube.z, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y + 1, cube.z, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y + 1, cube.z, cube.w + 1 });
    // z = 1, w = 1
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y - 1, cube.z + 1, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y - 1, cube.z + 1, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y - 1, cube.z + 1, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y,     cube.z + 1, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y,     cube.z + 1, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y,     cube.z + 1, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x - 1, cube.y + 1, cube.z + 1, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x,     cube.y + 1, cube.z + 1, cube.w + 1 });
    neighbors.emplace_back(Point4D{ cube.x + 1, cube.y + 1, cube.z + 1, cube.w + 1 });

    return neighbors;
}

int count_active_neighbors_3D(const Point3D& cube, const std::vector<Point3D>& cubes)
{
    auto active_neighbors{ 0 };
    auto neighbors{ get_neighbors_3D(cube) };
    for (const auto& neighbor : neighbors)
    {
        if (std::find(cubes.cbegin(), cubes.end(), neighbor) != cubes.cend())
        {
            // Found an active neighbor
            ++active_neighbors;
        }
    }
    return active_neighbors;
}

int count_active_neighbors_4D(const Point4D& cube, const std::vector<Point4D>& cubes)
{
    auto active_neighbors{ 0 };
    auto neighbors{ get_neighbors_4D(cube) };
    for (const auto& neighbor : neighbors)
    {
        if (std::find(cubes.cbegin(), cubes.end(), neighbor) != cubes.cend())
        {
            // Found an active neighbor
            ++active_neighbors;
        }
    }
    return active_neighbors;
}

std::vector<Point3D> process_active_cubes_3D(const std::vector<Point3D>& cubes)
{
    // "If a cube is active and exactly 2 or 3 of its neighbors are also active, the cube remains active.
    // Otherwise, the cube becomes inactive."
    std::vector<Point3D> new_cubes;
    for (const auto& active_cube : cubes)
    {
        auto active_neighbors{ count_active_neighbors_3D(active_cube, cubes) };
        if (active_neighbors == 2 || active_neighbors == 3)
        {
            new_cubes.emplace_back(active_cube);
        }
    }
    return new_cubes;
}

std::vector<Point4D> process_active_cubes_4D(const std::vector<Point4D>& cubes)
{
    // "If a cube is active and exactly 2 or 3 of its neighbors are also active, the cube remains active.
    // Otherwise, the cube becomes inactive."
    std::vector<Point4D> new_cubes;
    for (const auto& active_cube : cubes)
    {
        auto active_neighbors{ count_active_neighbors_4D(active_cube, cubes) };
        if (active_neighbors == 2 || active_neighbors == 3)
        {
            new_cubes.emplace_back(active_cube);
        }
    }
    return new_cubes;
}

std::vector<Point3D> process_inactive_cubes_3D(const std::vector<Point3D>& cubes)
{
    // "If a cube is inactive but exactly 3 of its neighbors are active, the cube becomes active.
    // Otherwise, the cube remains inactive."
    std::vector<Point3D> new_cubes;
    for (const auto& active_cube : cubes)
    {
        auto neighbors{ get_neighbors_3D(active_cube) };
        for (const auto& neighbor : neighbors)
        {
            if (std::find(cubes.cbegin(), cubes.cend(), neighbor) == cubes.cend())
            {
                // Neighbor is inactive
                auto active_neighbors_of_inactive_cube{ count_active_neighbors_3D(neighbor,cubes) };
                if (active_neighbors_of_inactive_cube == 3)
                {
                    new_cubes.emplace_back(neighbor);
                }
            }
        }

    }
    return new_cubes;
}

std::vector<Point4D> process_inactive_cubes_4D(const std::vector<Point4D>& cubes)
{
    // "If a cube is inactive but exactly 3 of its neighbors are active, the cube becomes active.
    // Otherwise, the cube remains inactive."
    std::vector<Point4D> new_cubes;
    for (const auto& active_cube : cubes)
    {
        auto neighbors{ get_neighbors_4D(active_cube) };
        for (const auto& neighbor : neighbors)
        {
            if (std::find(cubes.cbegin(), cubes.cend(), neighbor) == cubes.cend())
            {
                // Neighbor is inactive
                auto active_neighbors_of_inactive_cube{ count_active_neighbors_4D(neighbor,cubes) };
                if (active_neighbors_of_inactive_cube == 3)
                {
                    new_cubes.emplace_back(neighbor);
                }
            }
        }

    }
    return new_cubes;
}

int part1(const std::vector<std::string>& input)
{
    auto cubes{ process_input_3D(input) };
    auto cycle{ 0 };

    while (cycle < 6)
    {
        auto next_cycle_cubes{ process_active_cubes_3D(cubes) };
        auto next_cycle_from_inactive_cubes{ process_inactive_cubes_3D(cubes) };
        next_cycle_cubes.insert(next_cycle_cubes.cend(), next_cycle_from_inactive_cubes.cbegin(), next_cycle_from_inactive_cubes.cend());
        std::unordered_set<Point3D, boost::hash<Point3D>> unique_cubes(next_cycle_cubes.cbegin(), next_cycle_cubes.cend()); // Remove duplicates
        cubes = std::vector<Point3D>(unique_cubes.cbegin(), unique_cubes.cend());
        ++cycle;
    }

    return static_cast<int>(cubes.size());
}

int part2(const std::vector<std::string>& input)
{
    auto cubes{ process_input_4D(input) };
    auto cycle{ 0 };

    while (cycle < 6)
    {
        auto next_cycle_cubes{ process_active_cubes_4D(cubes) };
        auto next_cycle_from_inactive_cubes{ process_inactive_cubes_4D(cubes) };
        next_cycle_cubes.insert(next_cycle_cubes.cend(), next_cycle_from_inactive_cubes.cbegin(), next_cycle_from_inactive_cubes.cend());
        std::unordered_set<Point4D, boost::hash<Point4D>> unique_cubes(next_cycle_cubes.cbegin(), next_cycle_cubes.cend()); // Remove duplicates
        cubes = std::vector<Point4D>(unique_cubes.cbegin(), unique_cubes.cend());
        ++cycle;
    }

    return static_cast<int>(cubes.size());
}

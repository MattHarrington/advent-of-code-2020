#include <cmath>
#include <fstream>
#include <regex>
#include <stdexcept>
#include <sstream>

#include "lib.hpp"

std::vector<std::pair<char, int>> read_input(const std::string& filename)
{
    std::fstream in{ filename };
    if (!in.is_open()) throw std::runtime_error("Could not open file");
    std::string line;
    std::regex r{ R"(([NSEWLRF])(\d*))" };
    std::vector < std::pair < char, int >> input;

    while (getline(in, line))
    {
        std::smatch sm;
        std::regex_match(line, sm, r);
        input.emplace_back(std::make_pair(sm[1].str()[0], std::stoi(sm[2])));
    }
    return input;
}

int part1(const std::vector<std::pair<char, int>>& instructions)
{
    int x{ 0 };
    int y{ 0 };

    int bearing{ 90 }; // Initially facing east

    for (const auto& instruction : instructions)
    {
        switch (instruction.first)
        {
        case 'N':
            y += instruction.second;
            break;
        case 'E':
            x += instruction.second;
            break;
        case 'S':
            y -= instruction.second;
            break;
        case 'W':
            x -= instruction.second;
            break;
        case 'L':
            bearing -= instruction.second;
            break;
        case 'R':
            bearing += instruction.second;
            break;
        case 'F':
            if (bearing > 360) bearing -= 360; // Only handles -360 < bearing < 360
            else if (bearing < 0) bearing += 360;
            switch (bearing)
            {
            case 0:
            case 360:
                y += instruction.second;
                break;
            case 90:
                x += instruction.second;
                break;
            case 180:
                y -= instruction.second;
                break;
            case 270:
                x -= instruction.second;
                break;
            default:
                throw std::runtime_error("Bad bearing");
            }
            break;
        default:
            throw std::runtime_error("Bad instruction");
        }
    }
    return std::abs(x) + std::abs(y); // Manhattan distance from starting point
}

int part2(const std::vector<std::pair<char, int>>& instructions)
{
    struct Ship
    {
        int x{ 0 };
        int y{ 0 };
    };

    struct Waypoint {
        // Position relative to ship
        int x{ 10 };
        int y{ 1 };
    };

    Ship ship;
    Waypoint waypoint;

    for (const auto& instruction : instructions)
    {
        auto waypoint_orig{ waypoint };
        switch (instruction.first)
        {
        case 'N':
            waypoint.y += instruction.second;
            break;
        case 'E':
            waypoint.x += instruction.second;
            break;
        case 'S':
            waypoint.y -= instruction.second;
            break;
        case 'W':
            waypoint.x -= instruction.second;
            break;
        case 'L':
            // Rotate CCW
            switch (instruction.second)
            {
            case 90:
                waypoint.x = -waypoint_orig.y;
                waypoint.y = waypoint_orig.x;
                break;
            case 180:
                waypoint.x = -waypoint_orig.x;
                waypoint.y = -waypoint_orig.y;
                break;
            case 270:
                // Same as R90
                waypoint.x = waypoint_orig.y;
                waypoint.y = -waypoint_orig.x;
                break;
            default:
                throw std::runtime_error("Bad rotate left angle");
            }
            break; // Break out of case 'L'
        case 'R':
            // Rotate CW
            switch (instruction.second)
            {
            case 90:
                waypoint.x = waypoint_orig.y;
                waypoint.y = -waypoint_orig.x;
                break;
            case 180:
                waypoint.x = -waypoint_orig.x;
                waypoint.y = -waypoint_orig.y;
                break;
            case 270:
                // Same as L90
                waypoint.x = -waypoint_orig.y;
                waypoint.y = waypoint_orig.x;
                break;
            default:
                throw std::runtime_error("Bad rotate right angle");
            }
            break; // Break out of case 'R'
        case 'F':
            ship.x += waypoint.x * instruction.second;
            ship.y += waypoint.y * instruction.second;
            break;
        }
    }
    return std::abs(ship.x) + std::abs(ship.y); // Manhattan distance from starting point
}

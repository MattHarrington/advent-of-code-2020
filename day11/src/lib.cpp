#include <fstream>
#include <functional>
#include <stdexcept>
#include <sstream>

#include "lib.hpp"

seating_chart read_input(const std::string& filename)
{
    std::fstream in{ filename };
    if (!in.is_open()) throw std::runtime_error("Could not open file");
    std::string line;
    seating_chart input;

    while (getline(in, line))
    {
        input.emplace_back(line);
    }
    return input;
}

bool has_adjacent_occupied_seats(const seating_chart& seating_chart, const size_t x, const size_t y)
{
    if (x > 0 && y > 0 && seating_chart[y - 1][x - 1] == '#') return true;
    if (y > 0 && seating_chart[y - 1][x] == '#') return true;
    if (x < seating_chart.front().size() && y > 0 && seating_chart[y - 1][x + 1] == '#') return true;
    if (x < seating_chart.front().size() && seating_chart[y][x + 1] == '#') return true;
    if (x < seating_chart.front().size() && y < seating_chart.size() - 1
        && seating_chart[y + 1][x + 1] == '#') return true;
    if (y < seating_chart.size() - 1 && seating_chart[y + 1][x] == '#') return true;
    if (x > 0 && y < seating_chart.size() - 1 && seating_chart[y + 1][x - 1] == '#') return true;
    if (x > 0 && seating_chart[y][x - 1] == '#') return true;
    else return false;
}

bool can_see_occupied_seat(const seating_chart& seating_chart, const size_t cx, const size_t cy)
{
    auto x{ cx }; // cx and cy are constant function parameters for safety
    auto y{ cy }; // x and y are reset after checking in a particular direction

    while (x > 0 && y > 0) // Northwest
    {
        if (seating_chart[y - 1][x - 1] == '#') return true;
        if (seating_chart[y - 1][x - 1] == 'L') break;
        --x; --y;
    }
    x = cx; y = cy;

    while (y > 0) // North
    {
        if (seating_chart[y - 1][x] == '#') return true;
        if (seating_chart[y - 1][x] == 'L') break;
        --y;
    }
    x = cx; y = cy;

    while (x < seating_chart.front().size() && y > 0) // Northeast
    {
        if (seating_chart[y - 1][x + 1] == '#') return true;
        if (seating_chart[y - 1][x + 1] == 'L') break;
        ++x; --y;
    }
    x = cx; y = cy;

    while (x < seating_chart.front().size()) // East
    {
        if (seating_chart[y][x + 1] == '#') return true;
        if (seating_chart[y][x + 1] == 'L') break;
        ++x;
    }
    x = cx; y = cy;

    while (x < seating_chart.front().size() && y < seating_chart.size() - 1) // Southeast
    {
        if (seating_chart[y + 1][x + 1] == '#') return true;
        if (seating_chart[y + 1][x + 1] == 'L') break;
        ++x; ++y;
    }
    x = cx; y = cy;

    while (y < seating_chart.size() - 1) // South
    {
        if (seating_chart[y + 1][x] == '#') return true;
        if (seating_chart[y + 1][x] == 'L') break;
        ++y;
    }
    x = cx; y = cy;

    while (x > 0 && y < seating_chart.size() - 1) // Southwest
    {
        if (seating_chart[y + 1][x - 1] == '#') return true;
        if (seating_chart[y + 1][x - 1] == 'L') break;
        --x; ++y;
    }
    x = cx; y = cy;

    while (x > 0) // West
    {
        if (seating_chart[y][x - 1] == '#') return true;
        if (seating_chart[y][x - 1] == 'L') break;
        --x;
    }

    return false;
}

bool has_four_plus_adjacent_occupied_seats(const seating_chart& seating_chart, const size_t x, const size_t y)
{
    int adjacent_occupied_seats{ 0 };
    if (x > 0 && y > 0 && seating_chart[y - 1][x - 1] == '#') ++adjacent_occupied_seats;
    if (y > 0 && seating_chart[y - 1][x] == '#') ++adjacent_occupied_seats;
    if (x < seating_chart.front().size() && y > 0 && seating_chart[y - 1][x + 1] == '#') ++adjacent_occupied_seats;
    if (x < seating_chart.front().size() && seating_chart[y][x + 1] == '#') ++adjacent_occupied_seats;
    if (x < seating_chart.front().size() && y < seating_chart.size() - 1
        && seating_chart[y + 1][x + 1] == '#') ++adjacent_occupied_seats;
    if (y < seating_chart.size() - 1 && seating_chart[y + 1][x] == '#') ++adjacent_occupied_seats;
    if (x > 0 && y < seating_chart.size() - 1 && seating_chart[y + 1][x - 1] == '#') ++adjacent_occupied_seats;
    if (x > 0 && seating_chart[y][x - 1] == '#') ++adjacent_occupied_seats;
    return adjacent_occupied_seats >= 4 ? true : false;
}

bool can_see_five_plus_occupied_seats(const seating_chart& seating_chart, const size_t cx, const size_t cy)
{
    int visible_occupied_seats{ 0 };
    auto x{ cx }; // cx and cy are constant function parameters for safety
    auto y{ cy }; // x and y are reset after checking in a particular direction

    while (x > 0 && y > 0) // Northwest
    {
        if (seating_chart[y - 1][x - 1] == '#')
        {
            ++visible_occupied_seats;
            break;
        }
        if (seating_chart[y - 1][x - 1] == 'L') break;
        --x; --y;
    }
    x = cx; y = cy;

    while (y > 0) // North
    {
        if (seating_chart[y - 1][x] == '#')
        {
            ++visible_occupied_seats;
            break;
        }
        if (seating_chart[y - 1][x] == 'L') break;
        --y;
    }
    x = cx; y = cy;

    while (x < seating_chart.front().size() && y > 0) // Northeast
    {
        if (seating_chart[y - 1][x + 1] == '#')
        {
            ++visible_occupied_seats;
            break;
        }
        if (seating_chart[y - 1][x + 1] == 'L') break;
        ++x; --y;
    }
    x = cx; y = cy;

    while (x < seating_chart.front().size()) // East
    {
        if (seating_chart[y][x + 1] == '#')
        {
            ++visible_occupied_seats;
            break;
        }
        if (seating_chart[y][x + 1] == 'L') break;
        ++x;
    }
    x = cx; y = cy;

    while (x < seating_chart.front().size() && y < seating_chart.size() - 1) // Southeast
    {
        if (seating_chart[y + 1][x + 1] == '#')
        {
            ++visible_occupied_seats;
            break;
        }
        if (seating_chart[y + 1][x + 1] == 'L') break;
        ++x; ++y;
    }
    x = cx; y = cy;

    while (y < seating_chart.size() - 1) // South
    {
        if (seating_chart[y + 1][x] == '#')
        {
            ++visible_occupied_seats;
            break;
        }
        if (seating_chart[y + 1][x] == 'L') break;
        ++y;
    }
    x = cx; y = cy;

    while (x > 0 && y < seating_chart.size() - 1) // Southwest
    {
        if (seating_chart[y + 1][x - 1] == '#')
        {
            ++visible_occupied_seats;
            break;
        }
        if (seating_chart[y + 1][x - 1] == 'L') break;
        --x; ++y;
    }
    x = cx; y = cy;

    while (x > 0) // West
    {
        if (seating_chart[y][x - 1] == '#')
        {
            ++visible_occupied_seats;
            break;
        }
        if (seating_chart[y][x - 1] == 'L') break;
        --x;
    }

    return visible_occupied_seats >= 5 ? true : false;
}

std::tuple<seating_chart, bool> process_seating_chart(bool part1, const seating_chart& original_seating_chart)
{
    // Choose func1 and func2 depending on if part1 or part2 of the problem is being computed
    std::function<bool(const seating_chart&, const size_t, const size_t)> func1;
    func1 = part1 ? has_adjacent_occupied_seats : can_see_occupied_seat;
    std::function<bool(const seating_chart&, const size_t, const size_t)> func2;
    func2 = part1 ? has_four_plus_adjacent_occupied_seats : can_see_five_plus_occupied_seats;

    bool seating_chart_changed{ false };
    seating_chart new_seating_chart;
    for (size_t y{ 0 }; y < original_seating_chart.size(); ++y)
    {
        std::stringstream ss;
        for (size_t x{ 0 }; x < original_seating_chart.front().size(); ++x)
        {
            switch (original_seating_chart[y][x])
            {
            case '.':
                ss << '.';
                break;
            case 'L':
                if (!func1(original_seating_chart, x, y))
                {
                    seating_chart_changed = true;
                    ss << '#';
                }
                else
                {
                    ss << 'L';
                }
                break;
            case '#':
                if (func2(original_seating_chart, x, y))
                {
                    seating_chart_changed = true;
                    ss << 'L';
                }
                else
                {
                    ss << '#';
                }
                break;

            default:
                throw std::runtime_error("Bad seating chart");
            }
        }
        new_seating_chart.emplace_back(ss.str());
    }
    return { new_seating_chart, seating_chart_changed };
}

int count_occupied_seats(const seating_chart& seating_chart)
{
    int occupied_seats{ 0 };
    for (const auto row : seating_chart)
    {
        for (const auto seat : row)
        {
            if (seat == '#') ++occupied_seats;
        }
    }
    return occupied_seats;
}

int part1_and_2(bool part1, seating_chart& seating_chart)
{
    bool changed{ false };
    do {
        auto [new_seating_chart, seating_chart_changed] = process_seating_chart(part1, seating_chart);
        seating_chart = new_seating_chart;
        changed = seating_chart_changed;
    } while (changed);
    return count_occupied_seats(seating_chart);
}

#include <fstream>
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

bool has_adjacent_unoccupied_seats(const seating_chart& seating_chart, size_t x, size_t y)
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

bool has_four_adjacent_occupied_seats(const seating_chart& seating_chart, size_t x, size_t y)
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

std::tuple<seating_chart, bool> process_seating_chart(const seating_chart& original_seating_chart)
{
    struct return_values { seating_chart new_seating_chart; bool seating_chart_changed; };
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
                // "If a seat is empty (L) and there are no occupied seats adjacent
                // to it, the seat becomes occupied."
                if (!has_adjacent_unoccupied_seats(original_seating_chart, x, y))
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
                // "If a seat is occupied (#) and four or more seats adjacent to it
                // are also occupied, the seat becomes empty."
                if (has_four_adjacent_occupied_seats(original_seating_chart, x, y))
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

int part1(seating_chart& seating_chart)
{
    bool changed{ false };
    do {
        auto [new_seating_chart, seating_chart_changed] = process_seating_chart(seating_chart);
        seating_chart = new_seating_chart;
        changed = seating_chart_changed;
    } while (changed);
    return count_occupied_seats(seating_chart);
}

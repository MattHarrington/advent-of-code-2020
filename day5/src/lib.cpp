#include <algorithm>
#include <fstream>
#include <stdexcept>

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

std::pair<int, int> get_seat(const std::string& seat)
{
    std::pair<int, int> row{ 0,127 };
    std::pair<int, int> column{ 0,7 };

    for (const auto& c : seat)
    {
        switch (c)
        {
        case 'F':
            row.second -= (row.second - row.first + 1) / 2;
            break;
        case 'B':
            row.first += (row.second - row.first + 1) / 2;
            break;
        case 'L':
            column.second -= (column.second - column.first + 1) / 2;
            break;
        case 'R':
            column.first += (column.second - column.first + 1) / 2;
            break;
        default:
            throw std::runtime_error("Bad seat");
        }
    }
    return std::make_pair(row.first, column.first);
}

int get_seat_id(const std::pair<int, int>& seat)
{
    return seat.first * 8 + seat.second;
}

std::vector<int> get_seat_ids(const std::vector<std::string>& encoded_seats)
{
    std::vector<int> seat_ids;
    seat_ids.reserve(encoded_seats.size());
    for (const auto& encoded_seat : encoded_seats)
    {
        const auto seat{ get_seat(encoded_seat) };
        const auto seat_id{ get_seat_id(seat) };
        seat_ids.push_back(seat_id);
    }
    return seat_ids;
}

int get_max_seat_id(const std::vector<int>& seat_ids)
{
    return *std::max_element(seat_ids.begin(), seat_ids.end());
}

int get_missing_seat_id(std::vector<int>& seat_ids)
{
    std::sort(seat_ids.begin(), seat_ids.end());
    for (auto it{ seat_ids.begin() }; it != seat_ids.end(); ++it)
    {
        if (*it + 1 != *std::next(it))
        {
            return *it + 1;
        }
    }
    return -1; // Seat not found
}

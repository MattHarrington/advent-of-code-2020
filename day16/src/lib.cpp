#include <fstream>
#include <regex>
#include <numeric>
#include <stdexcept>
#include <sstream>

#include "lib.hpp"

std::tuple<std::vector<TicketRule>, Ticket, std::vector<Ticket>> read_input(const std::string& filename)
{
    std::fstream in{ filename };
    if (!in.is_open()) throw std::runtime_error("Could not open file");

    std::string line;

    // Process ticket rules
    std::vector<TicketRule> ticket_rules;
    std::regex rule_regex{ R"(([a-z ]+): (\d+)-(\d+) or (\d+)-(\d+))" };
    while (getline(in, line))
    {
        std::smatch sm;
        if (!std::regex_match(line, sm, rule_regex)) break;
        TicketRule rule{ sm[1], std::stoi(sm[2]), std::stoi(sm[3]), std::stoi(sm[4]), std::stoi(sm[5]) };
        ticket_rules.emplace_back(rule);
    }

    // Skip lines
    getline(in, line);
    getline(in, line);

    // Process my ticket
    Ticket my_ticket;
    std::regex ticket_regex{ R"((\d+))" };
    auto my_ticket_search_start(line.cbegin());
    std::smatch my_ticket_sm;
    while (std::regex_search(my_ticket_search_start, line.cend(), my_ticket_sm, ticket_regex))
    {
        my_ticket.fields.emplace_back(std::stoi(my_ticket_sm[1]));
        my_ticket_search_start = my_ticket_sm.suffix().first;
    }

    // Skip lines
    getline(in, line);
    getline(in, line);

    // Process nearby tickets
    std::vector<Ticket> nearby_tickets;
    while (getline(in, line))
    {
        Ticket nearby_ticket;

        auto search_start(line.cbegin());
        std::smatch sm;

        while (std::regex_search(search_start, line.cend(), sm, ticket_regex))
        {
            nearby_ticket.fields.emplace_back(std::stoi(sm[1]));
            search_start = sm.suffix().first;
        }
        nearby_tickets.emplace_back(nearby_ticket);
    }

    return std::make_tuple(ticket_rules, my_ticket, nearby_tickets);
}

// Checks if a field is valid for any of the rules
bool field_is_valid_for_any_rule(int field, const std::vector<TicketRule>& rules)
{
    for (const auto& rule : rules)
    {
        if ((field >= rule.first_seat_left && field <= rule.last_seat_left)
            || (field >= rule.first_seat_right && field <= rule.last_seat_right))
        {
            // Field is valid
            return true;
        }
    }
    return false;
}

// Checks if all fields are valid for a given rule
bool fields_are_valid_for_rule(Eigen::VectorXi fields, const TicketRule& rule)
{
    for (auto i{ 0 }; i < fields.size(); ++i)
    {
        if (!((fields[i] >= rule.first_seat_left && fields[i] <= rule.last_seat_left)
            || (fields[i] >= rule.first_seat_right && fields[i] <= rule.last_seat_right)))
        {
            // Field is invalid
            return false;
        }
    }
    return true;
}

int part1(const std::string& filename)
{
    std::vector<int> invalid_fields;
    const auto [rules, ticket, nearby_tickets] = read_input(filename);
    for (const auto& nearby_ticket : nearby_tickets)
    {
        for (const auto field : nearby_ticket.fields)
        {
            if (!field_is_valid_for_any_rule(field, rules))
            {
                // Field is invalid, so remember it
                invalid_fields.push_back(field);
            }
        }
    }
    // Return sum of invalid fields, per problem statement
    return std::accumulate(invalid_fields.cbegin(), invalid_fields.cend(), 0);
}

// Construct a matrix whose coeffecients are ticket fields
Eigen::MatrixXi get_ticket_matrix(const std::vector<Ticket>& tickets)
{
    Eigen::MatrixXi ticket_matrix(tickets.size(), tickets.front().fields.size());
    for (auto row{ 0 }; row < tickets.size(); ++row)
    {
        for (auto column{ 0 }; column < tickets.front().fields.size(); ++column)
        {
            ticket_matrix(row, column) = tickets[row].fields[column];
        }
    }
    return ticket_matrix;
}

bool ticket_is_valid(const std::vector<TicketRule>& rules, Ticket ticket)
{
    return std::all_of(ticket.fields.cbegin(), ticket.fields.cend(),
        [&rules](int f) {return field_is_valid_for_any_rule(f, rules); });
}

// Remove tickets with invalid fields
std::vector<Ticket> remove_invalid_tickets(const std::vector<TicketRule>& rules, std::vector<Ticket> tickets)
{
    auto ticket_it{ tickets.begin() };

    while (ticket_it != tickets.end())
    {
        if (ticket_is_valid(rules, *ticket_it))
        {
            ++ticket_it;
        }
        else
        {
            // Invalid ticket
            ticket_it = tickets.erase(ticket_it);
        }
    }
    return tickets;
}

long long part2(const std::vector<TicketRule>& ticket_rules, const Ticket& my_ticket, std::vector<Ticket> nearby_tickets)
{
    // Remove invalid tickets, per problem statement
    nearby_tickets = remove_invalid_tickets(ticket_rules, nearby_tickets);

    // Create a matrix of ticket fields. Not strictly required, but
    // it's easier to extract a column from a matrix than from other
    // data structures.
    Eigen::MatrixXi nearby_tickets_matrix{ get_ticket_matrix(nearby_tickets) };

    // Discover which rules could apply to a given column
    std::vector<std::vector<std::string>> possible_rules_per_column;
    for (auto i{ 0 }; i < nearby_tickets_matrix.cols(); ++i)
    {
        std::vector<std::string> possible_rules;
        for (const auto& rule : ticket_rules)
        {
            if (fields_are_valid_for_rule(nearby_tickets_matrix.col(i), rule))
            {
                possible_rules.emplace_back(rule.name);
            }
        }
        possible_rules_per_column.emplace_back(possible_rules);
    }

    // Scan through possible_rules_per_column. Search for element with size 1.
    // Save that rule in a vector at the correct position. That rule can only
    // correspond to that column.
    // Remove that rule from all elements.
    // Repeat until no possible rules are of size 1.
    std::vector<std::string> column_headers(ticket_rules.size());
    auto single_rule_it{ std::find_if(possible_rules_per_column.cbegin(), possible_rules_per_column.cend(),
        [](auto v) {return v.size() == 1; }) };
    while (single_rule_it != possible_rules_per_column.end())
    {
        auto pos{ single_rule_it - possible_rules_per_column.cbegin() };
        auto column_header{ single_rule_it->front() };
        column_headers.at(pos) = column_header;
        for (auto& possible_rules : possible_rules_per_column)
        {
            possible_rules.erase(std::remove(possible_rules.begin(), possible_rules.end(), column_header),
                possible_rules.end());
        }
        single_rule_it = std::find_if(possible_rules_per_column.cbegin(), possible_rules_per_column.cend(),
            [](auto v) {return v.size() == 1; });
    }

    // Find columns beginning with "departure". Multiply corresponding values on my_ticket to obtain part2_answer.
    std::vector<std::string> departure_headings{ "departure location", "departure station", "departure platform",
                                                 "departure track", "departure date", "departure time" };
    auto part2_answer{ 1LL };
    for (auto i{ 0 }; i < column_headers.size(); ++i)
    {
        if (std::count(departure_headings.cbegin(), departure_headings.cend(), column_headers.at(i)))
        {
            part2_answer *= my_ticket.fields.at(i);
        }
    }

    return part2_answer;
}

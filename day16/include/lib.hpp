#pragma once

#include <Eigen/Dense>
#include <string>
#include <tuple>
#include <vector>

struct TicketRule
{
	std::string name;
	int first_seat_left;
	int last_seat_left;
	int first_seat_right;
	int last_seat_right;
};

struct Ticket
{
	std::vector<int> fields;
};

std::tuple<std::vector<TicketRule>, Ticket, std::vector<Ticket>> read_input(const std::string&);

int part1(const std::string&);

Eigen::MatrixXi get_ticket_matrix(const std::vector<Ticket>&);

long long part2(const std::vector<TicketRule>&, const Ticket&, std::vector<Ticket>);

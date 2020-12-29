#pragma once

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Graph
{
public:
    explicit Graph(const std::vector<std::string>&);
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> adjacency_list;
};

std::vector<std::string> read_input(const std::string&);

int part1(const Graph&);

int part2(const Graph&);

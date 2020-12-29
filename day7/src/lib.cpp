#include <fstream>
#include <regex>
#include <queue>
#include <stdexcept>

#include "lib.hpp"

Graph::Graph(const std::vector<std::string>& input)
{
    std::regex r1{ R"(([a-z ]+) bags contain )" };
    std::regex r2{ R"(([\d]+) ([a-z ]+) bag)" };

    for (const auto& line : input)
    {
        auto search_start(line.cbegin());
        std::smatch sm_key;
        std::smatch sm;

        std::regex_search(search_start, line.cend(), sm_key, r1);
        std::string key{ sm_key[1] };
        search_start = sm_key.suffix().first;

        std::vector<std::pair<int, std::string>> list;
        while (std::regex_search(search_start, line.cend(), sm, r2))
        {
            list.emplace_back(std::make_pair(std::stoi(sm[1]), sm[2]));
            search_start = sm.suffix().first;
        }
        adjacency_list[key] = list;
    }
}

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

int part1(const Graph& graph)
{
    // BFS
    int contain_shiny_gold{ 0 };

    for (const auto& [key, value] : graph.adjacency_list)
    {
        std::unordered_map<std::string, bool> visited;
        std::queue<std::pair<int, std::string>> q;
        for (const auto& vertex : value)
        {
            q.emplace(vertex);
        }

        while (!q.empty())
        {
            const auto [bag_quantity, bag_name] { q.front() };
            q.pop();
            if (visited[bag_name]) continue;
            if (bag_name == "shiny gold")
            {
                ++contain_shiny_gold;
                break;
            }
            else
            {
                visited[bag_name] = true;
                for (const auto& next_bag : graph.adjacency_list.at(bag_name))
                {
                    q.emplace(next_bag);
                }
            }
        }

    }
    return contain_shiny_gold;
}

int part2(const Graph& graph)
{
    int contained_bags{ 0 };
    std::queue<std::pair<int, std::string>> q;
    for (const auto& vertex : graph.adjacency_list.at("shiny gold"))
    {
        q.emplace(vertex);
    }

    while (!q.empty())
    {
        const auto [bag_quantity, bag_name] { q.front() };
        q.pop();
        contained_bags += bag_quantity;
        for (const auto& [next_bag_quantity, next_bag_name] : graph.adjacency_list.at(bag_name))
        {
            q.emplace(std::make_pair(bag_quantity * next_bag_quantity, next_bag_name));
        }
    }

    return contained_bags;
}

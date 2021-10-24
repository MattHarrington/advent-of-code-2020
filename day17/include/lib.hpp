#pragma once

#include <boost/container_hash/hash.hpp>
#include <string>
#include <vector>

struct Point3D
{
    int x;
    int y;
    int z;
};

inline size_t hash_value(Point3D const& p) {
    size_t seed = 0;
    boost::hash_combine(seed, p.x);
    boost::hash_combine(seed, p.y);
    boost::hash_combine(seed, p.z);
    return seed;
}

inline bool operator==(const Point3D& lhs, const Point3D& rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

std::vector<std::string> read_input(const std::string&);

std::vector<Point3D> process_input(const std::vector<std::string>&);

int part1(const std::vector<std::string>&);

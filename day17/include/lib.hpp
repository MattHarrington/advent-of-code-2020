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

struct Point4D
{
    int x;
    int y;
    int z;
    int w;
};

inline size_t hash_value(Point4D const& p) {
    size_t seed = 0;
    boost::hash_combine(seed, p.x);
    boost::hash_combine(seed, p.y);
    boost::hash_combine(seed, p.z);
    boost::hash_combine(seed, p.w);
    return seed;
}

inline bool operator==(const Point4D& lhs, const Point4D& rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
}

std::vector<std::string> read_input(const std::string&);

std::vector<Point3D> process_input_3D(const std::vector<std::string>&);

std::vector<Point4D> process_input_4D(const std::vector<std::string>&);

int part1(const std::vector<std::string>&);

int part2(const std::vector<std::string>&);

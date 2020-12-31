#pragma once

#include <string>
#include <vector>

enum class opcode
{
    acc, jmp, nop
};

struct instruction
{
    opcode operation;
    int argument;
};

std::vector<std::string> read_input(const std::string&);

std::vector<instruction> process_input(const std::vector<std::string>&);

int part1(const std::vector<instruction>&);

int part2(std::vector<instruction>);

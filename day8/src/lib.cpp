#include <fstream>
#include <regex>
#include <stdexcept>
#include <sstream>

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

std::vector<instruction> process_input(const std::vector<std::string>& input)
{
    std::vector<instruction> instructions;
    const std::regex r{ R"((nop|acc|jmp) ([\+\-\d]+))" };

    for (const auto& line : input)
    {
        std::smatch sm;
        std::regex_match(line, sm, r);
        if (sm[1] == "nop") instructions.emplace_back(instruction{ opcode::nop, std::stoi(sm[2]) });
        else if (sm[1] == "acc") instructions.emplace_back(instruction{ opcode::acc, std::stoi(sm[2]) });
        else if (sm[1] == "jmp") instructions.emplace_back(instruction{ opcode::jmp, std::stoi(sm[2]) });
    }
    return instructions;
}

int part1(const std::vector<instruction>& boot_code)
{
    int accumulator{ 0 };
    size_t ip{ 0 }; // Instruction pointer
    std::vector<bool> visited(boot_code.size());
    while (!visited.at(ip))
    {
        visited.at(ip) = true;
        if (boot_code.at(ip).operation == opcode::nop) ++ip;
        else if (boot_code.at(ip).operation == opcode::acc) {
            accumulator += boot_code.at(ip).argument;
            ++ip;
        }
        else if (boot_code.at(ip).operation == opcode::jmp) ip += boot_code.at(ip).argument;
    }
    return accumulator;
}

int part2(std::vector<instruction> boot_code)
{
    for (size_t i{ 0 }; i < boot_code.size(); ++i) {
        // Change nop to jmp and vice versa, per problem statement
        if (boot_code.at(i).operation == opcode::nop) boot_code.at(i).operation = opcode::jmp;
        else if (boot_code.at(i).operation == opcode::jmp) boot_code.at(i).operation = opcode::nop;

        int accumulator{ 0 };
        size_t ip{ 0 }; // Instruction pointer
        std::vector<bool> visited(boot_code.size());
        while (!visited.at(ip))
        {
            visited.at(ip) = true;
            if (boot_code.at(ip).operation == opcode::nop) ++ip;
            else if (boot_code.at(ip).operation == opcode::acc) {
                accumulator += boot_code.at(ip).argument;
                ++ip;
            }
            else if (boot_code.at(ip).operation == opcode::jmp) ip += boot_code.at(ip).argument;
            if (ip == boot_code.size()) return accumulator; // "Boot code" terminates when ip is one past the last instruction
        }

        // Revert changes, per problem statement
        if (boot_code.at(i).operation == opcode::nop) boot_code.at(i).operation = opcode::jmp;
        else if (boot_code.at(i).operation == opcode::jmp) boot_code.at(i).operation = opcode::nop;
    }
    return -1; // Failure.  Even when modifying instructions, "boot code" does not terminate.
}

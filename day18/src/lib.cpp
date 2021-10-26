#include <fstream>
#include <numeric>
#include <sstream>
#include <stdexcept>

#include "lib.hpp"

std::vector<std::queue<Token>> read_input(const std::string& filename)
{
    std::vector<std::queue<Token>> problems;
    std::fstream in{ filename };
    if (!in.is_open()) throw std::runtime_error("Could not open file");

    std::string line;

    while (getline(in, line))
    {
        std::queue<Token> problem;
        for (const char c : line)
        {
            switch (c)
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                problem.push(static_cast<Token>(c - '0')); // Casts '1' to Token::one, etc.
                break;
            case '+':
                problem.push(Token::plus);
                break;
            case '*':
                problem.push(Token::times);
                break;
            case '(':
                problem.push(Token::left_parens);
                break;
            case ')':
                problem.push(Token::right_parens);
                break;
            case ' ':
                break;
            default:
                throw std::runtime_error("Bad token");
            }
        }
        problems.emplace_back(problem);
    }
    return problems;
}

long long process_queue(std::queue<Token>& problem, const Part& part)
{
    auto accumulator{ 0LL };

    // Handle start of queue
    if (problem.front() == Token::left_parens)
    {
        problem.pop();
        accumulator = process_queue(problem, part);
    }
    else
    {
        accumulator = static_cast<long long>(problem.front());
        problem.pop();
    }

    Token previous_token{ Token::none }; // At start of expression, there is no previous token

    // Process rest of queue
    while (!problem.empty())
    {
        Token token{ problem.front() };
        problem.pop();
        switch (token)
        {
        case Token::plus:
            previous_token = Token::plus;
            break;
        case Token::times:
            previous_token = Token::times;
            if (part == Part::two)
            {
                // Multiplication has lower precedence than addition in part 2
                token = static_cast<Token>(process_queue(problem, part)); // A little tricky since token can now be greater than Token enum values
                accumulator *= static_cast<long long>(token);
                return accumulator;
            }
            break;
        case Token::left_parens:
            token = static_cast<Token>(process_queue(problem, part)); // A little tricky since token can now be greater than Token enum values
            [[fallthrough]];
        case Token::one:
        case Token::two:
        case Token::three:
        case Token::four:
        case Token::five:
        case Token::six:
        case Token::seven:
        case Token::eight:
        case Token::nine:
            if (previous_token == Token::plus)
            {
                accumulator += static_cast<long long>(token);
            }
            else if (previous_token == Token::times)
            {
                accumulator *= static_cast<long long>(token);
            }
            break;
        case Token::right_parens:
            return accumulator;
        default:
            throw std::runtime_error("Bad token");
        }
    }
    return accumulator;
}

long long solve_part(std::vector<std::queue <Token>> problems, const Part& part)
{
    std::vector<long long> results;
    for (auto problem : problems)
    {
        results.push_back(process_queue(problem, part));
    }
    return std::accumulate(results.cbegin(), results.cend(), 0LL);
}

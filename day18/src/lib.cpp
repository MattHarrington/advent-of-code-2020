#include <fstream>
#include <numeric>
#include <sstream>
#include <stdexcept>

#include "lib.hpp"

std::vector<std::queue<Token>> read_input(const std::string& filename)
{
    std::vector<std::queue<Token>> output;
    std::fstream in{ filename };
    if (!in.is_open()) throw std::runtime_error("Could not open file");

    std::string line;

    while (getline(in, line))
    {
        std::queue<Token> q;
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
                q.push(static_cast<Token>(c - '0')); // Casts '1' to Token::one, etc.
                break;
            case '+':
                q.push(Token::plus);
                break;
            case '*':
                q.push(Token::times);
                break;
            case '(':
                q.push(Token::left_parens);
                break;
            case ')':
                q.push(Token::right_parens);
                break;
            case ' ':
                break;
            default:
                throw std::runtime_error("Bad token");
            }
        }
        output.emplace_back(q);
    }
    return output;
}

long long process_queue(std::queue<Token>& q)
{
    auto acc{ 0LL };
    if (q.front() == Token::left_parens)
    {
        q.pop();
        acc = process_queue(q);
    }
    else
    {
        acc = static_cast<long long>(q.front());
        q.pop();
    }

    Token previous_token{ Token::none }; // At start of expression, there is no previous token

    while (!q.empty())
    {
        Token token{ q.front() };
        q.pop();
        switch (token)
        {
        case Token::plus:
            previous_token = Token::plus;
            break;
        case Token::times:
            previous_token = Token::times;
            break;
        case Token::left_parens:
            token = static_cast<Token>(process_queue(q));
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
                acc += static_cast<long long>(token);
            }
            else if (previous_token == Token::times)
            {
                acc *= static_cast<long long>(token);
            }
            break;
        case Token::right_parens:
            return acc;
            break;
        default:
            throw std::runtime_error("Bad token");
        }
    }
    return acc;
}

long long part1(std::vector<std::queue <Token>> input)
{
    std::vector<long long> results;
    for (auto expression : input)
    {
        results.push_back(process_queue(expression));
    }
    return std::accumulate(results.cbegin(), results.cend(), 0LL);
}

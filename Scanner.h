#ifndef SCANNER_H_
#define SCANNER_H_

#include "Token.h"

#include <cctype>

class Scanner
{
public:
    Scanner(const std::string &input)
    : input(input) {}

    Token scanToken()
    {
        TokenType type;
        std::string value;
        int line = 1;

        while(std::isspace(input.at(0)))
        {
            if(input.at(0) == '\n')
            {
                line++;
            }
            input = input.substr(1);
        }
        if(input.at(0) == ',')
        {
            type = COMMA;
            value = ",";
            input = input.substr(1);
        }

        return Token(type, value, line);
    }

private:
    std::string input;
};

#endif
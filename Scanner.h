#ifndef SCANNER_H_
#define SCANNER_H_

#include "Token.h"

#include <cctype>
#include <vector>
#include <iostream>

class Scanner
{
public:
    Scanner(const std::string &input)
    : input(input)
    {
        scanTokens();
    }

    std::string toString() const
    {
        std::string result = "";

        for(int i = 0; i < tokens.size(); i++)
        {
            result += tokens.at(i)->toString();
        }

        return result;
    }

    void scanTokens()
    {
        int line = 1;

        while(!input.empty())
        {
            while(!input.empty() && std::isspace(input.at(0)))
            {
                if(input.at(0) == '\n')
                {
                    line++;
                }
                if(input.size() > 1)
                {
                    input = input.substr(1);
                }
                else
                {
                    input = "";
                }
            }
            if(!input.empty())
            {
                Token* newToken = new Token();

                if(input.at(0) == ',')
                {
                    newToken->setType(COMMA);
                    newToken->setValue(",");
                    newToken->setLine(line);
                    if(input.size() > 1)
                    {
                        input = input.substr(1);
                    }
                    else
                    {
                        input = "";
                    }
                }
                else
                {
                    newToken->setType(UNDEFINED);
                    newToken->setValue("?");
                    newToken->setLine(line);

                    if(input.size() > 1)
                    {
                        input = input.substr(1);
                    }
                    else
                    {
                        input = "";
                    }
                }

                tokens.push_back(newToken);
            }
        }
    }

private:
    std::string input;
    std::vector<Token*> tokens;
};

#endif
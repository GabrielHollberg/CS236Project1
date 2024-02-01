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
                else if(input.at(0) == '.')
                {
                    newToken->setType(PERIOD);
                    newToken->setValue(".");
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
                else if(input.at(0) == '?')
                {
                    newToken->setType(Q_MARK);
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
                else if(input.at(0) == '(')
                {
                    newToken->setType(LEFT_PAREN);
                    newToken->setValue("(");
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
                else if(input.at(0) == ')')
                {
                    newToken->setType(RIGHT_PAREN);
                    newToken->setValue(")");
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
                else if(input.substr(0, 2) == ":-")
                {
                    newToken->setType(COLON_DASH);
                    newToken->setValue(":-");
                    newToken->setLine(line);
                    if(input.size() > 1)
                    {
                        input = input.substr(2);
                    }
                    else
                    {
                        input = "";
                    }
                }
                else if(input.at(0) == ':')
                {
                    newToken->setType(COLON);
                    newToken->setValue(":");
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
                else if(input.at(0) == '*')
                {
                    newToken->setType(MULTIPLY);
                    newToken->setValue("*");
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
                else if(input.at(0) == '+')
                {
                    newToken->setType(ADD);
                    newToken->setValue("+");
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
                else if(input.substr(0, 7) == "Schemes")
                {
                    newToken->setType(SCHEMES);
                    newToken->setValue("Schemes");
                    newToken->setLine(line);
                    if(input.size() > 1)
                    {
                        input = input.substr(7);
                    }
                    else
                    {
                        input = "";
                    }
                }
                else if(input.substr(0, 5) == "Facts")
                {
                    newToken->setType(FACTS);
                    newToken->setValue("Facts");
                    newToken->setLine(line);
                    if(input.size() > 1)
                    {
                        input = input.substr(5);
                    }
                    else
                    {
                        input = "";
                    }
                }
                else if(input.substr(0, 5) == "Rules")
                {
                    newToken->setType(RULES);
                    newToken->setValue("Rules");
                    newToken->setLine(line);
                    if(input.size() > 1)
                    {
                        input = input.substr(5);
                    }
                    else
                    {
                        input = "";
                    }
                }
                else if(input.substr(0, 7) == "Queries")
                {
                    newToken->setType(QUERIES);
                    newToken->setValue("Queries");
                    newToken->setLine(line);
                    if(input.size() > 1)
                    {
                        input = input.substr(7);
                    }
                    else
                    {
                        input = "";
                    }
                }
                else
                {
                    newToken->setType(UNDEFINED);
                    newToken->setValue(" ");
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
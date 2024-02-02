#ifndef SCANNER_H_
#define SCANNER_H_

#include "Token.h"

#include <cctype>
#include <vector>
#include <iostream>

class Scanner
{
public:
    Scanner(const std::string& input)
        : input(input)
    {
        scanTokens();
    }

    std::string toString() const
    {
        std::string result = "";

        for (int i = 0; i < tokens.size(); i++)
        {
            result += tokens.at(i)->toString();
        }

        return result;
    }

    void scanTokens()
    {
        int line = 1;

        //scan string and add tokens
        while (!input.empty())
        {
            Token* newToken = new Token();

            //skip whitespace
            while (!input.empty() && std::isspace(input.at(0)))
            {
                if (input.at(0) == '\n')
                {
                    line++;
                }
                if (input.size() > 1)
                {
                    input = input.substr(1);
                }
                else
                {
                    input = "";
                }
            }

            //detect token type
            if (!input.empty())
            {
                if (input.at(0) == ',')
                {
                    if (input.size() > 1)
                    {
                        input = input.substr(1);
                    }
                    else
                    {
                        input = "";
                    }
                    newToken->setType(COMMA);
                    newToken->setValue(",");
                    newToken->setLine(line);
                }
                else if (input.at(0) == '.')
                {
                    if (input.size() > 1)
                    {
                        input = input.substr(1);
                    }
                    else
                    {
                        input = "";
                    }
                    newToken->setType(PERIOD);
                    newToken->setValue(".");
                    newToken->setLine(line);
                }
                else if (input.at(0) == '?')
                {
                    if (input.size() > 1)
                    {
                        input = input.substr(1);
                    }
                    else
                    {
                        input = "";
                    }
                    newToken->setType(Q_MARK);
                    newToken->setValue("?");
                    newToken->setLine(line);
                }
                else if (input.at(0) == '(')
                {
                    if (input.size() > 1)
                    {
                        input = input.substr(1);
                    }
                    else
                    {
                        input = "";
                    }
                    newToken->setType(LEFT_PAREN);
                    newToken->setValue("(");
                    newToken->setLine(line);
                }
                else if (input.at(0) == ')')
                {
                    if (input.size() > 1)
                    {
                        input = input.substr(1);
                    }
                    else
                    {
                        input = "";
                    }
                    newToken->setType(RIGHT_PAREN);
                    newToken->setValue(")");
                    newToken->setLine(line);
                }
                else if (input.substr(0, 2) == ":-")
                {
                    if (input.size() > 1)
                    {
                        input = input.substr(2);
                    }
                    else
                    {
                        input = "";
                    }
                    newToken->setType(COLON_DASH);
                    newToken->setValue(":-");
                    newToken->setLine(line);
                }
                else if (input.at(0) == ':')
                {
                    if (input.size() > 1)
                    {
                        input = input.substr(1);
                    }
                    else
                    {
                        input = "";
                    }
                    newToken->setType(COLON);
                    newToken->setValue(":");
                    newToken->setLine(line);
                }
                else if (input.at(0) == '*')
                {
                    if (input.size() > 1)
                    {
                        input = input.substr(1);
                    }
                    else
                    {
                        input = "";
                    }
                    newToken->setType(MULTIPLY);
                    newToken->setValue("*");
                    newToken->setLine(line);
                }
                else if (input.at(0) == '+')
                {
                    if (input.size() > 1)
                    {
                        input = input.substr(1);
                    }
                    else
                    {
                        input = "";
                    }
                    newToken->setType(ADD);
                    newToken->setValue("+");
                    newToken->setLine(line);
                }
                else if (input.substr(0, 7) == "Schemes")
                {
                    if (input.size() > 1)
                    {
                        input = input.substr(7);
                    }
                    else
                    {
                        input = "";
                    }
                    newToken->setType(SCHEMES);
                    newToken->setValue("Schemes");
                    newToken->setLine(line);
                }
                else if (input.substr(0, 5) == "Facts")
                {
                    if (input.size() > 1)
                    {
                        input = input.substr(5);
                    }
                    else
                    {
                        input = "";
                    }
                    newToken->setType(FACTS);
                    newToken->setValue("Facts");
                    newToken->setLine(line);
                }
                else if (input.substr(0, 5) == "Rules")
                {
                    if (input.size() > 1)
                    {
                        input = input.substr(5);
                    }
                    else
                    {
                        input = "";
                    }
                    newToken->setType(RULES);
                    newToken->setValue("Rules");
                    newToken->setLine(line);
                }
                else if (input.substr(0, 7) == "Queries")
                {
                    if (input.size() > 1)
                    {
                        input = input.substr(7);
                    }
                    else
                    {
                        input = "";
                    }
                    newToken->setType(QUERIES);
                    newToken->setValue("Queries");
                    newToken->setLine(line);
                }
                else if (std::isalpha(input.at(0)))
                {
                    std::string value = "";

                    while (input.size() > 0 && (std::isalpha(input.at(0)) || std::isdigit(input.at(0))))
                    {
                        value += input.at(0);

                        if (input.size() > 1)
                        {
                            input = input.substr(1);
                        }
                        else
                        {
                            input = "";
                        }
                    }
                    newToken->setType(ID);
                    newToken->setValue(value);
                    newToken->setLine(line);
                }
                else if (input.at(0) == '\'')
                {
                    std::string value = "\'";
                    newToken->setLine(line);

                    if (input.size() > 1)
                    {
                        input = input.substr(1);
                    }
                    else
                    {
                        input = "";
                    }

                    while (input.size() > 0)
                    {
                        if (input.at(0) == '\n')
                        {
                            value += " ";
                            line += 1;

                            if (input.size() > 1)
                            {
                                input = input.substr(1);
                            }
                            else
                            {
                                input = "";
                            }
                        }
                        else if (input.at(0) == '\'')
                        {
                            if (input.at(1) == '\'')
                            {
                                value += input.substr(0, 2);

                                if (input.size() > 2)
                                {
                                    input = input.substr(2);
                                }
                                else
                                {
                                    input = "";
                                }
                            }
                            else
                            {
                                value += input.at(0);

                                if (input.size() > 1)
                                {
                                    input = input.substr(1);
                                }
                                else
                                {
                                    input = "";
                                }

                                newToken->setType(STRING);
                                break;
                            }
                        }
                        else
                        {
                            value += input.substr(0, 1);

                            if (input.size() > 1)
                            {
                                input = input.substr(1);
                            }
                            else
                            {
                                input = "";

                                newToken->setType(UNDEFINED);
                            }
                        }
                    }
                    newToken->setValue(value);
                }
                else
                {
                    newToken->setType(UNDEFINED);
                    newToken->setValue(input.substr(0, 1));
                    newToken->setLine(line);

                    if (input.size() > 1)
                    {
                        input = input.substr(1);
                    }
                    else
                    {
                        input = "";
                    }
                }
            }
            tokens.push_back(newToken);
        }
        line -= 1;
        Token* token = new Token(END, "", line);
        tokens.push_back(token);
    }

private:
    std::string input;
    std::vector<Token*> tokens;
};

#endif
#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>
#include <sstream>
#include <iostream>

enum TokenType
{
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    COLON,
    COLON_DASH,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    END
};

class Token
{
public:
    Token()
    : type(UNDEFINED), value(""), line(0) {}
    Token(TokenType type, std::string value, int line)
    : type(type), value(value), line(line) {}
    ~Token() {}

    std::string typeName(TokenType type) const
    {
        std::string result = "";
        switch(type)
        {
            case COMMA:
                result = "COMMA";
                break;
            case PERIOD:
                result = "PERIOD";
                break;
            case Q_MARK:
                result = "Q_MARK";
                break;
            case LEFT_PAREN:
                result = "LEFT_PAREN";
                break;
            case RIGHT_PAREN:
                result = "RIGHT_PAREN";
                break;
            case COLON:
                result = "COLON";
                break;
            case COLON_DASH:
                result = "COLON_DASH";
                break;
            case MULTIPLY:
                result = "MULTIPLY";
                break;
            case ADD:
                result = "ADD";
                break;
            case SCHEMES:
                result = "SCHEMES";
                break;
            case FACTS:
                result = "FACTS";
                break;
            case RULES:
                result = "RULES";
                break;
            case QUERIES:
                result = "QUERIES";
                break;
            case ID:
                result = "ID";
                break;
            case STRING:
                result = "STRING";
                break;
            case COMMENT:
                result = "COMMENT";
                break;
            case UNDEFINED:
                result = "UNDEFINED";
                break;
            case END:
                result = "EOF";
                break;
        }
        return result;
    }

    void setType(TokenType type)
    {
        this->type = type;
    }

    void setValue(std::string value)
    {
        this->value = value;
    }

    void setLine(int line)
    {
        this->line = line;
    }

    std::string toString() const
    {
        std::stringstream out;
        out << "(" << typeName(type) << "," << "\"" << value << "\"" << "," << line << ")" << std::endl;
        return out.str();
    }

private:
    TokenType type;
    std::string value;
    int line;
};

#endif
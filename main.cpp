#include "Scanner.h"

#include <iostream>

int main()
{
    Scanner s = Scanner(" , , ");
    Token t = s.scanToken();
    std::cout << t.toString() << std::endl;

    return 0;
}
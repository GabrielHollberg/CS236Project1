#include "Scanner.h"

#include <iostream>
#include <fstream>
#include <sstream>


int main(int argc, char* argv[])
{
    std::stringstream ss;
    std::ifstream fileIn(argv[1]);
    std::string line;

    while (!fileIn.eof())
    {
        getline(fileIn, line);
        ss << line;
        ss << '\n';
    }

    fileIn.close();

    Scanner s = Scanner(ss.str());

    std::cout << s.toString();

    return 0;
}